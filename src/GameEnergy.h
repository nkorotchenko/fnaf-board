#ifndef GAME_ENERGY_H
#define GAME_ENERGY_H

enum E_GameDoor
{
    LEFT = 1,
    RIGHT = 2,
};

class GameEnergy
{
    float Energy;

    bool IsDoorLeftClosed;
    bool IsDoorRightClosed;

public:
    GameEnergy();

    float GetEnergy() { return Energy; }

    void SetDoor(E_GameDoor door, bool closed);
    void Update(float elapsed);

    bool GetDoorClosed(E_GameDoor door);

    void Set(float energy) { Energy = energy; }

    int GetUsage();
    int GetMaxUsage();
};

#endif