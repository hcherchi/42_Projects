'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});

var _regenerator = require('babel-runtime/regenerator');

var _regenerator2 = _interopRequireDefault(_regenerator);

var _asyncToGenerator2 = require('babel-runtime/helpers/asyncToGenerator');

var _asyncToGenerator3 = _interopRequireDefault(_asyncToGenerator2);

var _GameController = require('../controllers/Game.controller.js');

var _GameController2 = _interopRequireDefault(_GameController);

var _PlayerController = require('../controllers/Player.controller.js');

var _PlayerController2 = _interopRequireDefault(_PlayerController);

var _PieceController = require('../controllers/Piece.controller.js');

var _PieceController2 = _interopRequireDefault(_PieceController);

var _lodash = require('lodash');

var _lodash2 = _interopRequireDefault(_lodash);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

exports.default = function (socket) {

  socket.on('disconnect', function (data) {
    return disconnected(data, socket);
  });

  socket.on('newPlayer', function (data) {
    return newPlayer(data, socket);
  });

  socket.on('startGame', function (data) {
    return startGame(data, socket);
  });

  socket.on('nextTurn', function (data) {
    return nextTurn(data, socket);
  });

  socket.on('restartGame', function (data) {
    return restartGame(data, socket);
  });

  socket.on('giveMalus', function (data) {
    return giveMalus(data, socket);
  });

  socket.on('loseGame', function (data) {
    return loseGame(data, socket);
  });

  socket.on('getGames', function (data) {
    return getGames(data, socket);
  });
};

var getGames = function () {
  var _ref = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee(data, socket) {
    var allGame;
    return _regenerator2.default.wrap(function _callee$(_context) {
      while (1) {
        switch (_context.prev = _context.next) {
          case 0:
            _context.prev = 0;
            _context.next = 3;
            return _GameController2.default.getGames();

          case 3:
            allGame = _context.sent;

            socket.emit('action', {
              type: 'GET_GAMES',
              data: allGame
            });
            _context.next = 10;
            break;

          case 7:
            _context.prev = 7;
            _context.t0 = _context['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context.t0
            });

          case 10:
          case 'end':
            return _context.stop();
        }
      }
    }, _callee, undefined, [[0, 7]]);
  }));

  return function getGames(_x, _x2) {
    return _ref.apply(this, arguments);
  };
}();

var loseGame = function () {
  var _ref2 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee3(data, socket) {
    return _regenerator2.default.wrap(function _callee3$(_context3) {
      while (1) {
        switch (_context3.prev = _context3.next) {
          case 0:
            _context3.prev = 0;
            return _context3.delegateYield(_regenerator2.default.mark(function _callee2() {
              var isOver, updatedPlayer, game, standingPlayers, updatedGame;
              return _regenerator2.default.wrap(function _callee2$(_context2) {
                while (1) {
                  switch (_context2.prev = _context2.next) {
                    case 0:
                      isOver = false;
                      _context2.next = 3;
                      return _PlayerController2.default.updatePlayerById({ looser: true }, data.player_id);

                    case 3:
                      updatedPlayer = _context2.sent;
                      _context2.next = 6;
                      return _GameController2.default.getGameById(data.game_id);

                    case 6:
                      game = _context2.sent;
                      standingPlayers = _lodash2.default.filter(game.players, function (player) {
                        return !player.looser;
                      });

                      if (standingPlayers.length == 1 && game.players.length != 1 || standingPlayers.length == 0) {
                        if (standingPlayers.length == 1) _PlayerController2.default.updatePlayerById({ winner: true }, standingPlayers[0].id);
                        isOver = true;
                      }

                      _context2.next = 11;
                      return _GameController2.default.updateGameById({ isOver: isOver }, data.game_id);

                    case 11:
                      updatedGame = _context2.sent;

                      updatedGame.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'LOSE_GAME',
                          data: updatedGame
                        });
                      });

                    case 13:
                    case 'end':
                      return _context2.stop();
                  }
                }
              }, _callee2, undefined);
            })(), 't0', 2);

          case 2:
            _context3.next = 7;
            break;

          case 4:
            _context3.prev = 4;
            _context3.t1 = _context3['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context3.t1
            });

          case 7:
          case 'end':
            return _context3.stop();
        }
      }
    }, _callee3, undefined, [[0, 4]]);
  }));

  return function loseGame(_x3, _x4) {
    return _ref2.apply(this, arguments);
  };
}();

var addMalusToSpectre = function addMalusToSpectre(spectre, malus) {
  return spectre.map(function (line) {
    var newline = line - malus;
    if (newline < 0) newline = 0;
    return newline;
  });
};

