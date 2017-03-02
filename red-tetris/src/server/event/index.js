import Game from '../controllers/Game.controller.js'
import Player from '../controllers/Player.controller.js'
import Piece from '../controllers/Piece.controller.js'
import _ from 'lodash'

export default (socket) => {
  socket.on('disconnect', (data) => disconnected(data, socket))

  socket.on('newPlayer', (data) => newPlayer(data, socket))

  socket.on('startGame', (data) => startGame(data, socket))

  socket.on('nextTurn', (data) => nextTurn(data, socket))

  socket.on('restartGame', (data) => restartGame(data, socket))

  socket.on('giveMalus', (data) => giveMalus(data, socket))

  socket.on('loseGame', (data) => loseGame(data, socket))

  socket.on('getGames',(data) => getGames(data,socket))

}

const getGames = async (data, socket) => {
  try {
    const allGame = await Game.getGames()
    socket.emit('action', {
      type: 'GET_GAMES',
      data: allGame,
    })
  } catch (e){
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const loseGame = async (data, socket) => {
  try {
    let isOver = false
    const updatedPlayer = await Player.updatePlayerById({ looser: true }, data.player_id)
    const game = await Game.getGameById(data.game_id)

    const standingPlayers = _.filter(game.players, player => !player.looser)
    if ((standingPlayers.length == 1 && game.players.length != 1) || standingPlayers.length == 0) {
      if (standingPlayers.length == 1) Player.updatePlayerById({ winner: true }, standingPlayers[0].id)
      isOver = true
    }

    const updatedGame = await Game.updateGameById({ isOver }, data.game_id)
    updatedGame.players.forEach((player) => {
      global.io.to(player.socketId).emit('action', {
        type: 'LOSE_GAME',
        data: updatedGame,
      })
    })
  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const addMalusToSpectre = (spectre, malus) => {
  return spectre.map(line => {
    let newline = line - malus
    if (newline < 0) newline = 0
    return newline
  })
}

const giveMalus = async (data, socket) => {
  try {
    const game = await Game.getGameById(data.game_id)
    const promises = []
    const goodPlayer = game.players.find(player => player.id == data.player_id)

    const otherPlayer = game.players.filter(player => player.id != data.player_id)
    otherPlayer.forEach(player => promises.push(Player.updatePlayerById({ spectre: addMalusToSpectre(player.spectre, data.malus) }, player.id)))
    await Promise.all(promises)
    const updatedGame = await Game.getGameById(data.game_id)
    updatedGame.players.forEach((player) => {
      global.io.to(player.socketId).emit('action', {
        type: 'GIVE_MALUS',
        data: { game: updatedGame, malus: (player.id == data.player_id) ? 0 : data.malus, message: (goodPlayer.id != player.id) ? `${goodPlayer.name} just gave you a malus...` : null },
      })
    })
  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const restartGame = async (data, socket) => {
  try {
    const newPiece1 = await Piece.createPiece()
    const newPiece2 = await Piece.createPiece()
    const updatedGame = await Game.updateGameById({ isOver: false, isStarted: false, pieces: [newPiece1.id, newPiece2.id] }, data.game_id)
    const promises = []
    updatedGame.players.forEach(player => promises.push(Player.updatePlayerById({ looser: false, winner: false, curPiece: 0, malus: 0, spectre: [21, 21, 21, 21, 21, 21, 21, 21, 21, 21] }, player.id)))
    await Promise.all(promises)
    const game = await Game.getGameById(data.game_id)

    game.players.forEach((player) => {
      global.io.to(player.socketId).emit('action', {
        type: 'RESTART_GAME',
        data: game,
      })
    })
  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const disconnected = async (data, socket) => {


  try {
    const playerInfo = await Player.getPlayerBySocket(socket.id)
    const updatedPlayer = await Player.updatePlayerById({ isDisconnected: true }, playerInfo.id)
    let isOver = false

    await Player.deletePlayerById(playerInfo.id)

    let game = await Game.getGameById(playerInfo.gameId)

    if (game.players.length != 0) {
      const standingPlayers = _.filter(game.players, player => !player.looser)
      if ((standingPlayers.length == 1 && game.players.length != 1) || standingPlayers.length == 0) {
        if (standingPlayers.length == 1) Player.updatePlayerById({ winner: true }, standingPlayers[0].id)
        isOver = true
      }
      await Player.updatePlayerById({ isVisitor: false }, game.players[0]._id)
      const updatedGame = await Game.updateGameById({ isOver }, game.id)

      game.players.forEach((player) => {
        global.io.to(player.socketId).emit('action', {
          type: 'DISCONNECTED',
          data: updatedGame,
          message: 'Player disconnected'
        })
      })
    } else Game.deleteGameById(game.id)
  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const newPlayer = async (data, socket) => {
  try {
    let game = await Game.getGameByName(data.room)
    let isVisitor = true

    if (!game) {
      game = await Game.createGame(data.room)
      isVisitor = false
    }
    if (game.players.length == 5) throw 'Too many players'

    if (_.find(game.players, player => player.name === data.name)) throw 'name already taken'

    if (game.isStarted) throw 'The game has already started'
    const playerCreated = await Player.createPlayer(data.name, isVisitor, socket.id, game.id)
    game = await Game.updateGameById({ players: game.players.concat(playerCreated.id)}, game.id)
    game.players.forEach((player) => {
      global.io.to(player.socketId).emit('action', {
        type: 'NEW_PLAYER',
        data: game,
        message: 'Player successfully created'
      })
    })
  }
  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const startGame = async (data, socket) => {
  try {
    const updatedGame = await Game.updateGameById({ isStarted: true }, data.game_id)
    updatedGame.players.forEach((player) => {
      global.io.to(player.socketId).emit('action', {
        type: 'START_GAME',
        data: updatedGame,
        message: 'Game successfully started'
      })
    })

  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}

const nextTurn = async (data, socket) => {

  try {
    const player = await Player.getPlayerById(data.player_id)
    const updatedPlayer = await Player.updatePlayerById({ spectre: data.spectre, curPiece: player.curPiece + 1 }, data.player_id)
    const game = await Game.getGameById(data.game_id)

    if (updatedPlayer.curPiece >= game.pieces.length - 1) {
      const piece = await Piece.createPiece()
      game.pieces.push(piece.id)
    }
    const updatedGame = await Game.updateGameById({ pieces: game.pieces }, game.id)
    updatedGame.players.forEach((playeur) => {
      global.io.to(playeur.socketId).emit('action', {
        type: 'NEXT_TURN',
        data: { updatedGame, name: player.name }
      })
    })
  }

  catch (e) {
    socket.emit('action', {
      type: 'ERROR',
      data: e,
    })
  }
}
