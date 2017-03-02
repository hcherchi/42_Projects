import { fromJS } from 'immutable'
import _ from 'lodash'

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

const newLine = (color) => {
  const line = []
  for (let i = 0; i < 10; i++) line.push({ color })
  return line
}

const putMalusToBoard = (board, malus) => {
  let i = 0
  while (i < malus) {
    board.push(newLine('black'))
    board.shift()
    i++
  }
  return fromJS(board)
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

const reducer = (state = fromJS(intialState) , action) => {
  switch(action.type) {
    case 'NEW_PLAYER':
      return state.setIn(['room'], fromJS(action.data))
    case 'START_GAME':
      return state.setIn(['room'], fromJS(action.data)).setIn(['currentPiece'], state.getIn(['room', 'pieces', 0]))
    case 'RESTART_GAME':
      return state.setIn(['room'], fromJS(action.data)).setIn(['board'], fromJS(creatTab()))
    case 'GET_GAMES':
      return state.setIn(['games'],fromJS(action.data))
    case 'NEXT_TURN':
      if (state.getIn(['info', 'name']) !== action.data.name) {
        return state.setIn(['room'], fromJS(action.data.updatedGame)).setIn(['hasToWait'], false)
      } else {
        const players = action.data.updatedGame.players
        const currentPlayer = players.find(player => player.name == action.data.name)
        const currentIndexPiece = currentPlayer.curPiece
        const piece = action.data.updatedGame.pieces[currentIndexPiece]

        return state.setIn(['room'], fromJS(action.data.updatedGame)).setIn(['hasToWait'], false).setIn(['currentPiece'], fromJS(piece))
      }
    case 'DISCONNECTED':
      return state.setIn(['room'], fromJS(action.data))
    case 'LOSE_GAME':
      return state.setIn(['room'], fromJS(action.data))
    case 'GIVE_MALUS':
      return state.setIn(['room'], fromJS(action.data.game)).setIn(['board'], putMalusToBoard(state.get('board').toJS(), action.data.malus)).setIn(['message'], action.data.message)
    case 'ERROR':
      return state.setIn(['error'], fromJS(action.data))
    case 'client/openModal':
      return state.setIn(['modal'],fromJS(action.data.modal)).setIn(['currentRoom'],fromJS(action.data.currentRoom))
    case 'client/posePiece':
      return state.setIn(['board'],fromJS(action.data))
    case 'client/moveLine':
       return state.setIn(['board'],fromJS(action.data))
    case 'client/disactivation':
      return state.setIn(['hasToFall'], false)
    case 'client/activation':
      return state.setIn(['hasToFall'], true)
    case 'client/startInterval':
      return state.setIn(['interval'], fromJS(action.data))
    case 'server/newPlayer':
      return state.setIn(['info'], fromJS(action.data)).setIn(['room'], null).setIn(['error'], null).setIn(['board'], fromJS(creatTab()))
    case 'client/tetriMove':
      return state.setIn(['currentPiece', 'positionX'], action.data.posX).setIn(['currentPiece' , 'positionY'], action.data.posY)
    case 'client/tetriRotate':
      return state.setIn(['currentPiece', 'shape'], fromJS(action.data.shape))
    case 'client/clearMessage':
      return state.setIn(['message'], null)
    default:
      return state
  }
}

export default reducer
