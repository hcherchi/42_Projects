package main
import (
  //"math"
)

const EATABLE_MALUS = 10
const SCORE_BONUS = 1
const FREE_FOUR_BONUS = 50
const FULL_FREE_BONUS = 20
const LINE_BONUS = 5
const SPACE_BONUS = 2
const COEF_FREE = 1
const COEF_FRIEND = 3

// Evaluate a grid
func evaluate(game *Game) Move {
  var res int = 0
  var i int = 0
  var j int = 0

  for i < game.score[game.friend - 1] {
    res += SCORE_BONUS
    i++
  }
  i = 0
  for i < game.score[game.friend % 2] {
    res -= SCORE_BONUS
    i++
  }
  i = 0
  for i < SIZE {
    j = 0
    for j < SIZE {
      if (game.board[i][j] == game.friend) {
        res += evaluateEach(&game.board, i, j)
      } else if (game.board[i][j] == game.friend % 2 + 1) {
        res -= evaluateEach(&game.board, i, j)
      }
      j++
    }
    i++
  }
  return (newMove(0, 0, res))
}

// Evaluate a Pion
func evaluateEach(board *[SIZE][SIZE]int, x int, y int) int {
  var i int = -1
  var j int = -1
  var k int = 1
  var player = board[x][y]
  var res int = 0
  var countFree int = 0
  var countLine int = 0
  var countFriend int = 0
  var limit bool = false

  if (isEatable(x, y, board)) {
    res -= EATABLE_MALUS
  }

  for i <= 1 {
    j = -1
    for j <= 1 {

      countFree = 0
      countFriend = 0
      countLine = 0
      limit = false

      k = -1
      for (k >= -4 && x + i * k >= 0 && x + i * k < SIZE && y + j * k >= 0 && y + j * k < SIZE && (*board)[x + i * k][y + j * k] != player % 2 + 1) {

        if ((*board)[x + i * k][y + j * k] == player && !limit) {
          countLine++
        } else if ((*board)[x + i * k][y + j * k] == NONE && !limit) {
          limit = true
        }

        if ((*board)[x + i * k][y + j * k] == player) {
          countFriend++
        } else {
          countFree++
        }

        k--
      }

      k = 1
      for (k <= 4 && x + i * k >= 0 && x + i * k < SIZE && y + j * k >= 0 && y + j * k < SIZE && (*board)[x + i * k][y + j * k] != player % 2 + 1) {

        if ((*board)[x + i * k][y + j * k] == player && !limit) {
          countLine++
        } else if ((*board)[x + i * k][y + j * k] == NONE && !limit) {
          limit = true
        }

        if ((*board)[x + i * k][y + j * k] == player) {
          countFriend++
        } else {
          countFree++
        }

        k++
      }


      if (countFree + countFriend >= 4) {

        res += SPACE_BONUS * (countFree * COEF_FREE + countFriend * COEF_FRIEND)
        res += LINE_BONUS * countLine
        if (countFree + countFriend >= 6 && countLine >= 3) {
          res += FREE_FOUR_BONUS
        }
        if (countFree + countFriend >= 8) {
          res += FULL_FREE_BONUS
        }

      }


      j++
    }
    i++
  }

  return res
}
