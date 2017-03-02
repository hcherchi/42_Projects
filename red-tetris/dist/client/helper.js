'use strict';

var _typeof2 = require('babel-runtime/helpers/typeof');

var _typeof3 = _interopRequireDefault(_typeof2);

var _lodash = require('lodash');

var _lodash2 = _interopRequireDefault(_lodash);

var _immutable = require('immutable');

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var isGameLost = function isGameLost(board) {
  try {
    var line = board.get(0);
    line.forEach(function (bloc) {
      if (bloc && bloc.get('color') != 'white') throw true;
    });
    return false;
  } catch (e) {
    return e;
  }
};

var isPossible = function isPossible(board, shape, posX, posY) {

  try {
    shape.forEach(function (line, y) {
      line.forEach(function (bloc, x) {
        var newY = y + posY;
        var newX = x + posX;
        var onBoard = true;
        var free = true;

        if (newY >= 21 || newX < 0 || newX >= 10) onBoard = false;
        if (onBoard && newY >= 0 && board && board.getIn([newY, newX, 'color']) !== 'white') free = false;

        if (shape[y][x] == 1 && (!onBoard || !free)) throw null;
      });
    });
    return true;
  } catch (e) {
    return false;
  }
};

function newLine() {
  var tab_tmp = [];
  for (var d = 0; d < 10; d++) {
    tab_tmp.push({ color: 'white' });
  }
  return tab_tmp;
}

var lineDestroyer = function lineDestroyer(board, giveMalus, player_id, game_id) {
  try {
    var _ret = function () {
      var newTab = board.toJS();
      var toRet = [];
      newTab.forEach(function (line, x) {
        var checker = 0;
        line.forEach(function (bloc, y) {
          if (bloc.color !== 'white' && bloc.color !== 'black') {
            checker++;
          }
        });
        if (checker === 10) {
          toRet.push(x);
        }
      });
      if (toRet.length > 1) giveMalus({ player_id: player_id, game_id: game_id, malus: toRet.length - 1 });
      if (toRet.length != 0) {
        for (var d = 0; d < toRet.length; d++) {
          newTab.splice(toRet[d], 1);
          newTab.unshift(newLine());
        }
        return {
          v: newTab
        };
      } else {
        return {
          v: false
        };
      }
    }();

    if ((typeof _ret === 'undefined' ? 'undefined' : (0, _typeof3.default)(_ret)) === "object") return _ret.v;
  } catch (e) {
    console.log('err', e);
  }
};

var isPiece = function isPiece(i, j, shape, posX, posY) {
  var x = i - posX;
  var y = j - posY;
  if (x < 0 || x >= shape.length || y < 0 || y >= shape.length) return false;
  if (shape[y][x] === 1) return true;else return false;
};

var rotate = function rotate(shape) {
  var newShape = [];
  shape.forEach(function (line, i) {
    line.forEach(function (bloc, j) {
      if (!newShape[j]) newShape[j] = [];
      newShape[j][line.length - i - 1] = shape[i][j];
    });
  });
  return newShape;
};

var pieceToBoard = function pieceToBoard(board, shape, posX, posY, color) {
  try {
    var _ret2 = function () {
      var test = board.toJS();
      board.forEach(function (line, j) {
        line.forEach(function (bloc, i) {
          if (isPiece(i, j, shape, posX, posY) && i >= 0 && i < 10 && j >= 0 && j < 21) {
            test[j][i].color = color;
          }
        });
      });
      return {
        v: test
      };
    }();

    if ((typeof _ret2 === 'undefined' ? 'undefined' : (0, _typeof3.default)(_ret2)) === "object") return _ret2.v;
  } catch (e) {
    console.log(e);
    return false;
  }
};
var updateSpectre = function updateSpectre(newBoard, spectre) {
  try {
    spectre.forEach(function (s, e) {
      return spectre[e] = 21;
    });
    newBoard.forEach(function (line, j) {
      var test_tmp = [];
      line.forEach(function (bloc, i) {
        if (bloc.color != 'white') {
          spectre[i] = Math.min(spectre[i], j);
        }
      });
    });
    return spectre;
  } catch (e) {
    console.log(e);
    return false;
  }
};

module.exports = {
  updateSpectre: updateSpectre,
  pieceToBoard: pieceToBoard,
  rotate: rotate,
  lineDestroyer: lineDestroyer,
  isPiece: isPiece,
  isPossible: isPossible,
  isGameLost: isGameLost
};