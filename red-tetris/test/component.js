import React from 'react'
import chai from "chai"
import {fromJS} from 'immutable'
import _ from 'lodash'
import Spectre from '../src/client/components/spectre'
import ServerPage  from '../src/client/components/serverPage'
import BoardGame  from '../src/client/components/boardGame'
import Room from '../src/client/components/room'
import  App from '../src/client/containers/app'
import actions from '../src/client/actions/activation'
import ReactTestUtils from 'react-addons-test-utils'
import socketIoMiddleWare from '../src/client/middleware/socketIoMiddleWare'
import io from 'socket.io-client'
const assert = require('chai').assert
const expect = chai.expect
const should = chai.should()

const initialState = {}
const socket = io('localhost:5000')


const state = {
  player: fromJS({
    spectre: [2,0,0,2,0, 10, 15, 14],
    name: 'test',
    winner: 'false',
    looser: 'false',
  }),
board:fromJS( [
    [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
    [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
    [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
    [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
    [{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'},{color: 'white'}, {color: 'white'}],
    [{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'red'},{color: 'red'}, {color: 'white'}],
  ]),
  games: fromJS([{
    players: ['ooo','ooo'],
    room: 'test',
    isStarted: false,
  }]),
  games1: fromJS([{
    players: ['ooo','ooo'],
    room: 'test',
    isStarted: true,
  }]),
  games2: fromJS([{
    players: ['ooo','ooo'],
    room: 'teoooooooooooooooooooooooooooooot',
    isStarted: true,
  }]),
  players: fromJS([{
    spectre: [2,0,0,2,0, 10, 15, 14],
    name: 'test',
    winner: 'false',
    looser: 'false',
    name: 'test',
    isVisitor: false,
  }]),
  players1: fromJS([{
    spectre: [2,0,0,2,0, 10, 15, 14],
    name: 'test',
    winner: 'false',
    looser: 'false',
    name: 'test',
    isVisitor: true,
  }]),
}
describe('Components', () => {

  describe('Spectre', () => {

        it ('should be a div after render', done => {
          const renderer = ReactTestUtils.createRenderer();
          renderer.render(<Spectre
            player={state.player}
            board={state.board}/>);
          const result = renderer.getRenderOutput();
          assert.equal(result.type,'div')
          done()
        })

  })
  describe('middleware', () => {

        it ('should be a div after render', done => {
          const lol = socketIoMiddleWare(socket)
          const test = lol(socket)
          const test2 = test(socket)
          done()
        })

  })

  describe('ServerPage', () => {

        it ('should be a div after render', done => {
          const test = {
            router: null,
            getGames: null,
            openModal: null,
            currentRoom: null,
            games: state.games,
            modal: true,
          }
          const lol = ServerPage.WrappedComponent(test)
           assert.equal(lol.type,'div')
          done()
        })
        it ('should be a div after render', done => {
          const test = {
            router: null,
            getGames: null,
            openModal: null,
            currentRoom: null,
            games: null,
            modal: false,
          }
          const lol = ServerPage.WrappedComponent(test)
           assert.equal(lol.type,'div')
          done()
        })

        it ('should be a div after render', done => {
          const test = {
            router: null,
            getGames: null,
            openModal: null,
            currentRoom: null,
            games: state.games1,
            modal: true,
          }
          const lol = ServerPage.WrappedComponent(test)
           assert.equal(lol.type,'div')
          done()
        })

        it ('should be a div after render', done => {
          const test = {
            router: null,
            getGames: null,
            openModal: null,
            currentRoom: null,
            games: state.games2,
            modal: true,
          }
          const lol = ServerPage.WrappedComponent(test)
           assert.equal(lol.type,'div')
          done()
        })

  })

    // describe('BoardGame', () => {
    //
    //       it ('should be a div after render', done => {
    //         const test = {
    //           posY: 1,
    //           posX: 1,
    //           board: state.board,
    //           restartGame: null,
    //           shape: [2, 2, 2, 2, 2, 2, 2,],
    //           color: 'red',
    //           looser: true,
    //           winner: true,
    //           isOver: true,
    //           isVisitor: true,
    //           game_id: '234234',
    //           message: 'salut',
    //         }
    //         console.log(BoardGame);
    //         const lol = BoardGame.WrappedComponent(test)
    //          assert.equal(lol.type,'div')
    //         done()
    //       })
    // })

    describe('App', () => {

          it ('should be a div after render', done => {
            const test = {
              room: null,
              info: fromJS({name: 'heee', room: 'oeuoeu'}),
              newPlayer: null,
              error: 'heteheh',
              otherPlayers: null,
              board: state.board,
              router: null,
            }
            const lol = App.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })

          it ('should be a div after render', done => {
            const test = {
              room: null,
              info: fromJS({name: 'heee', room: 'oeuoeu'}),
              newPlayer: null,
              error: null,
              otherPlayers: null,
              board: state.board,
              router: null,
            }
            const lol = App.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })

          it ('should be a div after render', done => {
            const test = {
              room: fromJS(),
              info: fromJS({name: 'heee', room: 'oeuoeu'}),
              newPlayer: null,
              error: null,
              otherPlayers: null,
              board: state.board,
              router: null,
            }
            const lol = App.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })

          it ('should be a div after render', done => {
            const test = {
              room: fromJS({isStarted: true}),
              info: fromJS({name: 'heee', room: 'oeuoeu'}),
              newPlayer: null,
              error: null,
              otherPlayers: null,
              board: state.board,
              router: null,
            }
            const lol = App.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })

          it ('should be a div after render', done => {
            const test = {
              room: fromJS({isStarted: false}),
              info: fromJS({name: 'heee', room: 'oeuoeu'}),
              newPlayer: null,
              error: null,
              otherPlayers: null,
              board: state.board,
              router: null,
            }
            const lol = App.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })
    })

    describe('Room', () => {

          it ('should be a div after render', done => {
            const test = {
              room: fromJS({isStarted: false}),
              info: fromJS({name: 'test', room: 'oeuoeu'}),
              players: state.players,
            }
            const lol = Room.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })
          it ('should be a div after render', done => {
            const test = {
              room: fromJS({isStarted: false}),
              info: fromJS({name: 'test', room: 'oeuoeu'}),
              players: state.players1,
            }
            const lol = Room.WrappedComponent(test)
             assert.equal(lol.type,'div')
            done()
          })
        })

})
