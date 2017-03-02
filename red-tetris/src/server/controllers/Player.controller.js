import filter from 'filter-object'
import Player from '../models/Player.model'

const permitted ='{name,isVisitor,curPiece,looser,winner,malus,spectre,socketId,gameId,isDisconnected}'

export default class PlayerController {

  /*
  create a new Player
  */
  static async createPlayer(name, isVisitor, socketId, gameId) {
    try {

      const newPlayer = new Player({ name, isVisitor, socketId, gameId})
      for (let i = 0; i < 10; i++) {
        newPlayer.spectre.push(21)
      }
      await newPlayer.save()
      return newPlayer.serialize
    }

    catch(err) { console.log(err);throw 'Error while creating Player' }
  }

  /*
  Get a Player
  */
  static async getPlayerById(player_id) {
    try {
      const player = await Player.findOne({ _id: player_id })
      if (!player) throw 'Player not found'
      return player.serialize
    }

    catch(err) { console.log(err); throw 'Error while getting Player' }
  }

  /*
  Get a Player by socket
  */

  static async getPlayerBySocket(socketId) {
    try {
      const player = await Player.findOne({ socketId })
      if (!player) throw 'Player not found'
      return player.serialize
    }

    catch(err) { console.log(err);throw 'Error while getting Player' }
  }

  /*
  Update a Player
  */
  static async updatePlayerById (data, player_id) {
    try {
      const player = await Player.findByIdAndUpdate(player_id, { $set: filter(data, permitted) }, { new: true })
      if (!player) throw 'Player not found'
      return player.serialize
    }

    catch(err) { console.log(err);throw 'Error while updating Player' }
  }

  /*
  Delete a Player
  */
  static async deletePlayerById (player_id) {
    try {
      await Player.remove({ _id: player_id })
    }
    catch(err) { console.log(err);throw 'Error while deleting Player' }
  }
}
