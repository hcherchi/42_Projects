import _ from 'lodash'
import { fromJS } from 'immutable'

const isGameLost = (board) => {
  try {
    const line = board.get(0)
    line.forEach(bloc => {
      if (bloc && bloc.get('color') != 'white') throw true
    })
    return false
  }
  catch (e) {
    return e
  }
}

const isPossible = (board, shape, posX, posY) => {

  try {
    shape.forEach((line, y) => {
      line.forEach((bloc, x) => {
        const newY = y + posY
        const newX = x + posX
        let onBoard = true
        let free = true

        if (newY >= 21 || newX < 0 || newX >= 10) onBoard = false
        if (onBoard && newY >= 0 && board  && board.getIn([newY, newX, 'color']) !== 'white') free = false

        if (shape[y][x] == 1 && (!onBoard || !free)) throw null
      })
    })
    return true
  }

  catch (e) {
    return false
  }
}

function newLine() {
  let tab_tmp = []
  for(let d = 0; d < 10; d++) {
    tab_tmp.push({color: 'white'})
  }
  return tab_tmp
}


const lineDestroyer = (board, giveMalus, player_id, game_id) => {
  try {
    const newTab = board.toJS()
    let toRet = []
    newTab.forEach((line, x) => {
      let checker = 0
      line.forEach((bloc, y) => {
        if (bloc.color !== 'white' && bloc.color !== 'black') { checker++ }
      })
      if (checker === 10) {
        toRet.push(x)
      }
    })
    if (toRet.length > 1) giveMalus({ player_id, game_id, malus: toRet.length - 1 })
    if (toRet.length != 0) {
      for (let d = 0; d < toRet.length; d++) {
        newTab.splice(toRet[d],1)
        newTab.unshift(newLine())
      }
      return newTab
    } else {
      return false
    }
  } catch (e) {
    console.log('err',e);
  }
}

const isPiece = (i, j, shape, posX, posY) => {
  const x = i - posX
  const y = j - posY
  if (x < 0 || x >= shape.length || y < 0 || y >= shape.length) return false
  if (shape[y][x] === 1) return true
  else return false
}

const rotate = (shape) => {
  const newShape = []
  shape.forEach((line, i) => {
    line.forEach((bloc, j) => {
      if (!newShape[j]) newShape[j] = []
      newShape[j][line.length - i - 1] = shape[i][j]
    })
  })
  return newShape
}

const pieceToBoard = (board, shape, posX, posY, color) => {
  try {
    const test = board.toJS()
    board.forEach((line, j) => {
          line.forEach((bloc, i) => {
            if (isPiece(i, j, shape, posX, posY) && (i >= 0 && i < 10 && j >= 0 && j < 21)) {
              test[j][i].color = color
            }
          })
        })
    return test
  }

  catch (e) {
    console.log(e)
    return false
  }
}
const updateSpectre = (newBoard, spectre) => {
  try {
    spectre.forEach((s,e) => spectre[e] = 21)
    newBoard.forEach((line, j) => {
      let test_tmp = []
      line.forEach((bloc, i) => {
        if (bloc.color != 'white') {
          spectre[i] = Math.min(spectre[i], j)
      }
    })
  })
    return spectre
  }
  catch (e) {
    console.log(e)
    return false
  }
}

module.exports = {
  updateSpectre,
  pieceToBoard,
  rotate,
  lineDestroyer,
  isPiece,
  isPossible,
  isGameLost,
}
