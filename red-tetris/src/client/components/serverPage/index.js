import React from 'react'
import Modal from 'react-modal'
import { connect } from 'react-redux'
import _ from 'lodash'
import getGames from '../../actions/getGames'
import openModal from '../../actions/openModal'

import './style.scss'

const customStyles =
{
  content : {
    top                   : '50%',
    left                  : '50%',
    right                 : 'auto',
    bottom                : 'auto',
    background            : '',
    border                : '',
    transform             : 'translate(-50%, -50%)'
  }
}

const ServerPage = (state) => {

  const {
  router,
  getGames,
  openModal,
  currentRoom,
  games,
  modal,
  } = state

  return (
  <div className='room'>

    <button className='indexServer' onClick={(e) => getGames()}>
      join a room
    </button>
    <Modal
      isOpen={modal}
      style={customStyles}
      onRequestClose={() => openModal({modal: !modal, currentRoom: null})}
      contentLabel="Name Modal"
      >
      <form className='formModal' onSubmit={(e) => {
        e.preventDefault()
        const Name = document.getElementById('Name').value
        const curr = currentRoom
        openModal({modal: !modal, currentRoom: null})
        router.router.push(`#${curr}[${Name}]`)

        }}>
          <input className='inputText' type='text' id='Name' placeholder='Name'/>
        <input className='input' type='submit' value='GO' />
      </form>
    </Modal>
    <div className='server'>
      {games && (
        games.map((p, i) => {
          const players = p.get('players').toJS()
          let str = p.get('room')
          if (str.length >= 10) {
            str = str.slice(0, 10) + '...'
          }
          if(!p.get('isStarted')) {

            return(
            <button className='notStarted'
              key={i}
              onClick={(e)  =>  openModal({modal: !modal, currentRoom: p.get('room')})}>
              <p>{str}</p>
              <p>{`${players.length}/5`} </p>
            </button>
            )
           }
           else {
             return(
      <button className='disabled asStarted'
      key={i}
      >
        <p>{str}</p>
        <p>{`${players.length}/5`} </p>
      </button>
      )
           }
        })
      )}
    </div>
    <p className='or'> or </p>
      <form className='form'onSubmit={(e) => {
        e.preventDefault()
        const hostName = document.getElementById('hostName').value
        const roomName = document.getElementById('roomName').value

        if (hostName !== '' && roomName !== '') { router.router.push(`#${roomName}[${hostName}]`) }
        }}>
        <legend className='legend'>Create your room </legend>
          <input className='inputText' type='text' id='hostName' placeholder='Host Name'/>
          <input className='inputText' type='text' id='roomName' placeholder='Room Name'/>
        <button className='input'type='submit'>
        GO
        </button>
      </form>
  </div>
  )
}
/* istanbul ignore next */
const mapStateToProps = (state, router) => {
  return {
    currentRoom: state.game.getIn(['currentRoom']),
    modal: state.game.getIn(['modal']),
    games: state.game.getIn(['games']),
    room: state.game.getIn(['room']),
    info: state.game.getIn(['info']),
    players: state.game.getIn(['room', 'players']),
    router,
  }
}


const mapDispatchToProps = (dispatch) => {
  return {
    openModal: (data) => dispatch(openModal(data)),
    getGames: (data) => dispatch(getGames(data))
  }
}

export default connect(mapStateToProps, mapDispatchToProps)(ServerPage)
