import React from 'react'
import { connect } from 'react-redux'
import { provideHooks } from 'redial'
import tetriMove  from '../../actions/tetriMove.js'
import tetriRotate  from '../../actions/tetriRotate.js'
import nextTurn from '../../actions/nextTurn.js'
import moveLine from '../../actions/moveLine.js'
import disactivation from '../../actions/disactivation'
import activation from '../../actions/activation'
import posePiece from '../../actions/posePiece'
import restartGame from '../../actions/restartGame'
import loseGame from '../../actions/loseGame'
import giveMalus from '../../actions/giveMalus'
import clearMessage from '../../actions/clearMessage'


import { types, isPossible, lineDestroyer, isPiece, rotate, pieceToBoard, updateSpectre, isGameLost} from '../../helper'


import startInterval from '../../actions/startInterval.js'

import functional from 'react-functional'

import { is } from 'immutable'

import './style.scss'

const moveDown = (props) => {
  const {
    board,
    shape,
    posX,
    posY,
    curPiece,
    tetriMove,
    nextTurn,
    posePiece,
    color,
    game_id,
    player_id,
    spectre,
  } = props

  if (isPossible(board, shape, posX, posY + 1)) tetriMove({ posX, posY: posY + 1, curPiece })

  else {
    const newBoard = pieceToBoard(board, shape, posX, posY, color)
    posePiece(newBoard)
    nextTurn({
      game_id,
      player_id,
      spectre: updateSpectre(newBoard, spectre),
    })
  }
}
const moveForce = (props) => {
  const {
    board,
    shape,
    posX,
    posY,
    curPiece,
    tetriMove,
    nextTurn,
    posePiece,
    color,
    game_id,
    player_id,
    spectre,
  } = props

  let k = 1
  if (posY >= 0) {
  for (let j = 0; j <= 19; j++)  if (isPossible(board, shape, posX,  k + 1)) k++
  tetriMove({ posX, posY: k, curPiece })
    const newBoard = pieceToBoard(board, shape, posX, k, color)
    posePiece(newBoard)
    nextTurn({
      game_id,
      player_id,
      spectre: updateSpectre(newBoard, spectre),
    })
  }
}

const moveLeft = (props) => {
  const {
    board,
    shape,
    posX,
    posY,
    curPiece,
    tetriMove,
  } = props

  if (isPossible(board, shape, posX - 1, posY)) tetriMove({ posX: posX - 1, posY, curPiece })
}

const moveRight = (props) => {
  const {
    board,
    shape,
    posX,
    posY,
    curPiece,
    tetriMove,
  } = props

  if (isPossible(board, shape, posX + 1, posY)) tetriMove({ posX: posX + 1, posY, curPiece })
}

const moveRotate = (props) => {
  const {
    board,
    shape,
    posX,
    posY,
    curPiece,
    tetriRotate,
  } = props

  const newShape = rotate(shape)

  if (isPossible(board, newShape, posX, posY)) tetriRotate({ shape: newShape, curPiece })
}

