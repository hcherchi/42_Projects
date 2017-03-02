import filter from 'filter-object'
import Game from '../models/Game.model'
import Piece from './Piece.controller'
import Player from './Player.controller'

const permitted ='{room,isOver,isStarted,players,pieces}'

export default class GameController {

  /*
  while create a new Game
  */
  static async createGame(room) {

    try {
      let game = await new Game({ room }).save()
      const piece1 = await Piece.createPiece()
      const piece2 = await Piece.createPiece()
      const piece3 = await Piece.createPiece()
      const piece4 = await Piece.createPiece()
      const piece5 = await Piece.createPiece()
      const piece6 = await Piece.createPiece()
      const piece7 = await Piece.createPiece()
      const piece8 = await Piece.createPiece()
      const piece9 = await Piece.createPiece()
      const piece10 = await Piece.createPiece()
      game.pieces.push(piece1.id)
      game.pieces.push(piece2.id)
      game.pieces.push(piece3.id)
      game.pieces.push(piece4.id)
      game.pieces.push(piece5.id)
      game.pieces.push(piece6.id)
      game.pieces.push(piece7.id)
      game.pieces.push(piece8.id)
      game.pieces.push(piece9.id)
      game.pieces.push(piece10.id)
      await game.save()
      return game.serialize
    }

    catch (err) { throw 'Error while creating Game' }
  }

  /*
  show a Game
  */
  static async getGameByName(name) {

    try {
      const game = await Game.findOne({ room: name })
      .populate('pieces')
      .populate('players')
      .exec()
      if (!game) return null
      return game.serialize
    }

    catch(err) { throw 'Error while getting Game' }
  }

  static async getGames() {
    try {
    const games = await Game.find({})
    .populate('pieces')
    .populate('players')
      let allGame = games.map(g => g.serialize)
      return allGame
  } catch (err) {
    console.log(err);
    throw 'No game to display'
  }
}
  /*
  show a Game
  */
  static async getGameById(game_id) {

    try {
      const game = await Game.findOne({ _id: game_id })
      .populate('pieces')
      .populate('players')
      .exec()
      if (!game) throw 'Game not found'
      return game.serialize
    }

    catch(err) {throw 'Error while getting Game' }
  }

  /*
  Update a Game
  */
  static async updateGameById (body, id) {

    try {
      const game = await Game.findByIdAndUpdate(id, { $set: filter(body, permitted) }, { new: true })
      .populate('pieces')
      .populate('players')
      .exec()
      if (!game) throw 'Game not found'
      return game.serialize
    }

    catch(err) { throw 'Error while updating Game' }
  }

  /*
  Delete a Game
  */
  static async deleteGameById (game_id) {
    try {
      const game = await GameController.getGameById(game_id)
      game.pieces.forEach((piece) => {
        Piece.deletePieceById(piece._id)
      })
      game.players.forEach((player) => {
        Player.deletePlayerById(player._id)
      })
      Game.remove({ _id: game_id })
      .then(del => {
        if (!del.result.n) throw 'Game not found'
      })
    }

    catch(err) {throw 'Error while deleting Game' }
  }
}
