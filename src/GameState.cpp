#include <mbed.h>
#include "GameState.h"

GameState::GameState()
{
    gameTime = new GameTime(24, 0);
    gameEnergy = new GameEnergy();
    
    state = E_GameState::MAIN_MENU;
}

void GameState::Update(float elapsed)
{
    gameTime->Update(elapsed);
    gameEnergy->Update(elapsed);
}

void GameState::SetDoor(E_GameDoor door, bool closed)
{
    if (door == E_GameDoor::LEFT)
    {
        IsDoorLeftClosed = closed;
    }
    else if (door == E_GameDoor::RIGHT)
    {
        IsDoorRightClosed = closed;
    }

    gameEnergy->AddUsage(closed ? 1 : -1);
}

bool GameState::GetDoorClosed(E_GameDoor door)
{
    if (door == E_GameDoor::LEFT)
    {
        return IsDoorLeftClosed;
    }
    else if (door == E_GameDoor::RIGHT)
    {
        return IsDoorRightClosed;
    }

    return false;
}

void GameState::NewGame()
{
    state = E_GameState::GAME;
    gameTime->Set(24, 0);
    gameEnergy->Set(100);
    gameEnergy->SetUsage(0);
}

char *GameState::GetTimeString()
{
    char szAM[] = "AM";
    char szPM[] = "PM";

    char *meridiem = szAM;

    int hour = gameTime->GetHour();

    if (hour >= 12)
    {
        meridiem = szPM;
        hour -= 12;
    }

    if (hour <= 0)
    {
        hour = 12;
    }

    sprintf(szTime, "%.2d:%.2d %s", hour, gameTime->GetMinutes(), meridiem);
    return szTime;
}

char *GameState::GetEnergyString()
{
    sprintf(szEnergy, "Power left: %3.0f%%", gameEnergy->GetEnergy());
    return szEnergy;
}