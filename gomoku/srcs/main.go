package main

import (
	"github.com/veandco/go-sdl2/sdl"
)

const W = 1205
const H = 1205
const OFFSET_Y = 160
const OFFSET_SCORE_Y = 70
const SPACING_SCORE = 2
const OFFSET_X = 110
const SPACING = 5
const SQUARE = 50
const PION = 40
const OFFSET_LAST_SCORE_X = 574
const OFFSET_LAST_SCORE_Y = 34
const OFFSET_ARRAY_Y = 32
const OFFSET_ARRAY_LEFT_X = 275
const OFFSET_ARRAY_RIGHT_X = 860

const PLAYER1 = 1
const PLAYER2 = 2
const NUL = 3
const NONE = 0
const HINT = 3
var DEPTH_MAX = 1
const EQUAL = 0
const INFINI = 1000000
const AMP = 1
const SIZE = 19
const MULTI = 2
const SOLO = 1
const MENU = 0

type Move struct {
  x int
  y int
  poid int
	pruned bool
}

type AlphaBeta struct {
  alpha int
  beta int
}

type LastChance struct {
	i int
	j int
	x int
	y int
	winner int
	player int
}

type Game struct {
	lastChance *LastChance
	score [2]int
	curPlayer int
	depth int
	winner int
	board [SIZE][SIZE]int
	friend int
}

type Tools struct {
	win *sdl.Window
	surface *sdl.Surface
	exit bool
	iaStart bool
	aiHelper bool
	gameType int
	wait bool
}

func main() {
	tools := initTools()
	game := initGame()

	displayMenu(tools, 0)
	handleEvent(tools, game)
	sdl.Quit()
	return
}
