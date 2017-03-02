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

var _Player = require('../models/Player.model');

var _Player2 = _interopRequireDefault(_Player);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

var permitted = '{name,isVisitor,curPiece,looser,winner,malus,spectre,socketId,gameId,isDisconnected}';

var PlayerController = function () {
  function PlayerController() {
    (0, _classCallCheck3.default)(this, PlayerController);
  }

  (0, _createClass3.default)(PlayerController, null, [{
    key: 'createPlayer',


    /*
    create a new Player
    */
    value: function () {
      var _ref = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee(name, isVisitor, socketId, gameId) {
        var newPlayer, i;
        return _regenerator2.default.wrap(function _callee$(_context) {
          while (1) {
            switch (_context.prev = _context.next) {
              case 0:
                _context.prev = 0;
                newPlayer = new _Player2.default({ name: name, isVisitor: isVisitor, socketId: socketId, gameId: gameId });

                for (i = 0; i < 10; i++) {
                  newPlayer.spectre.push(21);
                }
                _context.next = 5;
                return newPlayer.save();

              case 5:
                return _context.abrupt('return', newPlayer.serialize);

              case 8:
                _context.prev = 8;
                _context.t0 = _context['catch'](0);
                console.log(_context.t0);throw 'Error while creating Player';

              case 12:
              case 'end':
                return _context.stop();
            }
          }
        }, _callee, this, [[0, 8]]);
      }));

      function createPlayer(_x, _x2, _x3, _x4) {
        return _ref.apply(this, arguments);
      }

      return createPlayer;
    }()

    /*
    Get a Player
    */

  }, {
    key: 'getPlayerById',
    value: function () {
      var _ref2 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee2(player_id) {
        var player;
        return _regenerator2.default.wrap(function _callee2$(_context2) {
          while (1) {
            switch (_context2.prev = _context2.next) {
              case 0:
                _context2.prev = 0;
                _context2.next = 3;
                return _Player2.default.findOne({ _id: player_id });

              case 3:
                player = _context2.sent;

                if (player) {
                  _context2.next = 6;
                  break;
                }

                throw 'Player not found';

              case 6:
                return _context2.abrupt('return', player.serialize);

              case 9:
                _context2.prev = 9;
                _context2.t0 = _context2['catch'](0);
                console.log(_context2.t0);throw 'Error while getting Player';

              case 13:
              case 'end':
                return _context2.stop();
            }
          }
        }, _callee2, this, [[0, 9]]);
      }));

      function getPlayerById(_x5) {
        return _ref2.apply(this, arguments);
      }

      return getPlayerById;
    }()

    /*
    Get a Player by socket
    */

  }, {
    key: 'getPlayerBySocket',
    value: function () {
      var _ref3 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee3(socketId) {
        var player;
        return _regenerator2.default.wrap(function _callee3$(_context3) {
          while (1) {
            switch (_context3.prev = _context3.next) {
              case 0:
                _context3.prev = 0;
                _context3.next = 3;
                return _Player2.default.findOne({ socketId: socketId });

              case 3:
                player = _context3.sent;

                if (player) {
                  _context3.next = 6;
                  break;
                }

                throw 'Player not found';

              case 6:
                return _context3.abrupt('return', player.serialize);

              case 9:
                _context3.prev = 9;
                _context3.t0 = _context3['catch'](0);
                console.log(_context3.t0);throw 'Error while getting Player';

              case 13:
              case 'end':
                return _context3.stop();
            }
          }
        }, _callee3, this, [[0, 9]]);
      }));

      function getPlayerBySocket(_x6) {
        return _ref3.apply(this, arguments);
      }

      return getPlayerBySocket;
    }()

    /*
    Update a Player
    */

  }, {
    key: 'updatePlayerById',
    value: function () {
      var _ref4 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee4(data, player_id) {
        var player;
        return _regenerator2.default.wrap(function _callee4$(_context4) {
          while (1) {
            switch (_context4.prev = _context4.next) {
              case 0:
                _context4.prev = 0;
                _context4.next = 3;
                return _Player2.default.findByIdAndUpdate(player_id, { $set: (0, _filterObject2.default)(data, permitted) }, { new: true });

              case 3:
                player = _context4.sent;

                if (player) {
                  _context4.next = 6;
                  break;
                }

                throw 'Player not found';

              case 6:
                return _context4.abrupt('return', player.serialize);

              case 9:
                _context4.prev = 9;
                _context4.t0 = _context4['catch'](0);
                console.log(_context4.t0);throw 'Error while updating Player';

              case 13:
              case 'end':
                return _context4.stop();
            }
          }
        }, _callee4, this, [[0, 9]]);
      }));

      function updatePlayerById(_x7, _x8) {
        return _ref4.apply(this, arguments);
      }

      return updatePlayerById;
    }()

    /*
    Delete a Player
    */

  }, {
    key: 'deletePlayerById',
    value: function () {
      var _ref5 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee5(player_id) {
        return _regenerator2.default.wrap(function _callee5$(_context5) {
          while (1) {
            switch (_context5.prev = _context5.next) {
              case 0:
                _context5.prev = 0;
                _context5.next = 3;
                return _Player2.default.remove({ _id: player_id });

              case 3:
                _context5.next = 9;
                break;

              case 5:
                _context5.prev = 5;
                _context5.t0 = _context5['catch'](0);
                console.log(_context5.t0);throw 'Error while deleting Player';

              case 9:
              case 'end':
                return _context5.stop();
            }
          }
        }, _callee5, this, [[0, 5]]);
      }));

      function deletePlayerById(_x9) {
        return _ref5.apply(this, arguments);
      }

      return deletePlayerById;
    }()
  }]);
  return PlayerController;
}();

exports.default = PlayerController;