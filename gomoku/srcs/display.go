package main

import (
	"github.com/veandco/go-sdl2/sdl"
	"github.com/veandco/go-sdl2/sdl_image"
	"github.com/veandco/go-sdl2/sdl_ttf"
	"regexp"
	"os"
	"time"
	"strconv"
)

func displayBoard(tools *Tools, game *Game) {
	tools.surface.Free()

  putImageCenter("ressources/board.bmp", tools.surface)
  var i int = 0
  var j int = 0

  for i < SIZE {
    j = 0
    for j < SIZE {
      if (game.board[i][j] != 0) {
        displayDot(int32(i), int32(j), tools, game.board[i][j])
      }
      j++
    }
    i++
  }
	i = 0
	for i < game.score[PLAYER1 - 1] {
		displayScoreDot(int32(i), tools, PLAYER2)
		i++
	}
	i = 0
	for i < game.score[PLAYER2 - 1] {
		displayScoreDot(int32(i), tools, PLAYER1)
		i++
	}
	displayTurn(tools, game.curPlayer)
  tools.win.UpdateSurface()
}

func displayMenu(tools *Tools, sum int)  {
	if (tools.iaStart || tools.aiHelper) {
		if tools.iaStart && tools.aiHelper { putImageCenter("ressources/menu.bmp", tools.surface)}

		if tools.iaStart {
			if (!tools.aiHelper) { putImageCenter("ressources/menu.bmp", tools.surface) }
			putImageXY("ressources/Stick.bmp", tools.surface, 480,890)
		}
		if tools.aiHelper {
			if (!tools.iaStart) { putImageCenter("ressources/menu.bmp", tools.surface) }
			putImageXY("ressources/Stick.bmp", tools.surface, 480,943)
		}
		displayDepth(tools, sum)
		tools.win.UpdateSurface()
		return
	}

	putImageCenter("ressources/menu.bmp", tools.surface)
	displayDepth(tools, sum)
	tools.win.UpdateSurface()
}

func displayTurn(tools *Tools, curPlayer int)  {
	var file string
	var offsetX int32

	if curPlayer == PLAYER1 {
		offsetX = OFFSET_ARRAY_LEFT_X
	   file = "ressources/left.bmp"
	 } else {
		 offsetX = OFFSET_ARRAY_RIGHT_X
	   file = "ressources/right.bmp"
	 }
	putImageXY(file, tools.surface, offsetX, OFFSET_ARRAY_Y)
}

func displayDot(i int32, j int32, tools *Tools, player int) {
  var file string

	if player == PLAYER1 {
    file = "ressources/pion_blanc.bmp"
  } else if player == PLAYER2 {
    file = "ressources/pion_noir.bmp"
  } else if player == HINT {
		file = "ressources/pion_vert.bmp"
	}
	putImageXY(file, tools.surface, j * SQUARE + j * SPACING + OFFSET_X - SQUARE / 2, i * SQUARE + i * SPACING + OFFSET_Y - SQUARE / 2)
}

func displayScoreDot(nb int32, tools *Tools, player int) {
	var file string

	if player == PLAYER1 {
		file = "ressources/pion_blanc.bmp"
	} else {
		file = "ressources/pion_noir.bmp"
	}
	if (nb == 9) {
		putImageXY(file, tools.surface, OFFSET_LAST_SCORE_X + (SQUARE - PION) / 2, OFFSET_LAST_SCORE_Y + (SQUARE - PION) / 2)
	} else if (player == PLAYER1) {
		putImageXY(file, tools.surface, W - OFFSET_X + (SQUARE - PION) / 2 - (SQUARE + SPACING_SCORE) * (nb + 1) - SPACING_SCORE, OFFSET_SCORE_Y + (SQUARE - PION) / 2)
	} else {
		putImageXY(file, tools.surface, OFFSET_X + (SQUARE - PION) / 2 + (SQUARE + SPACING_SCORE) * nb, OFFSET_SCORE_Y + (SQUARE - PION) / 2)
	}
}

func getXY(src *sdl.Surface, dst *sdl.Surface, x int32, y int32) error {
	var centerRect sdl.Rect
	centerRect.X = x
	centerRect.Y = y
	return src.Blit(nil, dst, &centerRect)
}