var giveMalus = function () {
  var _ref3 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee5(data, socket) {
    return _regenerator2.default.wrap(function _callee5$(_context5) {
      while (1) {
        switch (_context5.prev = _context5.next) {
          case 0:
            _context5.prev = 0;
            return _context5.delegateYield(_regenerator2.default.mark(function _callee4() {
              var game, promises, goodPlayer, otherPlayer, updatedGame;
              return _regenerator2.default.wrap(function _callee4$(_context4) {
                while (1) {
                  switch (_context4.prev = _context4.next) {
                    case 0:
                      _context4.next = 2;
                      return _GameController2.default.getGameById(data.game_id);

                    case 2:
                      game = _context4.sent;
                      promises = [];
                      goodPlayer = game.players.find(function (player) {
                        return player.id == data.player_id;
                      });
                      otherPlayer = game.players.filter(function (player) {
                        return player.id != data.player_id;
                      });

                      otherPlayer.forEach(function (player) {
                        return promises.push(_PlayerController2.default.updatePlayerById({ spectre: addMalusToSpectre(player.spectre, data.malus) }, player.id));
                      });
                      _context4.next = 9;
                      return Promise.all(promises);

                    case 9:
                      _context4.next = 11;
                      return _GameController2.default.getGameById(data.game_id);

                    case 11:
                      updatedGame = _context4.sent;

                      updatedGame.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'GIVE_MALUS',
                          data: { game: updatedGame, malus: player.id == data.player_id ? 0 : data.malus, message: goodPlayer.id != player.id ? goodPlayer.name + ' just gave you a malus...' : null }
                        });
                      });

                    case 13:
                    case 'end':
                      return _context4.stop();
                  }
                }
              }, _callee4, undefined);
            })(), 't0', 2);

          case 2:
            _context5.next = 7;
            break;

          case 4:
            _context5.prev = 4;
            _context5.t1 = _context5['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context5.t1
            });

          case 7:
          case 'end':
            return _context5.stop();
        }
      }
    }, _callee5, undefined, [[0, 4]]);
  }));

  return function giveMalus(_x5, _x6) {
    return _ref3.apply(this, arguments);
  };
}();

var restartGame = function () {
  var _ref4 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee7(data, socket) {
    return _regenerator2.default.wrap(function _callee7$(_context7) {
      while (1) {
        switch (_context7.prev = _context7.next) {
          case 0:
            _context7.prev = 0;
            return _context7.delegateYield(_regenerator2.default.mark(function _callee6() {
              var newPiece1, newPiece2, updatedGame, promises, game;
              return _regenerator2.default.wrap(function _callee6$(_context6) {
                while (1) {
                  switch (_context6.prev = _context6.next) {
                    case 0:
                      _context6.next = 2;
                      return _PieceController2.default.createPiece();

                    case 2:
                      newPiece1 = _context6.sent;
                      _context6.next = 5;
                      return _PieceController2.default.createPiece();

                    case 5:
                      newPiece2 = _context6.sent;
                      _context6.next = 8;
                      return _GameController2.default.updateGameById({ isOver: false, isStarted: false, pieces: [newPiece1.id, newPiece2.id] }, data.game_id);

                    case 8:
                      updatedGame = _context6.sent;
                      promises = [];

                      updatedGame.players.forEach(function (player) {
                        return promises.push(_PlayerController2.default.updatePlayerById({ looser: false, winner: false, curPiece: 0, malus: 0, spectre: [21, 21, 21, 21, 21, 21, 21, 21, 21, 21] }, player.id));
                      });
                      _context6.next = 13;
                      return Promise.all(promises);

                    case 13:
                      _context6.next = 15;
                      return _GameController2.default.getGameById(data.game_id);

                    case 15:
                      game = _context6.sent;


                      game.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'RESTART_GAME',
                          data: game
                        });
                      });

                    case 17:
                    case 'end':
                      return _context6.stop();
                  }
                }
              }, _callee6, undefined);
            })(), 't0', 2);

          case 2:
            _context7.next = 7;
            break;

          case 4:
            _context7.prev = 4;
            _context7.t1 = _context7['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context7.t1
            });

          case 7:
          case 'end':
            return _context7.stop();
        }
      }
    }, _callee7, undefined, [[0, 4]]);
  }));

  return function restartGame(_x7, _x8) {
    return _ref4.apply(this, arguments);
  };
}();

