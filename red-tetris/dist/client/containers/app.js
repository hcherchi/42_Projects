'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactRedux = require('react-redux');

var _boardGame = require('../components/boardGame');

var _boardGame2 = _interopRequireDefault(_boardGame);

var _Room = require('../components/Room');

var _Room2 = _interopRequireDefault(_Room);

var _spectre = require('../components/spectre');

var _spectre2 = _interopRequireDefault(_spectre);

var _serverPage = require('../components/serverPage');

var _serverPage2 = _interopRequireDefault(_serverPage);

var _newPlayer2 = require('../actions/newPlayer');

var _newPlayer3 = _interopRequireDefault(_newPlayer2);

require('./style.scss');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var App = function App(props) {
  var room = props.room,
      info = props.info,
      newPlayer = props.newPlayer,
      error = props.error,
      otherPlayers = props.otherPlayers,
      board = props.board,
      router = props.router;

  var data = info && { name: info.getIn(['name']), room: info.getIn(['room']) };

  var errorCondition = error || !data;
  var connectionCondition = !errorCondition && !room;
  var roomCondition = !errorCondition && room && !room.getIn(['isStarted']);
  var gameCondition = !errorCondition && room && room.getIn(['isStarted']);

  var errorMessage = error ? error : 'The URL is invalid, please use: #<room>[<player_name>]';

  return _react2.default.createElement(
    'div',
    { className: 'container' },
    _react2.default.createElement(
      'header',
      null,
      _react2.default.createElement(
        'h1',
        null,
        'Red.Tetris'
      )
    ),
    _react2.default.createElement(
      'div',
      { className: 'content' },
      _react2.default.createElement(
        'div',
        { className: 'center' },
        errorCondition && _react2.default.createElement(
          'div',
          { className: 'error' },
          _react2.default.createElement(
            'p',
            null,
            errorMessage
          )
        ),
        !roomCondition && !gameCondition && _react2.default.createElement(_serverPage2.default, {
          router: router
        })
      ),
      otherPlayers && _react2.default.createElement(
        'div',
        { className: 'spectre--container' },
        otherPlayers.size >= 1 && _react2.default.createElement(_spectre2.default, { player: otherPlayers.get(0), board: board }),
        otherPlayers.size >= 2 && _react2.default.createElement(_spectre2.default, { player: otherPlayers.get(1), board: board })
      ),
      roomCondition && _react2.default.createElement(_Room2.default, null),
      gameCondition && _react2.default.createElement(_boardGame2.default, null),
      otherPlayers && _react2.default.createElement(
        'div',
        { className: 'spectre--container' },
        otherPlayers.size >= 3 && _react2.default.createElement(_spectre2.default, { player: otherPlayers.get(2), board: board }),
        otherPlayers.size >= 4 && _react2.default.createElement(_spectre2.default, { player: otherPlayers.get(3), board: board })
      )
    ),
    _react2.default.createElement(
      'footer',
      null,
      _react2.default.createElement(
        'h1',
        null,
        'Swag'
      )
    )
  );
};

var mapStateToProps = function mapStateToProps(state) {
  var info = state.game.getIn(['info']);
  var error = state.game.getIn(['error']);
  var room = state.game.getIn(['room']);
  var players = room && room.get('players');
  var otherPlayers = players && players.filter(function (player) {
    return player.get('name') != info.get('name');
  });
  var board = state.game.getIn(['board']);
  return {
    room: room,
    info: info,
    error: error,
    otherPlayers: otherPlayers,
    board: board
  };
};

var mapDispatchToProps = function mapDispatchToProps(dispatch) {
  return {
    newPlayer: function newPlayer(data) {
      return dispatch((0, _newPlayer3.default)(data));
    }
  };
};

exports.default = (0, _reactRedux.connect)(mapStateToProps, mapDispatchToProps)(App);