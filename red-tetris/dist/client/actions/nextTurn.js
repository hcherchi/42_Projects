'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = nextTurn;
function nextTurn(data) {
  return {
    type: 'server/nextTurn',
    data: data
  };
}