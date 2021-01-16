#include <mbed.h>
#include "GameEnergy.h"

GameEnergy::GameEnergy()
{
    Energy = 100;
    Usage = 1;
}

void GameEnergy::Update(float elapsed)
{
    float multiplier = 0.05 + (Usage * 0.1);
    
    Energy -= multiplier * elapsed;

    if (Energy <= 0)
    {
        Energy = 0;
    }
}

void GameEnergy::SetUsage(int usage)
{
    Usage = usage;

    if (Usage > USAGE_MAX)
    {
        Usage = USAGE_MAX;
    }

    if (Usage < USAGE_MIN)
    {
        Usage = USAGE_MIN;
    }
}

void GameEnergy::AddUsage(int usage)
{
    SetUsage(Usage + usage);
}

int GameEnergy::GetMaxUsage()
{
    return USAGE_MAX;
}