var disconnected = function () {
  var _ref5 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee9(data, socket) {
    var playerInfo, updatedPlayer, isOver, game;
    return _regenerator2.default.wrap(function _callee9$(_context9) {
      while (1) {
        switch (_context9.prev = _context9.next) {
          case 0:
            _context9.prev = 0;
            _context9.next = 3;
            return _PlayerController2.default.getPlayerBySocket(socket.id);

          case 3:
            playerInfo = _context9.sent;
            _context9.next = 6;
            return _PlayerController2.default.updatePlayerById({ isDisconnected: true }, playerInfo.id);

          case 6:
            updatedPlayer = _context9.sent;
            isOver = false;
            _context9.next = 10;
            return _PlayerController2.default.deletePlayerById(playerInfo.id);

          case 10:
            _context9.next = 12;
            return _GameController2.default.getGameById(playerInfo.gameId);

          case 12:
            game = _context9.sent;

            if (!(game.players.length != 0)) {
              _context9.next = 17;
              break;
            }

            return _context9.delegateYield(_regenerator2.default.mark(function _callee8() {
              var standingPlayers, updatedGame;
              return _regenerator2.default.wrap(function _callee8$(_context8) {
                while (1) {
                  switch (_context8.prev = _context8.next) {
                    case 0:
                      standingPlayers = _lodash2.default.filter(game.players, function (player) {
                        return !player.looser;
                      });

                      if (standingPlayers.length == 1 && game.players.length != 1 || standingPlayers.length == 0) {
                        if (standingPlayers.length == 1) _PlayerController2.default.updatePlayerById({ winner: true }, standingPlayers[0].id);
                        isOver = true;
                      }
                      _context8.next = 4;
                      return _PlayerController2.default.updatePlayerById({ isVisitor: false }, game.players[0]._id);

                    case 4:
                      _context8.next = 6;
                      return _GameController2.default.updateGameById({ isOver: isOver }, game.id);

                    case 6:
                      updatedGame = _context8.sent;


                      game.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'DISCONNECTED',
                          data: updatedGame,
                          message: 'Player disconnected'
                        });
                      });

                    case 8:
                    case 'end':
                      return _context8.stop();
                  }
                }
              }, _callee8, undefined);
            })(), 't0', 15);

          case 15:
            _context9.next = 18;
            break;

          case 17:
            _GameController2.default.deleteGameById(game.id);

          case 18:
            _context9.next = 23;
            break;

          case 20:
            _context9.prev = 20;
            _context9.t1 = _context9['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context9.t1
            });

          case 23:
          case 'end':
            return _context9.stop();
        }
      }
    }, _callee9, undefined, [[0, 20]]);
  }));

  return function disconnected(_x9, _x10) {
    return _ref5.apply(this, arguments);
  };
}();

var newPlayer = function () {
  var _ref6 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee11(data, socket) {
    return _regenerator2.default.wrap(function _callee11$(_context11) {
      while (1) {
        switch (_context11.prev = _context11.next) {
          case 0:
            _context11.prev = 0;
            return _context11.delegateYield(_regenerator2.default.mark(function _callee10() {
              var game, isVisitor, playerCreated;
              return _regenerator2.default.wrap(function _callee10$(_context10) {
                while (1) {
                  switch (_context10.prev = _context10.next) {
                    case 0:
                      _context10.next = 2;
                      return _GameController2.default.getGameByName(data.room);

                    case 2:
                      game = _context10.sent;
                      isVisitor = true;

                      if (game) {
                        _context10.next = 9;
                        break;
                      }

                      _context10.next = 7;
                      return _GameController2.default.createGame(data.room);

                    case 7:
                      game = _context10.sent;

                      isVisitor = false;

                    case 9:
                      if (!(game.players.length == 5)) {
                        _context10.next = 11;
                        break;
                      }

                      throw 'Too many players';

                    case 11:
                      if (!_lodash2.default.find(game.players, function (player) {
                        return player.name === data.name;
                      })) {
                        _context10.next = 13;
                        break;
                      }

                      throw 'name already taken';

                    case 13:
                      if (!game.isStarted) {
                        _context10.next = 15;
                        break;
                      }

                      throw 'The game has already started';

                    case 15:
                      _context10.next = 17;
                      return _PlayerController2.default.createPlayer(data.name, isVisitor, socket.id, game.id);

                    case 17:
                      playerCreated = _context10.sent;
                      _context10.next = 20;
                      return _GameController2.default.updateGameById({ players: game.players.concat(playerCreated.id) }, game.id);

                    case 20:
                      game = _context10.sent;

                      game.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'NEW_PLAYER',
                          data: game,
                          message: 'Player successfully created'
                        });
                      });

                    case 22:
                    case 'end':
                      return _context10.stop();
                  }
                }
              }, _callee10, undefined);
            })(), 't0', 2);

          case 2:
            _context11.next = 7;
            break;

          case 4:
            _context11.prev = 4;
            _context11.t1 = _context11['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context11.t1
            });

          case 7:
          case 'end':
            return _context11.stop();
        }
      }
    }, _callee11, undefined, [[0, 4]]);
  }));

  return function newPlayer(_x11, _x12) {
    return _ref6.apply(this, arguments);
  };
}();

