'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.createPlayer = undefined;

var _mongoose = require('mongoose');

var _mongoose2 = _interopRequireDefault(_mongoose);

var _errors = require('../utils/errors');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var createPlayer = exports.createPlayer = function createPlayer(req, res, next) {
  if (!req.body.name) {
    return (0, _errors.handleMongooseError)(new _errors.ValidationError('name', 'missing'), res);
  }
  return next();
};