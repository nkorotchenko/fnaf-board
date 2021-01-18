#ifndef GAME_DISPLAY_H
#define GAME_DISPLAY_H

#include "GameState.h"
#include "../lib/Adafruit_GFX/SSD1306.h"

#include "system.h"

class GameDisplay
{
    GameState *gameState;
    SSD1306 *display;

    E_DisplayState prevDisplayState;

    void DrawDoor(int x, int y, bool closed);
    void DrawGamePage();
    void DrawMainMenu();

public:
    void Init(GameState *state);
    void Display();
};

#endif