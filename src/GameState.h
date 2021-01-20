#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameTime.h"
#include "GameEnergy.h"

enum E_GameDoor
{
    LEFT = 1,
    RIGHT = 2,
};

enum E_DisplayState
{
    MAIN_MENU = 1,
    START_GAME = 2,
    GAME = 3,
    LAPTOP = 4,
    GAME_OVER = 5
};

struct GamePageState
{
    bool IsDoorLeftClosed;
    bool IsDoorRightClosed;
    int Energy;
    int Usage;
    int Hour;
    int Minute;

    bool operator==(const GamePageState& value)
    {
        return IsDoorLeftClosed == value.IsDoorLeftClosed
            && IsDoorRightClosed == value.IsDoorRightClosed
            && Energy == value.Energy
            && Usage == value.Usage
            && Hour == value.Hour
            && Minute == value.Minute;
    }
};

class GameState
{
    GameTime *gameTime;
    GameEnergy *gameEnergy;

    E_DisplayState displayState;

    bool IsDoorLeftClosed;
    bool IsDoorRightClosed;

    char szTime[10];
    char szEnergy[24];

    void UpdateEnergyUsing();

public:
    GameState();
    
    void Update(float elapsed);

    GameTime *GetTime() { return gameTime; }
    GameEnergy *GetEnergy() { return gameEnergy; }
    E_DisplayState GetDisplayState() { return displayState; }

    void SetDoor(E_GameDoor door, bool closed);
    bool GetDoorClosed(E_GameDoor door);

    void GetGamePageState(GamePageState* state);

    void NewGame();

    char *GetTimeString();
    char *GetEnergyString();
};

#endif