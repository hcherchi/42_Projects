package main
import (
	//"fmt"
)

// Check if the line contains at least one eatable pion
func isUnbreakableLine(i int, j int, x int, y int, board *[SIZE][SIZE]int) bool {
  var count = 0

  for count < 5 {
    if (isEatable(x + count * i, y + count * j, board)) {
      return false
    }
    count++
  }
  return true
}

// Check if the pion is eatable
func isEatable(x int, y int, board *[SIZE][SIZE]int) bool {
  var pion = board[x][y]
  var pion2 = 0

  if (pion == 0) {
    return false
  } else if (pion == 1) {
    pion2 = 2
  } else {
    pion2 = 1
  }

  var i = -1
  var j = -1

  for i <= 1 {
    j = -1
    for j <= 1 {
      if (x + i * -1 >= 0 && x + i * -1 < SIZE && y + j * -1 < SIZE && y + j * -1 >= 0 && x + i * 2 >= 0 && x + i * 2 < SIZE && y + j * 2 >= 0 && y + j * 2 < SIZE && board[x + i * -1][y + j * -1] == 0 && board[x + i][y + j] == pion && board[x + i * 2][y + j * 2] == pion2) {
        return true
      }
      if (x + i * -2 >= 0 && x + i * -2 < SIZE && y + j * -2 < SIZE && y + j * -2 >= 0 && x + i * 1 >= 0 && x + i * 1 < SIZE && y + j * 1 >= 0 && y + j * 1 < SIZE && board[x + i * -1][y + j * -1] == pion && board[x + i][y + j] == pion2 && board[x + i * -2][y + j * -2] == 0) {
        return true
      }
      j++
    }
    i++
  }
  return false
}

// check if the move is playable
func isPlayable(game *Game, x int, y int) bool {
  if (x >= SIZE || y >= SIZE || x < 0 || y < 0 || game.board[x][y] != 0) {
    return false
  }
  if (isForbidenMove(game, x, y)) {
    return false
  }
  return true
}


// Check if the move is forbidden or not
func isForbidenMove(game *Game, x int, y int) bool {
  var pion2 int
  var pion int

  if (game.curPlayer == PLAYER1) {
    pion = 1
    pion2 = 2
  } else {
    pion = 2
    pion2 = 1
  }

  var count = 0
  var count2 = 0
  var i = -1
  var j = -1

  for i <= 1 {
    j = -1
    for j <= 1 {
      if (x + i * -1 >= 0 && x + i * -1 < SIZE && y + j * -1 < SIZE && y + j * -1 >= 0 && x + i * 3 >= 0 && x + i * 3 < SIZE && y + j * 3 >= 0 && y + j * 3 < SIZE && game.board[x + i * -1][y + j * -1] != pion2 && game.board[x + i][y + j] == pion && game.board[x + i * 2][y + j * 2] == pion && game.board[x + i * 3][y + j * 3] != pion2) {
        if (x + i * -2 >= 0 && x + i * -2 < SIZE && y + j * -2 < SIZE && y + j * -2 >= 0 && game.board[x + i * -2][y + j * -2] == pion && game.board[x + i * -1][y + j * -1] == pion) {
          count--
        }
        count++
      }
      if (x + i * -1 >= 0 && x + i * -1 < SIZE && y + j * -1 < SIZE && y + j * -1 >= 0 && x + i * 4 >= 0 && x + i * 4 < SIZE && y + j * 4 >= 0 && y + j * 4 < SIZE && game.board[x + i * -1][y + j * -1] != pion2 && game.board[x + i][y + j] == 0 && game.board[x + i * 2][y + j * 2] == pion && game.board[x + i * 3][y + j * 3] == pion && game.board[x + i * 4][y + j * 4] != pion2) {
        count2++
      }
      j++
    }
    i++
  }
  if (count >= 2) {
    return true
  } else if (count >= 1 && count2 >= 1) {
    return true
  }
  return false
}
