package main

import (
	"time"
	"github.com/veandco/go-sdl2/sdl"
	//"fmt"
)

func play(game *Game, tools *Tools, i int, j int) {
  simulateMove(game, i, j)
  displayBoard(tools, game)
}

// IA Play
func iaTurn(tools *Tools, game *Game) time.Duration {
	alpha, beta := -INFINI, INFINI
	tools.wait = true
	timeBfore := time.Now()
	bestMove := getNextMove(game, alpha, beta)
	timeAfter := time.Now()
	time := timeAfter.Sub(timeBfore)
	play(game, tools, bestMove.x, bestMove.y)
	tools.wait = false
	return time
}

// AI search and display the Hint (green pion)
func displayHint(tools *Tools, game *Game) {
	tools.wait = true
	alpha, beta := -INFINI, INFINI
	bestMove := getNextMove(game, alpha, beta)

	game.board[bestMove.x][bestMove.y] = HINT
	displayBoard(tools, game)
	game.board[bestMove.x][bestMove.y] = NONE
	tools.wait = false
}

// Called when click of the screen
func  onClic(t *sdl.MouseButtonEvent, tools *Tools, game *Game)  {

	// translate x, y coordinate of the screen into grid coordinate
	var j int = (int(t.X) + SQUARE / 2 - OFFSET_X) / (SQUARE + SPACING)
	var moduloj = (int(t.X) + SQUARE / 2 - OFFSET_X) % (SQUARE + SPACING)
	var i int = (int(t.Y) + SQUARE / 2 - OFFSET_Y) / (SQUARE + SPACING)
	var moduloi = (int(t.Y) + SQUARE / 2 - OFFSET_Y) % (SQUARE + SPACING)

	// If move is playable
	if (moduloj > 0 && moduloi > 0 && isPlayable(game, i, j)) {
		// Play
    play(game, tools, i, j)
		// If winner, end the game
		if (game.winner != NONE) {
			endGame(tools, game)
		// If game was against IA, make it play
		} else if (tools.gameType == SOLO) {
			time := iaTurn(tools, game)
			if (game.winner != NONE) {
				endGame(tools, game)
			} else if (tools.aiHelper) {
				displayHint(tools, game)
			}
			displayTime(tools, time)
		} else if (tools.aiHelper) {
			displayHint(tools, game)
		}
	}
}

func handleEvent(tools *Tools, game *Game) {

	for !tools.exit {

		for event := sdl.PollEvent(); event != nil; event = sdl.PollEvent() {
			switch t := event.(type) {
			case *sdl.QuitEvent:
				tools.exit = true
				break
			case *sdl.MouseMotionEvent:
				//fmt.Println(t.X, " ", t.Y)
				break
			case *sdl.KeyDownEvent:
				if t.Keysym.Sym == 27 {
					tools.exit = true
				}
				break
			case *sdl.MouseButtonEvent:
				if t.Type == 1025 && tools.gameType != MENU && !tools.wait {
					onClic(t, tools, game)
				} else if (t.Type == 1025 && t.X <= 740 && t.Y <= 625 && t.Y  >= 492 && t.X >= 466 && tools.gameType == MENU) {
					tools.gameType = MULTI
					displayBoard(tools, game)
				} else if (t.Type == 1025 && t.X <= 740 && t.Y <= 822 && t.Y  >= 688 && t.X >= 466 && tools.gameType == MENU) {
					tools.gameType = SOLO
					displayBoard(tools, game)
					if (tools.iaStart) {
						iaTurn(tools, game)
					}
				} else if (t.Type == 1025 && t.X <= 510 && t.Y <= 921 && t.Y  >= 898 && t.X >= 485 && tools.gameType == MENU) {
					tools.iaStart = !tools.iaStart
					displayMenu(tools, 0)
				} else if (t.Type == 1025 && t.X <= 510 && t.Y <= 973 && t.Y  >= 956 && t.X >= 485 && tools.gameType == MENU) {
					tools.aiHelper = !tools.aiHelper
					displayMenu(tools, 0)
				} else if (t.Type == 1025 && t.X <= 494 && t.Y <= 1040 && t.Y  >= 1010 && t.X >= 473 && tools.gameType == MENU) {
					displayMenu(tools, 1)
				} else if (t.Type == 1025 && t.X <= 543 && t.Y <= 1035 && t.Y  >= 1020 && t.X >= 512 && tools.gameType == MENU) {
					displayMenu(tools, -1)
				}
				break
		}
	}
}
}
