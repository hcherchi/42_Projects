'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = startInterval;
function startInterval(data) {
  return {
    type: 'client/startInterval',
    data: data
  };
}