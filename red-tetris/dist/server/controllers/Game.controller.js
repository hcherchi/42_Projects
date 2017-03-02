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

var _filterObject = require('filter-object');

var _filterObject2 = _interopRequireDefault(_filterObject);

var _Game = require('../models/Game.model');

var _Game2 = _interopRequireDefault(_Game);

var _Piece = require('./Piece.controller');

var _Piece2 = _interopRequireDefault(_Piece);

var _Player = require('./Player.controller');

var _Player2 = _interopRequireDefault(_Player);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var permitted = '{room,isOver,isStarted,players,pieces}';

var GameController = function () {
  function GameController() {
    (0, _classCallCheck3.default)(this, GameController);
  }

  (0, _createClass3.default)(GameController, null, [{
    key: 'createGame',


    /*
    while create a new Game
    */
    value: function () {
      var _ref = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee(room) {
        var game, piece1, piece2;
        return _regenerator2.default.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _context.prev = 0;
                _context.next = 3;
                return new _Game2.default({ room: room }).save();

              case 3:
                game = _context.sent;
                _context.next = 6;
                return _Piece2.default.createPiece();

              case 6:
                piece1 = _context.sent;
                _context.next = 9;
                return _Piece2.default.createPiece();

              case 9:
                piece2 = _context.sent;

                game.pieces.push(piece1.id);
                game.pieces.push(piece2.id);
                _context.next = 14;
                return game.save();

              case 14:
                return _context.abrupt('return', game.serialize);

              case 17:
                _context.prev = 17;
                _context.t0 = _context['catch'](0);
                throw 'Error while creating Game';

              case 20:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, this, [[0, 17]]);
      }));

      function createGame(_x) {
        return _ref.apply(this, arguments);
      }

      return createGame;
    }()

    /*
    show a Game
    */

  }, {
    key: 'getGameByName',
    value: function () {
      var _ref2 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee2(name) {
        var game;
        return _regenerator2.default.wrap(function _callee2$(_context2) {
          while (1) {
            switch (_context2.prev = _context2.next) {
              case 0:
                _context2.prev = 0;
                _context2.next = 3;
                return _Game2.default.findOne({ room: name }).populate('pieces').populate('players').exec();

              case 3:
                game = _context2.sent;

                if (game) {
                  _context2.next = 6;
                  break;
                }

                return _context2.abrupt('return', null);

              case 6:
                return _context2.abrupt('return', game.serialize);

              case 9:
                _context2.prev = 9;
                _context2.t0 = _context2['catch'](0);
                throw 'Error while getting Game';

              case 12:
              case 'end':
                return _context2.stop();
            }
          }
        }, _callee2, this, [[0, 9]]);
      }));

      function getGameByName(_x2) {
        return _ref2.apply(this, arguments);
      }

      return getGameByName;
    }()
  }, {
    key: 'getGames',
    value: function () {
      var _ref3 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee3() {
        var games, allGame;
        return _regenerator2.default.wrap(function _callee3$(_context3) {
          while (1) {
            switch (_context3.prev = _context3.next) {
              case 0:
                _context3.prev = 0;
                _context3.next = 3;
                return _Game2.default.find({}).populate('pieces').populate('players');

              case 3:
                games = _context3.sent;

                if (!(!games || games.length === 0)) {
                  _context3.next = 6;
                  break;
                }

                return _context3.abrupt('return', res.json({ results: [], message: 'No Games' }));

              case 6:
                allGame = games.map(function (g) {
                  return g.serialize;
                });
                return _context3.abrupt('return', allGame);

              case 10:
                _context3.prev = 10;
                _context3.t0 = _context3['catch'](0);

                console.log(_context3.t0);
                throw 'Error while getting all games';

              case 14:
              case 'end':
                return _context3.stop();
            }
          }
        }, _callee3, this, [[0, 10]]);
      }));

      function getGames() {
        return _ref3.apply(this, arguments);
      }

      return getGames;
    }()
    /*
    show a Game
    */

  }, {
    key: 'getGameById',
    value: function () {
      var _ref4 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee4(game_id) {
        var game;
        return _regenerator2.default.wrap(function _callee4$(_context4) {
          while (1) {
            switch (_context4.prev = _context4.next) {
              case 0:
                _context4.prev = 0;
                _context4.next = 3;
                return _Game2.default.findOne({ _id: game_id }).populate('pieces').populate('players').exec();

              case 3:
                game = _context4.sent;

                if (game) {
                  _context4.next = 6;
                  break;
                }

                throw 'Game not found';

              case 6:
                return _context4.abrupt('return', game.serialize);

              case 9:
                _context4.prev = 9;
                _context4.t0 = _context4['catch'](0);
                throw 'Error while getting Game';

              case 12:
              case 'end':
                return _context4.stop();
            }
          }
        }, _callee4, this, [[0, 9]]);
      }));

      function getGameById(_x3) {
        return _ref4.apply(this, arguments);
      }

      return getGameById;
    }()

    /*
    Update a Game
    */

  }, {
    key: 'updateGameById',
    value: function () {
      var _ref5 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee5(body, id) {
        var game;
        return _regenerator2.default.wrap(function _callee5$(_context5) {
          while (1) {
            switch (_context5.prev = _context5.next) {
              case 0:
                _context5.prev = 0;
                _context5.next = 3;
                return _Game2.default.findByIdAndUpdate(id, { $set: (0, _filterObject2.default)(body, permitted) }, { new: true }).populate('pieces').populate('players').exec();

              case 3:
                game = _context5.sent;

                if (game) {
                  _context5.next = 6;
                  break;
                }

                throw 'Game not found';

              case 6:
                return _context5.abrupt('return', game.serialize);

              case 9:
                _context5.prev = 9;
                _context5.t0 = _context5['catch'](0);
                throw 'Error while updating Game';

              case 12:
              case 'end':
                return _context5.stop();
            }
          }
        }, _callee5, this, [[0, 9]]);
      }));

      function updateGameById(_x4, _x5) {
        return _ref5.apply(this, arguments);
      }

      return updateGameById;
    }()

    /*
    Delete a Game
    */

  }, {
    key: 'deleteGameById',
    value: function () {
      var _ref6 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee6(game_id) {
        var game;
        return _regenerator2.default.wrap(function _callee6$(_context6) {
          while (1) {
            switch (_context6.prev = _context6.next) {
              case 0:
                _context6.prev = 0;
                _context6.next = 3;
                return GameController.getGameById(game_id);

              case 3:
                game = _context6.sent;

                game.pieces.forEach(function (piece) {
                  _Piece2.default.deletePieceById(piece._id);
                });
                game.players.forEach(function (player) {
                  _Player2.default.deletePlayerById(player._id);
                });
                _Game2.default.remove({ _id: game_id }).then(function (del) {
                  if (!del.result.n) throw 'Game not found';
                });
                _context6.next = 12;
                break;

              case 9:
                _context6.prev = 9;
                _context6.t0 = _context6['catch'](0);
                throw 'Error while deleting Game';

              case 12:
              case 'end':
                return _context6.stop();
            }
          }
        }, _callee6, this, [[0, 9]]);
      }));

      function deleteGameById(_x6) {
        return _ref6.apply(this, arguments);
      }

      return deleteGameById;
    }()
  }]);
  return GameController;
}();

exports.default = GameController;