'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = moveLine;
function moveLine(data) {
  return {
    type: 'client/moveLine',
    data: data
  };
}