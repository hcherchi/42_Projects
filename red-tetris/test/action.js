import React from 'react'
import chai from "chai"
import {fromJS} from 'immutable'
import _ from 'lodash'
import Spectre from '../src/client/components/spectre'
import ServerPage from '../src/client/components/serverPage'

import activation from '../src/client/actions/activation'
import clearMessage from '../src/client/actions/clearMessage'
import disactivation from '../src/client/actions/disactivation'
import disconnect from '../src/client/actions/disconnect'
import getGames from '../src/client/actions/getGames'
import giveMalus from '../src/client/actions/giveMalus'
import loseGame from '../src/client/actions/loseGame'
import moveLine from '../src/client/actions/moveLine'
import newPlayer from '../src/client/actions/newPlayer'
import nextTurn from '../src/client/actions/nextTurn'


import openModal from '../src/client/actions/openModal'
import posePiece from '../src/client/actions/posePiece'
import restartGame from '../src/client/actions/restartGame'
import startGame from '../src/client/actions/startGame'
import startInterval from '../src/client/actions/startInterval'
import tetriMove from '../src/client/actions/tetriMove'
import tetriRotate from '../src/client/actions/tetriRotate'


import ReactTestUtils from 'react-addons-test-utils'
const assert = require('chai').assert
const expect = chai.expect
const should = chai.should()

describe('Components', () => {

  describe('Acion', () => {
        it ('should be true when actions is test', done => {
          const lol = activation()
          assert.equal(true,_.isEqual(lol, {type: 'client/activation'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = clearMessage()
          assert.equal(true,_.isEqual(lol, {type: 'client/clearMessage'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = disactivation()
          assert.equal(true,_.isEqual(lol, {type: 'client/disactivation'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = disconnect('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/disconnect', data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = getGames('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/getGames',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = giveMalus('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/giveMalus',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = loseGame('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/loseGame',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = moveLine('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/moveLine',data: 'test'}))
          done()
        })

        it ('should be true when actions is test', done => {
          const lol = newPlayer('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/newPlayer',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = nextTurn('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/nextTurn',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = openModal('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/openModal',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = posePiece('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/posePiece',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = restartGame('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/restartGame',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = startGame('test')
          assert.equal(true,_.isEqual(lol, {type: 'server/startGame',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = startInterval('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/startInterval',data: 'test'}))
          done()
        })

        it ('should be true when actions is test', done => {
          const lol = tetriMove('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/tetriMove',data: 'test'}))
          done()
        })
        it ('should be true when actions is test', done => {
          const lol = tetriRotate('test')
          assert.equal(true,_.isEqual(lol, {type: 'client/tetriRotate',data: 'test'}))
          done()
        })
  })
})
