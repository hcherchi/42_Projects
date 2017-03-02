'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = giveMalus;
function giveMalus(data) {
  return {
    type: 'server/giveMalus',
    data: data
  };
}