const boardGame = (props) => {

  const {
    posX,
    posY,
    board,
    restartGame,
    shape,
    color,
    players,
    looser,
    winner,
    isOver,
    isVisitor,
    game_id,
    message,
    nextPiece,
    nextPieceColor,
  } = props

  const onKey = (e) => {
    if (e.keyCode === 38) moveRotate(props)
    if (e.keyCode === 39) moveRight(props)
    if (e.keyCode === 37) moveLeft(props)
    if (e.keyCode === 40) moveDown(props)
    if (e.keyCode === 32) moveForce(props)
  }
  return (
    <div className='game'>
      <div className='space'>
        { nextPiece && (
          <div className='board'>
            {
              nextPiece.map((line, j) => {
                return (
                  <div key={j} className='line'>
                    { line.map((bloc, i) => (<div key={`${i} ${j}`} className={`sbloc ${bloc ? nextPieceColor : 'white'}`} />)) }
                  </div>
                )
              })
            }
          </div>
        )}
      </div>
      <div className='board' id="inner" tabIndex="-1" onBlur={() => document.getElementById('inner').focus()} onKeyDown={isOver ? '' : (e) => onKey(e)}>
        {
          board.map((line, j) => {
            return (j === 0) ? ('') : (
              <div key={j} className={`line ${(looser || winner) ? ' blur' : ''}`}>
              {
                line.map((bloc, i) => {
                  if (isPiece(i, j, shape, posX, posY)) {
                    return (<div key={`${i} ${j}`} className={`bloc ${color}`} />)
                  } else {
                    return (<div key={`${i} ${j}`} className={`bloc ${bloc.get('color')}`} />)
                  }
                })
              }
              </div>
            )}
        )}
        { (looser || winner) && (
          <h1 className='message'>{winner ? 'WINNER' : 'LOOSER'}</h1>
        )
      }
      </div>
      <div className='space'>
        { !isOver && message && (<p>{message}</p>) }
        { isOver && !isVisitor && (<button onClick={() => restartGame({ game_id })} ><p>Play again</p></button>) }
      </div>
    </div>
  )
}
/* istanbul ignore next */
 function  mapStateToProps(state) {
  const players = state.game.getIn(['room', 'players'])
  const pieces = state.game.getIn(['room','pieces'])
  const game_id = state.game.getIn(['room', 'id'])

  const isOver = state.game.getIn(['room', 'isOver'])

  const currentPlayerIndex = players.findIndex(player => player.get('name') === state.game.getIn(['info', 'name']))
  const currentPlayer = players.find(player => player.get('name') === state.game.getIn(['info', 'name']))
  const isVisitor = currentPlayer.get('isVisitor')
  const looser = currentPlayer.get('looser')
  const winner = currentPlayer.get('winner')

  const curPiece = currentPlayer.get('curPiece')
  const nextPiece = pieces.getIn([curPiece + 1, 'shape'])
  const nextPieceColor = pieces.getIn([curPiece + 1, 'color'])
  const player_id = currentPlayer.get('_id')
  const spectre = currentPlayer.get('spectre').toJS()
  const currentPiece = state.game.getIn(['currentPiece'])

  const posX = currentPiece.get('positionX')
  const posY = currentPiece.get('positionY')
  const color = currentPiece.get('color')
  const shape = currentPiece.get('shape').toJS()

  const board = state.game.getIn(['board'])
  const hasToFall = state.game.get('hasToFall')
  const interval = state.game.get('interval')
  const message = state.game.get('message')

  return {
    isOver,
    looser,
    winner,
    isVisitor,
    currentPlayerIndex,
    currentPlayer,
    curPiece,
    board,
    posX,
    posY,
    nextPiece,
    player_id,
    game_id,
    spectre,
    currentPiece,
    color,
    shape,
    hasToFall,
    interval,
    players,
    spectre,
    message,
    nextPieceColor,
  }
}

function mapDispatchToProps(dispatch) {
  return {
    tetriMove: (data) => dispatch(tetriMove(data)),
    tetriRotate: (data) => dispatch(tetriRotate(data)),
    nextTurn: (data) => dispatch(nextTurn(data)),
    moveLine: (data) => dispatch(moveLine(data)),
    posePiece: (data) => dispatch(posePiece(data)),
    activation: () => dispatch(activation()),
    disactivation: () => dispatch(disactivation()),
    startInterval: (data) => dispatch(startInterval(data)),
    restartGame: (data) => dispatch(restartGame(data)),
    loseGame: (data) => dispatch(loseGame(data)),
    giveMalus: (data) => dispatch(giveMalus(data)),
    clearMessage: () => dispatch(clearMessage()),
  }
}

boardGame.componentDidMount = (props, refs) => {
  const {
    startInterval,
    activation,
  } = props
  document.getElementById('inner').focus()
  startInterval(setInterval(() => activation(), 1000))
}

boardGame.componentWillUnmount = (props, refs) => {
  const {
    interval,
  } = props

  clearInterval(interval)
}

boardGame.componentDidUpdate = (props, refs) => {
  const {
    interval,
    board,
    winner,
    looser,
    moveLine,
    hasToFall,
    disactivation,
    loseGame,
    player_id,
    game_id,
    giveMalus,
    clearMessage,
    message,
  } = props

  if (message && !is(message, refs.message)) setTimeout(() => clearMessage(), 5000)

  if (!is(looser, refs.looser) || !is(winner, refs.winner)) clearInterval(interval)


  if (!is(board, refs.board)) {
    if (isGameLost(board)) loseGame({ player_id, game_id })
    const lineToDestroy = lineDestroyer(board, giveMalus, player_id, game_id)
    if (lineToDestroy) moveLine(lineToDestroy)
  }

  if (hasToFall) {
     moveDown(props)
     disactivation()
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(functional(boardGame))
