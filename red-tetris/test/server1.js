import chai from "chai"
import {startServer, configureStore} from './helpers/server'
import mongoose from 'mongoose'
import rootReducer from '../src/client/reducers'
import newPlayer from '../src/client/actions/newPlayer'
import io from 'socket.io-client'
import params from '../params'

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


describe('Event', () => {
  after( () => clearDB())
  beforeEach(done => {
    socket = io.connect(socketURL)
    socket.on('connect', () => {
      done()
    })
  })

  describe('Socket: create a player', () => {
    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK create player', done => {
      socket.on('action', (res) => {
        assert.equal(res.data.room,  'the_first_time')
        done()
      })
      socket.emit('newPlayer', {room: 'the_first_time', name: 'testo'})
    })
    it ('should be ERROR create player', done => {
      socket.on('action', (res) => {
        assert.equal(res.data, 'name already taken')
        done()
      })
      socket.emit('newPlayer', {room: 'the_first_time', name: 'testo'})
    })

  })

  describe('Socket: get games', () => {
    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK get games', done => {
      socket.on('action', (res) => {
        assert.equal(res.data.length, 1)
        done()
      })
      socket.emit('getGames', {})
    })
 })


  describe('Socket: loosse a game', () => {
    let game_id
    let player_id
    beforeEach(done => {
      socket.on('action', (res) => {
          if(res.type === 'NEW_PLAYER') {
        game_id = res.data.id
        player_id = res.data.players[0]._id
        done()
      }
      })
      socket.emit('newPlayer', {room: 'the_111', name: 'testo'})
    })
    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })

    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK loosse game', done => {
      socket.on('action', (res) => {
        assert.equal(res.data.players[0].looser, true)
        done()
      })
      socket.emit('loseGame', {player_id, game_id})
    })
  })
  describe('Socket: Give a malus', () => {
    let game_id
    let player_id
    let malus
    beforeEach(done => {
      socket.on('action', (res) => {
        if(res.type === 'NEW_PLAYER') {
        game_id = res.data.id
        player_id = res.data.players[0]._id
        malus = 2
        done()
      }
      })
      socket.emit('newPlayer', {room: 'the_11133', name: 'testo'})
    })

    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK give malus', done => {
      socket.on('action', (res) => {
        assert.equal(res.type, 'GIVE_MALUS')
        assert.equal(res.data.malus, 0)
        done()
      })
      socket.emit('giveMalus', {player_id, game_id, malus})
    })
  })

  describe('Socket: Restart a game', () => {
    let game_id
    beforeEach(done => {
      socket.on('action', (res) => {
        if(res.type === 'NEW_PLAYER') {
        game_id = res.data.id
        done()
      }
      })
      socket.emit('newPlayer', {room: 'the_111332', name: 'testo'})
    })

    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK Restart a game', done => {
      socket.on('action', (res) => {
        assert.equal(res.type, 'RESTART_GAME')
        assert.equal(res.data.room, 'the_111332')
        assert.equal(res.data.isOver, false)
        done()
      })
      socket.emit('restartGame', {game_id})
    })
  })

  describe('Socket: Start a game', () => {
    let game_id
    beforeEach(done => {
      socket.on('action', (res) => {
        if(res.type === 'NEW_PLAYER') {
        game_id = res.data.id
      }
      if (res.type === 'NEW_PLAYER') {
        game_id = res.data.id
        done()
      }
      })
      socket.emit('newPlayer', {room: 'the_1113335', name: 'testo'})
    })

    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK Start  a game', done => {
      socket.on('action', (res) => {
        assert.equal(res.type, 'START_GAME')
        assert.equal(res.data.room, 'the_1113335')
        assert.equal(res.data.isOver, false)
        assert.equal(res.message, 'Game successfully started')
        done()
      })
      socket.emit('startGame', {game_id})
    })
  })

  describe('Socket: Next turn', () => {
    let game_id
    let player_id
    let spectre
    beforeEach(done => {
      socket.on('action', (res) => {
        if(res.type === 'NEW_PLAYER') {
        game_id = res.data.id
        player_id = res.data.players[0]._id
        spectre = res.data.players[0].spectre
        done()
        }
      })
      socket.emit('newPlayer', {room: 'the_1113344', name: 'testo'})
    })

    after((done) => {
        if(socket.connected) socket.disconnect()
        done()
    })
    it ('should be OK give malus', done => {
      socket.on('action', (res) => {
        assert.equal(res.type, 'NEXT_TURN')
        assert.equal(res.data.updatedGame.isOver, false )
        done()
      })
      socket.emit('nextTurn', {player_id, game_id, spectre})
    })
  })

})
