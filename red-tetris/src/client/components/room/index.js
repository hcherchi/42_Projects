import React from 'react'
import { connect } from 'react-redux'
import _ from 'lodash'
import startGame from '../../actions/startGame'

import './style.scss'

const Room = (props) => {

  const {
    room,
    info,
    players,
    startGame
  } = props
  const currentPlayer = players.find(player => player.getIn(['name']) == info.getIn(['name']))
  const number = players.size
  const disabled = currentPlayer.getIn(['isVisitor'])

  return (
    <div className='room'>

      <button onClick={disabled ? '' : () => startGame({ game_id: room.getIn(['id']) })} className={disabled ? 'disabled' : ''}>
        <i className='ion-play' style={{ fontSize: '6vh' }} />
        <p>Start Game<br />{number}/5</p>
      </button>

    </div>
  )
}
/* istanbul ignore next */
const mapStateToProps = (state) => {
  return {
    room: state.game.getIn(['room']),
    info: state.game.getIn(['info']),
    players: state.game.getIn(['room', 'players']),
  }
}


const mapDispatchToProps = (dispatch) => {
  return {
    startGame: (data) => dispatch(startGame(data))
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(Room)
