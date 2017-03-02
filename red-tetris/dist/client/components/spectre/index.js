'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactRedux = require('react-redux');

var _redial = require('redial');

var _startInterval = require('../../actions/startInterval.js');

var _startInterval2 = _interopRequireDefault(_startInterval);

var _reactFunctional = require('react-functional');

var _reactFunctional2 = _interopRequireDefault(_reactFunctional);

require('./style.scss');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var spectreGame = function spectreGame(props) {
  var player = props.player,
      board = props.board;


  var spectre = player.get('spectre');
  var name = player.get('name');
  var winner = player.get('winner');
  var looser = player.get('looser');

  return _react2.default.createElement(
    'div',
    { className: 'spectre' },
    _react2.default.createElement(
      'p',
      { className: 'name' },
      name
    ),
    board.map(function (line, j) {
      return j === 0 ? '' : _react2.default.createElement(
        'div',
        { key: j, className: 'Sline ' + (looser || winner ? ' blur' : '') },
        spectre.map(function (s, i) {
          if (s <= j) {
            return _react2.default.createElement('div', { key: i + ' ' + j, className: 'Sbloc gold' });
          } else {
            return _react2.default.createElement('div', { key: i + ' ' + j, className: 'Sbloc white' });
          }
        })
      );
    }),
    (looser || winner) && _react2.default.createElement(
      'h1',
      { className: 'Smessage' },
      winner ? 'WINNER' : 'LOOSER'
    )
  );
};

exports.default = spectreGame;