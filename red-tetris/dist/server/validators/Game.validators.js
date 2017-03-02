'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.createGame = undefined;

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

var _errors = require('../utils/errors');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var createGame = exports.createGame = function createGame(req, res, next) {
  var room = req.body.room;

  if (!room) {
    return (0, _errors.handleMongooseError)(new _errors.ValidationError('room', 'missing'), res);
  }
  return next();
};