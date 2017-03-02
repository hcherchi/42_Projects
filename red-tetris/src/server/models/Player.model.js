import mongoose from 'mongoose'

const PlayerSchema = new mongoose.Schema({
  name: String,
  isVisitor: { type: Boolean, default: true },
  isDisconnected: { type: Boolean, default: false },
  curPiece: { type: Number, default: 0 },
  looser: { type: Boolean, default: false },
  winner: { type: Boolean, default: false },
  malus: { type: Number, default: 0 },
  spectre: { type: [Number], default: [] },
  socketId: {type: String, default: '' },
  gameId: {type: String, default: ''},
}, {
  usePushEach: true,
})

PlayerSchema.virtual('serialize').get(function () {
  return {
    id: this._id,
    name: this.name,
    isVisitor: this.isVisitor,
    isDisconnected: this.isDisconnected,
    curPiece: this.curPiece,
    looser: this.looser,
    winner: this.winner,
    malus: this.malus,
    spectre: this.spectre,
    socketId: this.socketId,
    gameId: this.gameId,
  }
})

const Player = mongoose.model('Player', PlayerSchema)

module.exports = Player