func putImageXY(file string, dst *sdl.Surface, x int32, y int32) error {
	imgSurface, _ := img.Load(file)
	defer imgSurface.Free()
	return getXY(imgSurface, dst, x, y)
}

func getCenter(src *sdl.Surface, dst *sdl.Surface) error {
	var centerRect sdl.Rect
	centerRect.X = dst.ClipRect.H/2 - src.ClipRect.H/2
	centerRect.Y = dst.ClipRect.W/2 - src.ClipRect.W/2
	return src.Blit(nil, dst, &centerRect)
}

func putImageCenter(file string, dst *sdl.Surface) error {
	imgSurface, _ := img.Load(file)
	defer imgSurface.Free()
	return getCenter(imgSurface, dst)
}

func initMessage(tools *Tools) sdl.MessageBoxData  {

	var msg sdl.MessageBoxData
	var buttonArray = make([]sdl.MessageBoxButtonData, 2)
	buttonArray[0].Flags = sdl.MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT
	buttonArray[0].ButtonId = 1
	buttonArray[0].Text = "Replay"
	buttonArray[1].Flags = sdl.MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT
	buttonArray[1].ButtonId = 2
	buttonArray[1].Text = "Quit"
	var colorBox *sdl.MessageBoxColorScheme = new(sdl.MessageBoxColorScheme)

	colorBox.Colors[0].R = 255
	colorBox.Colors[0].G = 0
	colorBox.Colors[0].B = 0

	colorBox.Colors[1].R = 255
	colorBox.Colors[1].G = 0
	colorBox.Colors[1].B = 0

	colorBox.Colors[2].R = 255
	colorBox.Colors[2].G = 0
	colorBox.Colors[2].B = 0

	colorBox.Colors[3].R = 255
	colorBox.Colors[3].G = 0
	colorBox.Colors[3].B = 0

	colorBox.Colors[4].R = 255
	colorBox.Colors[4].G = 0
	colorBox.Colors[4].B = 0

	msg.Flags = sdl.MESSAGEBOX_INFORMATION
	msg.Window = tools.win
	msg.Title = "End of game"
	msg.NumButtons = 2
	msg.Buttons = buttonArray
	msg.ColorScheme = colorBox
	return msg
}

func  displayDepth(tools *Tools, sum int)  {

	if sum < 0 && DEPTH_MAX + sum == 0 { sum = 0 }
	if sum > 0 && DEPTH_MAX + sum == 11  { sum = 0 }
	ttf.Init()

	var clr sdl.Color
	clr.R = 0
	clr.G = 0
	clr.B = 0

	var rect  sdl.Rect
	font, _:= ttf.OpenFont("ressources/Zalight.ttf", 42)

	DEPTH_MAX += sum
	text, _:= font.RenderUTF8_Solid(strconv.Itoa(DEPTH_MAX), clr)
	defer text.Free()

	rect.X = 679
	rect.Y = 1000
	text.Blit(nil, tools.surface, &rect);
}

func  displayTime(tools *Tools, time time.Duration)  {
	ttf.Init()
	var clr sdl.Color
	clr.R = 0
	clr.G = 0
	clr.B = 0

	match, _ := regexp.MatchString("µs", time.String())
	var rect  sdl.Rect
	font, _:= ttf.OpenFont("ressources/Zalight.ttf", 42)
	var str string

	if match {
		str = "less than 1ms"
	} else {
		str = time.String()
	}
	text, _:= font.RenderUTF8_Solid(str,clr)
	defer text.Free()

	rect.X = 100
	rect.Y = 120
	text.Blit(nil, tools.surface, &rect);
	tools.win.UpdateSurface()
}

func endGame(tools *Tools, game *Game) {

	msg := initMessage(tools)
	if game.winner == PLAYER1 {
		msg.Message = "PLAYER 1 win"
	} else if (game.winner == PLAYER2) {
		msg.Message = "PLAYER 2 win"
	} else {
		msg.Message = "Nobody win"
	}

	_, key := sdl.ShowMessageBox(&msg)


	if (key == 2) {
		sdl.Quit()
		os.Exit(1)
	}

	tools.gameType = MENU
	newGame(game)
	displayMenu(tools, 0)
}
