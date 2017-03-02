import mongoose from 'mongoose'

const PieceSchema = new mongoose.Schema({
  shape: { type: Array, default: [] },
  color: { type: String, default: "black" },
  positionX: { type: Number, default: 0 },
  positionY: { type: Number, default: 0 },
}, {
  usePushEach: true,
})

PieceSchema.virtual('serialize').get(function () {
  return {
    id: this._id,
    shape: this.shape,
    color: this.color,
    rotation: this.rotation,
    positionX: this.positionX,
    positionY: this.positionY,
  }
})

const Piece = mongoose.model('Piece', PieceSchema)

module.exports = Piece
