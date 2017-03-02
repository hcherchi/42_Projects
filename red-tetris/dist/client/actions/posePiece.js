'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = posePiece;
function posePiece(data) {

  return {
    type: 'client/posePiece',
    data: data
  };
}