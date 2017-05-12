package main
import (
  //"fmt"
)

// Check if there is a pion around the move we attempt to play
func isClose(x int, y int, board *[SIZE][SIZE]int) int {
  var count int = 0
  if (board[x][y] != 0) {
    return count
  }
  var i = -AMP
  for i <= AMP {
    var j = -AMP
    for j <= AMP {
      if (x + i >= 0 && x + i < SIZE && y + j >= 0 && y + j < SIZE && board[x + i][y + j] != 0) {
        count++
      }
      j++
    }
    i++
  }
  return count
}

// Get array of all playable moves around
func findMoves(game *Game) ([]Move) {

  moves := make([][]Move, 3)
  var res int = 0
  moves[0] = make([]Move, 0)
  moves[1] = make([]Move, 0)
  moves[2] = make([]Move, 0)
  var x = 0
  for x < SIZE {
    var y = 0
    for y < SIZE {
      res = isClose(x, y, &game.board)
      if (res > 3) {
        res = 3
      }
      if (res > 0 && !isForbidenMove(game, x, y)) {
        moves[res - 1] = append(moves[res - 1], newMove(x, y, 0))
      }
      y++
    }
    x++
  }
  moves[2] = append(moves[2], moves[1]...)
  moves[2] = append(moves[2], moves[0]...)
  return moves[2]
}

func getNextMove(game *Game, alpha int, beta int) Move {
  var t int = 0
  var shouldPrune bool = false

  // Reaching leaves
  if (game.depth == DEPTH_MAX) {
    return evaluate(game)
  }

  // Finding all possible moves around
  moves := findMoves(game)

  // If only one possibility, no choice, no need to calculate
  if (len(moves) == 1) {
    return moves[0]
  } else if (len(moves) == 0) {
    return newMove(9, 9, 0)
  }

  // Go through the array
  for t < len(moves) {

    // If the rest of the nodes are considered as useless, we consider the node as pruned
    if (shouldPrune) {
      moves[t].pruned = true

    // Else we Simulate the move for this node
    } else {
      newGame := copyGame(game)
      simulateMove(newGame, moves[t].x, moves[t].y)

      // Check if it's a win node
      if newGame.winner == newGame.friend {
        moves[t].poid = INFINI - newGame.depth
      } else if newGame.winner == newGame.friend % 2 + 1 {
        moves[t].poid = -INFINI + newGame.depth

      // reiterate with this function with the current node
      } else {
        moves[t].poid = getNextMove(newGame, alpha, beta).poid
      }

      // We update Alpha || Beta if result from the node match the conditions
      if (game.curPlayer != game.friend && moves[t].poid < beta) {
        beta = moves[t].poid
      } else if (game.curPlayer == game.friend && moves[t].poid > alpha) {
        alpha = moves[t].poid
      }

      // If Alpha > beta, the rest of the nodes are going to be pruned
      if (alpha >= beta) {
        shouldPrune = true
      }
    }
    t++
  }

  // Once all child nodes have been calculated, we can use min / max and return the right one
  if (game.curPlayer == game.friend) {
    return maxCoup(moves)
  } else {
    return minCoup(moves)
  }
}
