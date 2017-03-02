'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = restartGame;
function restartGame(data) {
  return {
    type: 'server/restartGame',
    data: data
  };
}