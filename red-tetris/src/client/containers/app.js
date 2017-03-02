import React from 'react'
import { connect } from 'react-redux'

import BoardGame from '../components/boardGame'
import Room from '../components/room'
import Spectre from '../components/spectre'
import ServerPage from '../components/serverPage'
import newPlayer from '../actions/newPlayer'

import './style.scss'

const App = (props) => {


  const {
    room,
    info,
    newPlayer,
    error,
    otherPlayers,
    board,
    router,
  } = props
  const data = info && { name: info.getIn(['name']), room: info.getIn(['room']) }

  const errorCondition = (error || !data)
  const connectionCondition = !errorCondition && !room
  const roomCondition = !errorCondition && room && !room.getIn(['isStarted'])
  const gameCondition = !errorCondition && room && room.getIn(['isStarted'])

  const errorMessage = error ? error : 'The URL is invalid, please use: #<room>[<player_name>]'

  return (
    <div className='container'>

      <header>
        <h1> <a href="http://localhost:8080/">{'Red.Tetris'}</a></h1>
      </header>

      <div className='content'>
        <div className='center'>
          {errorCondition &&
            <div className='error'>
                <p>{errorMessage}</p>
            </div>
          }
          {!roomCondition && !gameCondition &&
            <ServerPage
            router={router}
            />
          }
        </div>

        {otherPlayers && (
          <div className='spectre--container'>
            {otherPlayers.size >= 1 && (<Spectre player={otherPlayers.get(0)} board={board}/>)}
            {otherPlayers.size >= 2 && (<Spectre player={otherPlayers.get(1)} board={board}/>)}
          </div>
        )}

        {roomCondition && <Room />}
        {gameCondition && <BoardGame />}

        {otherPlayers && (
          <div className='spectre--container'>
            {otherPlayers.size >= 3 && (<Spectre player={otherPlayers.get(2)} board={board}/>)}
            {otherPlayers.size >= 4 && (<Spectre player={otherPlayers.get(3)} board={board}/>)}
          </div>
        )}

      </div>

      <footer>
        <h1>{'Swag'}</h1>
      </footer>

    </div>
  )
}
/* istanbul ignore next */
const mapStateToProps = (state) => {
  const info = state.game.getIn(['info'])
  const error = state.game.getIn(['error'])
  const room = state.game.getIn(['room'])
  const players = room && room.get('players')
  const otherPlayers = players && players.filter(player => player.get('name') != info.get('name'))
  const board = state.game.getIn(['board'])
  return {
    room,
    info,
    error,
    otherPlayers,
    board,
  }
}

const mapDispatchToProps = (dispatch) => {
  return {
    newPlayer: (data) => dispatch(newPlayer(data))
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(App)
