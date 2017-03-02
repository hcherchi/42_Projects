import mongoose from 'mongoose'

const GameSchema = new mongoose.Schema({
  room: String,
  isOver: { type: Boolean, default: false },
  isStarted: { type: Boolean, default: false },
  pieces: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Piece' }],
  players: [{ type: mongoose.Schema.Types.ObjectId, ref: 'Player' }],
}, {
  usePushEach: true,
})

GameSchema.virtual('serialize').get(function () {
  return {
    id: this._id,
    room: this.room,
    isOver: this.isOver,
    isStarted: this.isStarted,
    pieces: this.pieces,
    players: this.players,
  }
})

const Game = mongoose.model('Game', GameSchema)

module.exports = Game
