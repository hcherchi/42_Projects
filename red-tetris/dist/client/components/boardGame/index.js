'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _defineProperty2 = require('babel-runtime/helpers/defineProperty');

var _defineProperty3 = _interopRequireDefault(_defineProperty2);

var _react = require('react');

var _react2 = _interopRequireDefault(_react);

var _reactRedux = require('react-redux');

var _redial = require('redial');

var _tetriMove2 = require('../../actions/tetriMove.js');

var _tetriMove3 = _interopRequireDefault(_tetriMove2);

var _tetriRotate2 = require('../../actions/tetriRotate.js');

var _tetriRotate3 = _interopRequireDefault(_tetriRotate2);

var _nextTurn2 = require('../../actions/nextTurn.js');

var _nextTurn3 = _interopRequireDefault(_nextTurn2);

var _moveLine2 = require('../../actions/moveLine.js');

var _moveLine3 = _interopRequireDefault(_moveLine2);

var _disactivation2 = require('../../actions/disactivation');

var _disactivation3 = _interopRequireDefault(_disactivation2);

var _activation2 = require('../../actions/activation');

var _activation3 = _interopRequireDefault(_activation2);

var _posePiece2 = require('../../actions/posePiece');

var _posePiece3 = _interopRequireDefault(_posePiece2);

var _restartGame2 = require('../../actions/restartGame');

var _restartGame3 = _interopRequireDefault(_restartGame2);

var _loseGame2 = require('../../actions/loseGame');

var _loseGame3 = _interopRequireDefault(_loseGame2);

var _giveMalus2 = require('../../actions/giveMalus');

var _giveMalus3 = _interopRequireDefault(_giveMalus2);

var _clearMessage2 = require('../../actions/clearMessage');

var _clearMessage3 = _interopRequireDefault(_clearMessage2);

var _helper = require('../../helper');

var _startInterval2 = require('../../actions/startInterval.js');

var _startInterval3 = _interopRequireDefault(_startInterval2);

var _reactFunctional = require('react-functional');

var _reactFunctional2 = _interopRequireDefault(_reactFunctional);

var _immutable = require('immutable');

require('./style.scss');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var moveDown = function moveDown(props) {
  var board = props.board,
      shape = props.shape,
      posX = props.posX,
      posY = props.posY,
      curPiece = props.curPiece,
      tetriMove = props.tetriMove,
      nextTurn = props.nextTurn,
      posePiece = props.posePiece,
      color = props.color,
      game_id = props.game_id,
      player_id = props.player_id,
      spectre = props.spectre;


  if ((0, _helper.isPossible)(board, shape, posX, posY + 1)) tetriMove({ posX: posX, posY: posY + 1, curPiece: curPiece });else {
    var newBoard = (0, _helper.pieceToBoard)(board, shape, posX, posY, color);
    posePiece(newBoard);
    nextTurn({
      game_id: game_id,
      player_id: player_id,
      spectre: (0, _helper.updateSpectre)(newBoard, spectre)
    });
  }
};

var moveLeft = function moveLeft(props) {
  var board = props.board,
      shape = props.shape,
      posX = props.posX,
      posY = props.posY,
      curPiece = props.curPiece,
      tetriMove = props.tetriMove;


  if ((0, _helper.isPossible)(board, shape, posX - 1, posY)) tetriMove({ posX: posX - 1, posY: posY, curPiece: curPiece });
};

var moveRight = function moveRight(props) {
  var board = props.board,
      shape = props.shape,
      posX = props.posX,
      posY = props.posY,
      curPiece = props.curPiece,
      tetriMove = props.tetriMove;


  if ((0, _helper.isPossible)(board, shape, posX + 1, posY)) tetriMove({ posX: posX + 1, posY: posY, curPiece: curPiece });
};

var moveRotate = function moveRotate(props) {
  var board = props.board,
      shape = props.shape,
      posX = props.posX,
      posY = props.posY,
      curPiece = props.curPiece,
      tetriRotate = props.tetriRotate;


  var newShape = (0, _helper.rotate)(shape);

  if ((0, _helper.isPossible)(board, newShape, posX, posY)) tetriRotate({ shape: newShape, curPiece: curPiece });
};

