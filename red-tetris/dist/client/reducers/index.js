'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _immutable = require('immutable');

var _lodash = require('lodash');

var _lodash2 = _interopRequireDefault(_lodash);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function creatTab() {
  var tab = [];
  for (var c = 0; c < 21; c++) {

    var tab_tmp = [];
    for (var d = 0; d < 10; d++) {
      tab_tmp.push({ color: 'white' });
    }
    tab.push(tab_tmp);
  }
  return tab;
}

var newLine = function newLine(color) {
  var line = [];
  for (var i = 0; i < 10; i++) {
    line.push({ color: color });
  }return line;
};

var putMalusToBoard = function putMalusToBoard(board, malus) {
  var i = 0;
  while (i < malus) {
    board.push(newLine('black'));
    board.shift();
    i++;
  }
  return (0, _immutable.fromJS)(board);
};

var intialState = {
  room: null,
  games: null,
  info: null,
  board: creatTab(),
  hasToWait: false,
  modal: false,
  currentRoom: null
};

var reducer = function reducer() {
  var state = arguments.length > 0 && arguments[0] !== undefined ? arguments[0] : (0, _immutable.fromJS)(intialState);
  var action = arguments[1];

  switch (action.type) {
    case 'NEW_PLAYER':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data));
    case 'START_GAME':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data)).setIn(['currentPiece'], state.getIn(['room', 'pieces', 0]));
    case 'RESTART_GAME':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data)).setIn(['board'], (0, _immutable.fromJS)(creatTab()));
    case 'GET_GAMES':
      return state.setIn(['games'], (0, _immutable.fromJS)(action.data));
    case 'NEXT_TURN':
      if (state.getIn(['info', 'name']) !== action.data.name) {
        return state.setIn(['room'], (0, _immutable.fromJS)(action.data.updatedGame)).setIn(['hasToWait'], false);
      } else {
        var players = action.data.updatedGame.players;
        var currentPlayer = players.find(function (player) {
          return player.name == action.data.name;
        });
        var currentIndexPiece = currentPlayer.curPiece;
        var piece = action.data.updatedGame.pieces[currentIndexPiece];

        return state.setIn(['room'], (0, _immutable.fromJS)(action.data.updatedGame)).setIn(['hasToWait'], false).setIn(['currentPiece'], (0, _immutable.fromJS)(piece));
      }
    case 'DISCONNECTED':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data));
    case 'LOSE_GAME':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data));
    case 'GIVE_MALUS':
      return state.setIn(['room'], (0, _immutable.fromJS)(action.data.game)).setIn(['board'], putMalusToBoard(state.get('board').toJS(), action.data.malus)).setIn(['message'], action.data.message);
    case 'ERROR':
      return state.setIn(['error'], (0, _immutable.fromJS)(action.data));
    case 'client/openModal':
      return state.setIn(['modal'], (0, _immutable.fromJS)(action.data.modal)).setIn(['currentRoom'], (0, _immutable.fromJS)(action.data.currentRoom));
    case 'client/posePiece':
      return state.setIn(['board'], (0, _immutable.fromJS)(action.data));
    case 'client/moveLine':
      return state.setIn(['board'], (0, _immutable.fromJS)(action.data));
    case 'client/disactivation':
      return state.setIn(['hasToFall'], false);
    case 'client/activation':
      return state.setIn(['hasToFall'], true);
    case 'client/startInterval':
      return state.setIn(['interval'], (0, _immutable.fromJS)(action.data));
    case 'server/newPlayer':
      return state.setIn(['info'], (0, _immutable.fromJS)(action.data)).setIn(['room'], null).setIn(['error'], null).setIn(['board'], (0, _immutable.fromJS)(creatTab()));
    case 'client/tetriMove':
      return state.setIn(['currentPiece', 'positionX'], action.data.posX).setIn(['currentPiece', 'positionY'], action.data.posY);
    case 'client/tetriRotate':
      return state.setIn(['currentPiece', 'shape'], (0, _immutable.fromJS)(action.data.shape));
    case 'client/clearMessage':
      return state.setIn(['message'], null);
    default:
      return state;
  }
};

exports.default = reducer;