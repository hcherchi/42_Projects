import chai from "chai"
import {fromJS} from 'immutable'
import _ from 'lodash'
import { types, isPossible, lineDestroyer, isPiece, rotate, pieceToBoard, updateSpectre, isGameLost} from '../src/client/helper.js'
const assert = require('chai').assert
const expect = chai.expect
const should = chai.should()

const initialState = {}
let socket

const socketURL = 'http://localhost:5000'

function clearDB () {
  for (const i in mongoose.connection.collections) {
    if (mongoose.connection.collections.hasOwnProperty(i)) {
      mongoose.connection.collections[i].remove()
    }
  }
}

const board = [
  [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
  [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
  [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
  [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
  [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
  [{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'white'}],
]
const board1 = [
  [{color: 'white'}, {color: 'red'}],
  [{color: 'white'}, {color: 'white'}],
]
const shape  = [
  [0, 0, 0, 0],
  [0, 1, 1, 0],
  [0, 1, 1, 0],
  [0, 0, 0, 0],

]
const spectre = [0,0,0,0,0,0,0,0,0,0]
describe('front helper', () => {

  describe('isGameLost', () => {

        it ('should be false if lost', done => {
          let lol =isGameLost(fromJS(board))
          assert.equal(lol, false)
          done()
        })
        it ('should be true if lost', done => {
          let lol =isGameLost(fromJS(board1))
          assert.equal(lol, true)
          done()
        })
  })

  describe('isPossible', () => {

        it ('should be false if not possible', done => {
          let lol =isPossible(fromJS(board), shape, 2,2)
          assert.equal(lol, true)
          done()
        })
        it ('should be true if lost', done => {
          let lol =isPossible(fromJS(board), shape, 5,5)
          assert.equal(lol, false)
          done()
        })
  })

  describe('lineDestroyer', () => {

        it ('should be false if not possible', done => {
          let lol =lineDestroyer(fromJS(board),null, 1111,22222)
          assert.equal(lol, false)
          done()
        })
  })

  describe('isPiece', () => {

        it ('should be false if not possible', done => {
          let lol = isPiece(1,1,shape, 2,2)
          assert.equal(lol, false)
          done()
        })
        it ('should be true if  possible', done => {
          let lol = isPiece(2,2 ,shape, 0,0)
          assert.equal(lol, true)
          done()
        })
  })
  describe('Rotate', () => {

        it ('should be rotatation', done => {
          let lol = rotate(shape)
          assert.equal(true, _.isEqual(lol, shape))
          done()
        })
  })
  describe('pieceToBoard', () => {

        it ('should be rotatation', done => {
          let lol = pieceToBoard(fromJS(board), shape, 10, 10, 'red')
          assert.equal(true, _.isEqual(lol, board))
          done()
        })
  })
  describe('updateSpectre', () => {

        it ('should be rotatation', done => {
          let lol = updateSpectre(fromJS(board), spectre)
          assert.equal(true, _.isEqual(lol, [0,0,0,0,0,0,0,0,21,21]))
          done()
        })
  })




})
