'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = loseGame;
function loseGame(data) {
  return {
    type: 'server/loseGame',
    data: data
  };
}