'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactRedux = require('react-redux');

var _lodash = require('lodash');

var _lodash2 = _interopRequireDefault(_lodash);

var _startGame2 = require('../../actions/startGame');

var _startGame3 = _interopRequireDefault(_startGame2);

require('./style.scss');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var Room = function Room(props) {
  var room = props.room,
      info = props.info,
      players = props.players,
      startGame = props.startGame;


  var currentPlayer = players.find(function (player) {
    return player.getIn(['name']) == info.getIn(['name']);
  });
  var number = players.size;
  var disabled = currentPlayer.getIn(['isVisitor']);

  return _react2.default.createElement(
    'div',
    { className: 'room' },
    _react2.default.createElement(
      'button',
      { onClick: disabled ? '' : function () {
          return startGame({ game_id: room.getIn(['id']) });
        }, className: disabled ? 'disabled' : '' },
      _react2.default.createElement('i', { className: 'ion-play', style: { fontSize: '6vh' } }),
      _react2.default.createElement(
        'p',
        null,
        'Start Game',
        _react2.default.createElement('br', null),
        number,
        '/5'
      )
    )
  );
};

var mapStateToProps = function mapStateToProps(state) {
  return {
    room: state.game.getIn(['room']),
    info: state.game.getIn(['info']),
    players: state.game.getIn(['room', 'players'])
  };
};

var mapDispatchToProps = function mapDispatchToProps(dispatch) {
  return {
    startGame: function startGame(data) {
      return dispatch((0, _startGame3.default)(data));
    }
  };
};

exports.default = (0, _reactRedux.connect)(mapStateToProps, mapDispatchToProps)(Room);