'use strict';

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var PieceSchema = new _mongoose2.default.Schema({
  shape: { type: Array, default: [] },
  color: { type: String, default: "black" },
  positionX: { type: Number, default: 0 },
  positionY: { type: Number, default: 0 }
}, {
  usePushEach: true
});

PieceSchema.virtual('serialize').get(function () {
  return {
    id: this._id,
    shape: this.shape,
    color: this.color,
    rotation: this.rotation,
    positionX: this.positionX,
    positionY: this.positionY
  };
});

var Piece = _mongoose2.default.model('Piece', PieceSchema);

module.exports = Piece;