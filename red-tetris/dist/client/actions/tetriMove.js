'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = tetriMove;
function tetriMove(data) {
  return {
    type: 'client/tetriMove',
    data: data
  };
}