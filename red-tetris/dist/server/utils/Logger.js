'use strict';

var _classCallCheck2 = require('babel-runtime/helpers/classCallCheck');

var _classCallCheck3 = _interopRequireDefault(_classCallCheck2);

var _createClass2 = require('babel-runtime/helpers/createClass');

var _createClass3 = _interopRequireDefault(_createClass2);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var COLOR = {
  BLACK: '30',
  RED: '31',
  GREEN: '32',
  YELLOW: '33',
  BLUE: '34',
  PINK: '35',
  CYAN: '36',
  GREY: '37'
};

/* eslint-disable no-console */

var Logger = function () {
  function Logger() {
    (0, _classCallCheck3.default)(this, Logger);
  }

  (0, _createClass3.default)(Logger, null, [{
    key: 'error',
    value: function error() {
      for (var _len = arguments.length, messages = Array(_len), _key = 0; _key < _len; _key++) {
        messages[_key] = arguments[_key];
      }

      messages.map(function (message) {
        return Logger.show(message, COLOR.RED);
      });
    }
  }, {
    key: 'success',
    value: function success() {
      for (var _len2 = arguments.length, messages = Array(_len2), _key2 = 0; _key2 < _len2; _key2++) {
        messages[_key2] = arguments[_key2];
      }

      messages.map(function (message) {
        return Logger.show(message, COLOR.GREEN);
      });
    }
  }, {
    key: 'warning',
    value: function warning() {
      for (var _len3 = arguments.length, messages = Array(_len3), _key3 = 0; _key3 < _len3; _key3++) {
        messages[_key3] = arguments[_key3];
      }

      messages.map(function (message) {
        return Logger.show(message, COLOR.YELLOW);
      });
    }
  }, {
    key: 'info',
    value: function info() {
      for (var _len4 = arguments.length, messages = Array(_len4), _key4 = 0; _key4 < _len4; _key4++) {
        messages[_key4] = arguments[_key4];
      }

      messages.map(function (message) {
        return Logger.show(message, COLOR.CYAN);
      });
    }
  }, {
    key: 'log',
    value: function log() {
      for (var _len5 = arguments.length, messages = Array(_len5), _key5 = 0; _key5 < _len5; _key5++) {
        messages[_key5] = arguments[_key5];
      }

      messages.map(function (message) {
        return Logger.show(message);
      });
    }
  }, {
    key: 'show',
    value: function show(message, color) {
      if (process.env.NODE_ENV !== 'test') {
        if (!color) {
          console.log(message);
        } else {
          console.log('\x1B[' + color + 'm', '' + message, '\x1b[0m');
        }
      }
    }
  }]);
  return Logger;
}();

module.exports = Logger;
/* eslint-esable no-console */