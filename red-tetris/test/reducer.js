import chai from "chai"
import {fromJS} from 'immutable'
import _ from 'lodash'
import reducers from '../src/client/reducers'
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

function creatTab() {
  const tab = []
  for(let c = 0; c < 21; c++) {

    let tab_tmp = []
    for(let d = 0; d < 10; d++) {
      tab_tmp.push({color: 'white'})
    }
    tab.push(tab_tmp)
  }
  return tab
}

const intialState = {
  room: null,
  games: null,
  info: null,
  board: creatTab(),
  hasToWait: false,
  modal: false,
  currentRoom: null,
}
describe('reducer', () => {

  describe('NEW_PLAYER', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'NEW_PLAYER', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('NEXT_TURN', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'NEXT_TURN', data: {name: 'oeuoeu'} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })

  describe('START_GAME', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'START_GAME', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('GET_GAMES', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'GET_GAMES', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('DISCONNECTED', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'DISCONNECTED', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('LOSE_GAME', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'LOSE_GAME', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('GIVE_MALUS', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'GIVE_MALUS', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('ERROR', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'ERROR', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('client/openModal', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'client/openModal', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('client/posePiece', () => {

        it ('should be false ', done => {
          let lol =reducers(fromJS(intialState), {type: 'client/posePiece', data: {} })
          assert.equal(false, _.isEqual(lol, initialState))
          done()
        })
  })
  describe('client/moveLine', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/moveLine', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/disactivation', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/disactivation', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/activation', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/activation', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/startInterval', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/startInterval', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/newPlayer', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/newPlayer', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/tetriMove', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/tetriMove', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })
    describe('client/tetriRotate', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/tetriRotate', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })

    describe('client/clearMessage', () => {

          it ('should be false ', done => {
            let lol =reducers(fromJS(intialState), {type: 'client/clearMessage', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })

    describe('default', () => {

          it ('should be true ', done => {
            let lol =reducers(fromJS(intialState), {type: '', data: {} })
            assert.equal(false, _.isEqual(lol, initialState))
            done()
          })
    })


})
