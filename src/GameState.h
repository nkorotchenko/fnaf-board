#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameTime.h"
#include "GameEnergy.h"

enum E_GameState
{
    MAIN_MENU = 1,
    START_GAME = 2,
    GAME = 3,
    LAPTOP = 4,
    GAME_OVER = 5
};

class GameState
{
    GameTime *gameTime;
    GameEnergy *gameEnergy;

    E_GameState state;

    char szTime[10];
    char szEnergy[24];

public:
    GameState();
    void Update(float elapsed);

    GameTime *GetTime() { return gameTime; }
    GameEnergy *GetEnergy() { return gameEnergy; }
    E_GameState GetState() { return state; }

    void NewGame();

    char *GetTimeString();
    char *GetEnergyString();
};

#endif