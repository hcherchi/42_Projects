package main
import (
	//"fmt"
)

// Move the Pion and eat (if needed), check if there is a winner, if the ligne is unbreakable and if the player did actually break it.
func simulateMove(game *Game, x int, y int) {
  otherPlayer := game.curPlayer % 2 + 1
  var prevLastChance *LastChance = game.lastChance
  game.lastChance = nil
  var i = -1
  var j = -1
  var k = -4
  var count = 0
  var countMax = 0
  var posi = -1
  var posj = -1

  // Iterate over all directions
  for i <= 1 {
    j = -1
    for j <= 1 {

      //TODO PUT THIS INSIDE ANOTHER FUNCTION : isLine(i int, j int, board *int[][]) bool, int, int {}
      // check 4 cases around if the pion contribute to make a line
      k = -4
      count = 0
      countMax = 0
      for k <= 4 {
        if (k == 0 || (x + i * k >= 0 && x + i * k < SIZE && y + j * k >= 0 && y + j * k < SIZE && game.board[x + i * k][y + j * k] == game.curPlayer)) {
          count++
          if (count == 5) {
            posi = x + i * k
            posj = y + j * k
          }
          countMax = count
        } else {
          count = 0
        }
        k++
      }
      ///////////////////////////////////////////////

      // If a line was made
      if (countMax >= 5) {
        // And unbreakable
        if (isUnbreakableLine(-i, -j, posi, posj, &game.board)) {
          // Player win
          game.winner = game.curPlayer
        } else {
          // Else we save the position of the line to check next turn if still there
          game.lastChance = newLastChance(game.curPlayer, -i, -j, posi, posj)
      	}
      }

      // Check if there are Pions to eat in this direction, eat them and increase score
      if (x + i * 3 >= 0 && x + i * 3 < SIZE && y + j * 3 >= 0 && y + j * 3 < SIZE && game.board[x + i][y + j] == otherPlayer && game.board[x + i * 2][y + j * 2] == otherPlayer && game.board[x + i * 3][y + j * 3] == game.curPlayer) {
        game.board[x + i][y + j] = 0
        game.board[x + i * 2][y + j * 2] = 0
        game.score[game.curPlayer - 1] += 2
      }
      j++
    }
    i++
  }

  // Put the Pion
  game.board[x][y] = game.curPlayer

  // Check if someone won with scores
  if (game.score[PLAYER2 - 1] == 10) {
		game.winner = PLAYER2
	} else if (game.score[PLAYER1 - 1] == 10) {
    game.winner = PLAYER1
  }

  // Check if the player was in "Last chance" and missed it
  if (prevLastChance != nil && stillStanding(prevLastChance, game)) {
    game.winner = prevLastChance.winner
  }

  // Change player
  game.curPlayer = game.curPlayer % 2 + 1

  // Change the player we need to use IA for (only if not in minimax algorythm)
  if (game.depth == 0) {
    game.friend = game.curPlayer
    moves := findMoves(game)
    if (len(moves) == 0) {
      if (game.winner == NONE && game.lastChance == nil) {
        game.winner = NUL
      } else if (game.lastChance != nil) {
        game.winner = game.lastChance.winner
      }
    }
  }
}

// Check if the line of last chance is still on the board
func stillStanding(lastChance *LastChance, game *Game) bool {
  var i int = 0

  for i < 5 {
    if (game.board[lastChance.x + lastChance.i * i][lastChance.y + lastChance.j * i] != lastChance.winner) {
      return false
    }
    i++
  }
  return true
}
