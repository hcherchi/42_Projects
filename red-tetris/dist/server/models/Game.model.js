'use strict';

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var GameSchema = new _mongoose2.default.Schema({
  room: String,
  isOver: { type: Boolean, default: false },
  isStarted: { type: Boolean, default: false },
  pieces: [{ type: _mongoose2.default.Schema.Types.ObjectId, ref: 'Piece' }],
  players: [{ type: _mongoose2.default.Schema.Types.ObjectId, ref: 'Player' }]
}, {
  usePushEach: true
});

GameSchema.virtual('serialize').get(function () {
  return {
    id: this._id,
    room: this.room,
    isOver: this.isOver,
    isStarted: this.isStarted,
    pieces: this.pieces,
    players: this.players
  };
});

var Game = _mongoose2.default.model('Game', GameSchema);

module.exports = Game;