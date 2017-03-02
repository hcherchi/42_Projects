"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.handleMongooseError = exports.FormatError = exports.ValidationError = exports.notFoundError = undefined;

var _classCallCheck2 = require("babel-runtime/helpers/classCallCheck");

var _classCallCheck3 = _interopRequireDefault(_classCallCheck2);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

/**
 * Thrown when a resource is not found in db
 */
var notFoundError = exports.notFoundError = function notFoundError(target) {
  (0, _classCallCheck3.default)(this, notFoundError);

  this.target = target;
};

/**
 * Thrown when a parameter is invalid
 */


var ValidationError = exports.ValidationError = function ValidationError(target, action) {
  (0, _classCallCheck3.default)(this, ValidationError);

  this.target = target;
  this.action = action;
};

/**
 * Thrown by the validators, if an error is invalid
 */


var FormatError = exports.FormatError = function FormatError(message) {
  (0, _classCallCheck3.default)(this, FormatError);

  this.message = message;
};

/**
 * Handle the differents types of error the Connector methods can throw
 */


var handleMongooseError = exports.handleMongooseError = function handleMongooseError(err, res, message) {
  if (err instanceof notFoundError) {
    return res.status(404).json({ results: null, message: err.target + " not found" });
  } else if (err instanceof ValidationError) {
    return res.status(400).json({ results: null, message: "Parameter " + err.target + " is " + err.action });
  } else if (err instanceof FormatError) {
    return res.status(400).json({ results: null, message: err.message });
  }
  res.status(500).json({ results: null, message: message });
};