var startGame = function () {
  var _ref7 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee13(data, socket) {
    return _regenerator2.default.wrap(function _callee13$(_context13) {
      while (1) {
        switch (_context13.prev = _context13.next) {
          case 0:
            _context13.prev = 0;
            return _context13.delegateYield(_regenerator2.default.mark(function _callee12() {
              var updatedGame;
              return _regenerator2.default.wrap(function _callee12$(_context12) {
                while (1) {
                  switch (_context12.prev = _context12.next) {
                    case 0:
                      _context12.next = 2;
                      return _GameController2.default.updateGameById({ isStarted: true }, data.game_id);

                    case 2:
                      updatedGame = _context12.sent;

                      updatedGame.players.forEach(function (player) {
                        global.io.to(player.socketId).emit('action', {
                          type: 'START_GAME',
                          data: updatedGame,
                          message: 'Game successfully started'
                        });
                      });

                    case 4:
                    case 'end':
                      return _context12.stop();
                  }
                }
              }, _callee12, undefined);
            })(), 't0', 2);

          case 2:
            _context13.next = 7;
            break;

          case 4:
            _context13.prev = 4;
            _context13.t1 = _context13['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context13.t1
            });

          case 7:
          case 'end':
            return _context13.stop();
        }
      }
    }, _callee13, undefined, [[0, 4]]);
  }));

  return function startGame(_x13, _x14) {
    return _ref7.apply(this, arguments);
  };
}();

var nextTurn = function () {
  var _ref8 = (0, _asyncToGenerator3.default)(_regenerator2.default.mark(function _callee15(data, socket) {
    return _regenerator2.default.wrap(function _callee15$(_context15) {
      while (1) {
        switch (_context15.prev = _context15.next) {
          case 0:
            _context15.prev = 0;
            return _context15.delegateYield(_regenerator2.default.mark(function _callee14() {
              var player, updatedPlayer, game, piece, updatedGame;
              return _regenerator2.default.wrap(function _callee14$(_context14) {
                while (1) {
                  switch (_context14.prev = _context14.next) {
                    case 0:
                      _context14.next = 2;
                      return _PlayerController2.default.getPlayerById(data.player_id);

                    case 2:
                      player = _context14.sent;
                      _context14.next = 5;
                      return _PlayerController2.default.updatePlayerById({ spectre: data.spectre, curPiece: player.curPiece + 1 }, data.player_id);

                    case 5:
                      updatedPlayer = _context14.sent;
                      _context14.next = 8;
                      return _GameController2.default.getGameById(data.game_id);

                    case 8:
                      game = _context14.sent;

                      if (!(updatedPlayer.curPiece >= game.pieces.length - 1)) {
                        _context14.next = 14;
                        break;
                      }

                      _context14.next = 12;
                      return _PieceController2.default.createPiece();

                    case 12:
                      piece = _context14.sent;

                      game.pieces.push(piece.id);

                    case 14:
                      _context14.next = 16;
                      return _GameController2.default.updateGameById({ pieces: game.pieces }, game.id);

                    case 16:
                      updatedGame = _context14.sent;

                      updatedGame.players.forEach(function (playeur) {
                        global.io.to(playeur.socketId).emit('action', {
                          type: 'NEXT_TURN',
                          data: { updatedGame: updatedGame, name: player.name }
                        });
                      });

                    case 18:
                    case 'end':
                      return _context14.stop();
                  }
                }
              }, _callee14, undefined);
            })(), 't0', 2);

          case 2:
            _context15.next = 7;
            break;

          case 4:
            _context15.prev = 4;
            _context15.t1 = _context15['catch'](0);

            socket.emit('action', {
              type: 'ERROR',
              data: _context15.t1
            });

          case 7:
          case 'end':
            return _context15.stop();
        }
      }
    }, _callee15, undefined, [[0, 4]]);
  }));

  return function nextTurn(_x15, _x16) {
    return _ref8.apply(this, arguments);
  };
}();