var boardGame = function boardGame(props) {
  var posX = props.posX,
      posY = props.posY,
      board = props.board,
      restartGame = props.restartGame,
      shape = props.shape,
      color = props.color,
      players = props.players,
      looser = props.looser,
      winner = props.winner,
      isOver = props.isOver,
      isVisitor = props.isVisitor,
      game_id = props.game_id,
      message = props.message,
      nextPiece = props.nextPiece,
      nextPieceColor = props.nextPieceColor;


  var onKey = function onKey(e) {
    if (e.keyCode === 32) moveRotate(props);
    if (e.keyCode === 39) moveRight(props);
    if (e.keyCode === 37) moveLeft(props);
    if (e.keyCode === 40) moveDown(props);
  };
  return _react2.default.createElement(
    'div',
    { className: 'game' },
    _react2.default.createElement(
      'div',
      { className: 'space' },
      nextPiece && _react2.default.createElement(
        'div',
        { className: 'board' },
        nextPiece.map(function (line, j) {
          return _react2.default.createElement(
            'div',
            { key: j, className: 'line' },
            line.map(function (bloc, i) {
              return _react2.default.createElement('div', { key: i + ' ' + j, className: 'sbloc ' + (bloc ? nextPieceColor : 'white') });
            })
          );
        })
      )
    ),
    _react2.default.createElement(
      'div',
      { className: 'board', id: 'inner', tabIndex: '-1', onBlur: function onBlur() {
          return document.getElementById('inner').focus();
        }, onKeyDown: isOver ? '' : function (e) {
          return onKey(e);
        } },
      board.map(function (line, j) {
        return j === 0 ? '' : _react2.default.createElement(
          'div',
          { key: j, className: 'line ' + (looser || winner ? ' blur' : '') },
          line.map(function (bloc, i) {
            if ((0, _helper.isPiece)(i, j, shape, posX, posY)) {
              return _react2.default.createElement('div', { key: i + ' ' + j, className: 'bloc ' + color });
            } else {
              return _react2.default.createElement('div', { key: i + ' ' + j, className: 'bloc ' + bloc.get('color') });
            }
          })
        );
      }),
      (looser || winner) && _react2.default.createElement(
        'h1',
        { className: 'message' },
        winner ? 'WINNER' : 'LOOSER'
      )
    ),
    _react2.default.createElement(
      'div',
      { className: 'space' },
      !isOver && message && _react2.default.createElement(
        'p',
        null,
        message
      ),
      isOver && !isVisitor && _react2.default.createElement(
        'button',
        { onClick: function onClick() {
            return restartGame({ game_id: game_id });
          } },
        _react2.default.createElement(
          'p',
          null,
          'Play again'
        )
      )
    )
  );
};

function mapStateToProps(state) {
  var _ref;

  var players = state.game.getIn(['room', 'players']);
  var pieces = state.game.getIn(['room', 'pieces']);
  var game_id = state.game.getIn(['room', 'id']);

  var isOver = state.game.getIn(['room', 'isOver']);

  var currentPlayerIndex = players.findIndex(function (player) {
    return player.get('name') === state.game.getIn(['info', 'name']);
  });
  var currentPlayer = players.find(function (player) {
    return player.get('name') === state.game.getIn(['info', 'name']);
  });
  var isVisitor = currentPlayer.get('isVisitor');
  var looser = currentPlayer.get('looser');
  var winner = currentPlayer.get('winner');

  var curPiece = currentPlayer.get('curPiece');
  var nextPiece = pieces.getIn([curPiece + 1, 'shape']);
  var nextPieceColor = pieces.getIn([curPiece + 1, 'color']);
  var player_id = currentPlayer.get('_id');
  var spectre = currentPlayer.get('spectre').toJS();
  var currentPiece = state.game.getIn(['currentPiece']);

  var posX = void 0;
  var posY = void 0;
  var color = void 0;
  var shape = void 0;
  if (!currentPiece) {
    console.log('in the devil');
    posX = -3;
    posY = 0;
    color = 'red';
    shape = [[0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0]];
  } else {
    posX = currentPiece.get('positionX');
    posY = currentPiece.get('positionY');
    color = currentPiece.get('color');
    shape = currentPiece.get('shape').toJS();
  }
  var board = state.game.getIn(['board']);
  var hasToFall = state.game.get('hasToFall');
  var interval = state.game.get('interval');
  var message = state.game.get('message');

  return _ref = {
    isOver: isOver,
    looser: looser,
    winner: winner,
    isVisitor: isVisitor,
    currentPlayerIndex: currentPlayerIndex,
    currentPlayer: currentPlayer,
    curPiece: curPiece,
    board: board,
    posX: posX,
    posY: posY,
    nextPiece: nextPiece,
    player_id: player_id,
    game_id: game_id,
    spectre: spectre,
    currentPiece: currentPiece,
    color: color,
    shape: shape,
    hasToFall: hasToFall,
    interval: interval,
    players: players
  }, (0, _defineProperty3.default)(_ref, 'spectre', spectre), (0, _defineProperty3.default)(_ref, 'message', message), (0, _defineProperty3.default)(_ref, 'nextPieceColor', nextPieceColor), _ref;
}

