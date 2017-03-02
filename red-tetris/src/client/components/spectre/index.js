import React from 'react'
import { connect } from 'react-redux'
import { provideHooks } from 'redial'

import startInterval from '../../actions/startInterval.js'

import functional from 'react-functional'

import './style.scss'


const spectreGame = (props) => {

  const {
    player,
    board,
  } = props

  const spectre = player.get('spectre')
  const name = player.get('name')
  const winner = player.get('winner')
  const looser = player.get('looser')

  return (
    <div className='spectre'>
      <p className='name'>{name}</p>
      {
        board.map((line, j) => {
          return (j === 0) ? ('') : (
            <div key={j} className={`Sline ${(looser || winner) ? ' blur' : ''}`}>
            {
              spectre.map((s, i) => {
                if(s <= j) {
                  return(<div key={`${i} ${j}`} className={`Sbloc gold`} />)
                } else {
                  return (<div key={`${i} ${j}`} className={`Sbloc white`} />)
                }
              })
            }
            </div>
          )
        })
      }
      { (looser || winner) && (
        <h1 className='Smessage'>{winner ? 'WINNER' : 'LOOSER'}</h1>
      )}
    </div>
  )
}

export default spectreGame
