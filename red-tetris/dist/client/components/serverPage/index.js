'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactModal = require('react-modal');

var _reactModal2 = _interopRequireDefault(_reactModal);

var _reactRedux = require('react-redux');

var _lodash = require('lodash');

var _lodash2 = _interopRequireDefault(_lodash);

var _getGames2 = require('../../actions/getGames');

var _getGames3 = _interopRequireDefault(_getGames2);

var _openModal2 = require('../../actions/openModal');

var _openModal3 = _interopRequireDefault(_openModal2);

require('./style.scss');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var customStyles = {
  content: {
    top: '50%',
    left: '50%',
    right: 'auto',
    bottom: 'auto',
    background: '',
    border: '',
    transform: 'translate(-50%, -50%)'
  }
};

var Room = function Room(state) {
  var router = state.router,
      getGames = state.getGames,
      openModal = state.openModal,
      currentRoom = state.currentRoom,
      games = state.games,
      modal = state.modal;


  return _react2.default.createElement(
    'div',
    { className: 'room' },
    _react2.default.createElement(
      'button',
      { className: 'indexServer', onClick: function onClick(e) {
          return getGames();
        } },
      'join a room'
    ),
    _react2.default.createElement(
      _reactModal2.default,
      {
        isOpen: modal,
        style: customStyles,
        onRequestClose: function onRequestClose() {
          return openModal({ modal: !modal, currentRoom: null });
        },
        contentLabel: 'Name Modal'
      },
      _react2.default.createElement(
        'form',
        { className: 'formModal', onSubmit: function onSubmit(e) {
            e.preventDefault();
            var Name = document.getElementById('Name').value;
            var curr = currentRoom;
            openModal({ modal: !modal, currentRoom: null });
            router.router.push('#' + curr + '[' + Name + ']');
          } },
        _react2.default.createElement('input', { className: 'inputText', type: 'text', id: 'Name', placeholder: 'Name' }),
        _react2.default.createElement('input', { className: 'input', type: 'submit', value: 'GO' })
      )
    ),
    _react2.default.createElement(
      'div',
      { className: 'server' },
      games && games.map(function (p, i) {
        var players = p.get('players').toJS();
        var str = p.get('room');
        if (str.length >= 10) {
          str = str.slice(0, 10) + '...';
        }
        if (!p.get('isStarted')) {

          return _react2.default.createElement(
            'button',
            { className: 'notStarted',
              key: i,
              onClick: function onClick(e) {
                return openModal({ modal: !modal, currentRoom: p.get('room') });
              } },
            _react2.default.createElement(
              'p',
              null,
              str
            ),
            _react2.default.createElement(
              'p',
              null,
              players.length + '/5',
              ' '
            )
          );
        } else {
          return _react2.default.createElement(
            'button',
            { className: 'disabled asStarted',
              key: i
            },
            _react2.default.createElement(
              'p',
              null,
              str
            ),
            _react2.default.createElement(
              'p',
              null,
              players.length + '/5',
              ' '
            )
          );
        }
      })
    ),
    _react2.default.createElement(
      'p',
      { className: 'or' },
      ' or '
    ),
    _react2.default.createElement(
      'form',
      { className: 'form', onSubmit: function onSubmit(e) {
          e.preventDefault();
          var hostName = document.getElementById('hostName').value;
          var roomName = document.getElementById('roomName').value;

          if (hostName !== '' && roomName !== '') {
            router.router.push('#' + roomName + '[' + hostName + ']');
          }
        } },
      _react2.default.createElement(
        'legend',
        { className: 'legend' },
        'Create your room '
      ),
      _react2.default.createElement('input', { className: 'inputText', type: 'text', id: 'hostName', placeholder: 'Host Name' }),
      _react2.default.createElement('input', { className: 'inputText', type: 'text', id: 'roomName', placeholder: 'Room Name' }),
      _react2.default.createElement(
        'button',
        { className: 'input', type: 'submit' },
        'GO'
      )
    )
  );
};

var mapStateToProps = function mapStateToProps(state, router) {
  return {
    currentRoom: state.game.getIn(['currentRoom']),
    modal: state.game.getIn(['modal']),
    games: state.game.getIn(['games']),
    room: state.game.getIn(['room']),
    info: state.game.getIn(['info']),
    players: state.game.getIn(['room', 'players']),
    router: router
  };
};

var mapDispatchToProps = function mapDispatchToProps(dispatch) {
  return {
    openModal: function openModal(data) {
      return dispatch((0, _openModal3.default)(data));
    },
    getGames: function getGames(data) {
      return dispatch((0, _getGames3.default)(data));
    }
  };
};

exports.default = (0, _reactRedux.connect)(mapStateToProps, mapDispatchToProps)(Room);