function mapDispatchToProps(dispatch) {
  return {
    tetriMove: function tetriMove(data) {
      return dispatch((0, _tetriMove3.default)(data));
    },
    tetriRotate: function tetriRotate(data) {
      return dispatch((0, _tetriRotate3.default)(data));
    },
    nextTurn: function nextTurn(data) {
      return dispatch((0, _nextTurn3.default)(data));
    },
    moveLine: function moveLine(data) {
      return dispatch((0, _moveLine3.default)(data));
    },
    posePiece: function posePiece(data) {
      return dispatch((0, _posePiece3.default)(data));
    },
    activation: function activation() {
      return dispatch((0, _activation3.default)());
    },
    disactivation: function disactivation() {
      return dispatch((0, _disactivation3.default)());
    },
    startInterval: function startInterval(data) {
      return dispatch((0, _startInterval3.default)(data));
    },
    restartGame: function restartGame(data) {
      return dispatch((0, _restartGame3.default)(data));
    },
    loseGame: function loseGame(data) {
      return dispatch((0, _loseGame3.default)(data));
    },
    giveMalus: function giveMalus(data) {
      return dispatch((0, _giveMalus3.default)(data));
    },
    clearMessage: function clearMessage() {
      return dispatch((0, _clearMessage3.default)());
    }
  };
}

boardGame.componentDidMount = function (props, refs) {
  var startInterval = props.startInterval,
      activation = props.activation;

  document.getElementById('inner').focus();
  startInterval(setInterval(function () {
    return activation();
  }, 1));
};

boardGame.componentWillUnmount = function (props, refs) {
  var interval = props.interval;


  clearInterval(interval);
};

boardGame.componentDidUpdate = function (props, refs) {
  var interval = props.interval,
      board = props.board,
      winner = props.winner,
      looser = props.looser,
      moveLine = props.moveLine,
      hasToFall = props.hasToFall,
      disactivation = props.disactivation,
      loseGame = props.loseGame,
      player_id = props.player_id,
      game_id = props.game_id,
      giveMalus = props.giveMalus,
      clearMessage = props.clearMessage,
      message = props.message;


  if (message && !(0, _immutable.is)(message, refs.message)) setTimeout(function () {
    return clearMessage();
  }, 5000);

  if (!(0, _immutable.is)(looser, refs.looser) || !(0, _immutable.is)(winner, refs.winner)) clearInterval(interval);

  if (!(0, _immutable.is)(board, refs.board)) {
    if ((0, _helper.isGameLost)(board)) loseGame({ player_id: player_id, game_id: game_id });
    var lineToDestroy = (0, _helper.lineDestroyer)(board, giveMalus, player_id, game_id);
    if (lineToDestroy) moveLine(lineToDestroy);
  }

  if (hasToFall) {
    moveDown(props);
    disactivation();
  }
};

exports.default = (0, _reactRedux.connect)(mapStateToProps, mapDispatchToProps)((0, _reactFunctional2.default)(boardGame));