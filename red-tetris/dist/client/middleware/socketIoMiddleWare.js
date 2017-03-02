'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _newPlayer = require('../actions/newPlayer');

var _newPlayer2 = _interopRequireDefault(_newPlayer);

var _disconnect = require('../actions/disconnect');

var _disconnect2 = _interopRequireDefault(_disconnect);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var parseUrl = function parseUrl(data) {
  var hash = data.hash;
  var matches = hash && hash.match(/#([^\[]+)\[([^\]]+)\]/);
  return matches ? { name: matches[2], room: matches[1] } : null;
};

var socketIoMiddleWare = function socketIoMiddleWare(socket) {
  return function (_ref) {
    var dispatch = _ref.dispatch,
        getState = _ref.getState;

    if (socket) socket.on('action', dispatch);
    return function (next) {
      return function (action) {
        if (action.type == '@@router/LOCATION_CHANGE') {
          var data = parseUrl(action.payload);
          var state = getState();
          if (state.game.room) dispatch((0, _disconnect2.default)(data));

          dispatch((0, _newPlayer2.default)(data));
        }
        if (socket && action.type && action.type.indexOf('server/') === 0) {
          var serverAction = action.type.split('/');
          socket.emit(serverAction[1], action.data);
        }

        return next(action);
      };
    };
  };
};

exports.default = socketIoMiddleWare;