#include <mbed.h>
#include "GameEnergy.h"

GameEnergy::GameEnergy()
{
    Energy = 100;
    
    IsDoorLeftClosed = false;
    IsDoorRightClosed = false;
}

void GameEnergy::SetDoor(E_GameDoor door, bool closed)
{
    if (door == E_GameDoor::LEFT)
    {
        IsDoorLeftClosed = closed;
    }
    else if (door == E_GameDoor::RIGHT)
    {
        IsDoorRightClosed = closed;
    }
}

void GameEnergy::Update(float elapsed)
{
    float multiplier = 0.05;

    if (IsDoorLeftClosed)
    {
        multiplier += 0.1;
    }

    if (IsDoorRightClosed)
    {
        multiplier += 0.1;
    }

    Energy -= multiplier * elapsed;

    if (Energy <= 0)
    {
        Energy = 0;
    }
}

bool GameEnergy::GetDoorClosed(E_GameDoor door)
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

int GameEnergy::GetUsage()
{
    int usage = 1;

    if (IsDoorLeftClosed)
    {
        usage++;
    }

    if (IsDoorRightClosed)
    {
        usage++;
    }

    return usage;
}

int GameEnergy::GetMaxUsage()
{
    return 3;
}