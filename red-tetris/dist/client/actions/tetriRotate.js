'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = tetriRotate;
function tetriRotate(data) {
  return {
    type: 'client/tetriRotate',
    data: data
  };
}