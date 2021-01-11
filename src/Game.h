#ifndef GAME_H
#define GAME_H

enum E_GameButton
{
    LEFT_DOOR = 1,
    RIGHT_DOOR = 2,
    MONITOR_SWITCH = 3,
    FLASHLIGHT = 4,
};

#include "GameButton.h"
#include "GameState.h"
#include "GameDisplay.h"

#include "system.h"

class Game
{
    GameState *gameState;
    GameDisplay* gameDisplay;

    unsigned long lastUpdated;
    float elapsed;

public:
    void Init();
    void Update();
    void Display();

    void ToggleButton(E_GameButton button);
};

#endif