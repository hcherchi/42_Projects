'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = newPlayer;
function newPlayer(data) {

  return {
    type: 'server/newPlayer',
    data: data
  };
}