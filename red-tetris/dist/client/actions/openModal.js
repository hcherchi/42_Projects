'use strict';

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.default = openModal;
function openModal(data) {
  return {
    type: 'client/openModal',
    data: data
  };
}