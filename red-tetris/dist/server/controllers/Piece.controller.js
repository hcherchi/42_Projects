'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _regenerator = require('babel-runtime/regenerator');

var _regenerator2 = _interopRequireDefault(_regenerator);

var _asyncToGenerator2 = require('babel-runtime/helpers/asyncToGenerator');

var _asyncToGenerator3 = _interopRequireDefault(_asyncToGenerator2);

var _classCallCheck2 = require('babel-runtime/helpers/classCallCheck');

var _classCallCheck3 = _interopRequireDefault(_classCallCheck2);

var _createClass2 = require('babel-runtime/helpers/createClass');

var _createClass3 = _interopRequireDefault(_createClass2);

var _Piece = require('../models/Piece.model');

var _Piece2 = _interopRequireDefault(_Piece);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var colors = ['pink', 'red', 'green', 'gold', 'purple', 'blue', 'grey'];

var types = [[[0, 0, 0, 0], [0, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 0]], [[0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0], [0, 0, 1, 0]], [[0, 1, 0], [1, 1, 0], [0, 1, 0]], [[0, 1, 0], [0, 1, 1], [0, 0, 1]], [[0, 1, 0], [1, 1, 0], [1, 0, 0]], [[0, 1, 1], [0, 1, 0], [0, 1, 0]], [[1, 1, 0], [0, 1, 0], [0, 1, 0]]];

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

var random = function random(nb) {
  return Math.floor(Math.random() * nb);
};

var PieceController = function () {
  function PieceController() {
    (0, _classCallCheck3.default)(this, PieceController);
  }

  (0, _createClass3.default)(PieceController, null, [{
    key: 'createPiece',


    /*
    create a new Piece
    */
    value: function () {
      var _ref = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee() {
        var piece, type, rotation, i, newPiece;
        return _regenerator2.default.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _context.prev = 0;
                piece = {};
                type = random(7);

                piece.shape = types[type];
                piece.color = colors[type];
                rotation = random(4);

                for (i = 0; i <= rotation; i++) {
                  piece.shape = rotate(piece.shape);
                }piece.positionX = random(7);
                piece.positionY = -piece.shape.length;
                _context.next = 11;
                return new _Piece2.default(piece).save();

              case 11:
                newPiece = _context.sent;
                return _context.abrupt('return', newPiece.serialize);

              case 15:
                _context.prev = 15;
                _context.t0 = _context['catch'](0);
                throw 'Error while creating a Piece';

              case 18:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, this, [[0, 15]]);
      }));

      function createPiece() {
        return _ref.apply(this, arguments);
      }

      return createPiece;
    }()
  }, {
    key: 'deletePieceById',
    value: function () {
      var _ref2 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee2(piece_id) {
        return _regenerator2.default.wrap(function _callee2$(_context2) {
          while (1) {
            switch (_context2.prev = _context2.next) {
              case 0:
                _context2.prev = 0;
                _context2.next = 3;
                return _Piece2.default.remove({ _id: piece_id });

              case 3:
                _context2.next = 8;
                break;

              case 5:
                _context2.prev = 5;
                _context2.t0 = _context2['catch'](0);
                throw 'Error while deleting Piece';

              case 8:
              case 'end':
                return _context2.stop();
            }
          }
        }, _callee2, this, [[0, 5]]);
      }));

      function deletePieceById(_x) {
        return _ref2.apply(this, arguments);
      }

      return deletePieceById;
    }()
  }]);
  return PieceController;
}();

exports.default = PieceController;