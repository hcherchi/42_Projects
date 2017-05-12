package main

import (
  //"fmt"
)

// Get the Move with the min score
func minCoup(moves []Move) Move {
  var min = INFINI
  var minCoup *Move
  var t = 0

  for t < len(moves) {
    if (moves[t].poid < min && !moves[t].pruned) {
      min = moves[t].poid
      minCoup = &moves[t]
    }
    t++
  }
  return *minCoup
}

// Get the Move with the max score
func maxCoup(moves []Move) Move {
  var max = -INFINI
  var maxCoup *Move
  var t = 0

  for t < len(moves) {
    if (moves[t].poid > max && !moves[t].pruned) {
      max = moves[t].poid
      maxCoup = &moves[t]
    }
    t++
  }
  return *maxCoup
}
