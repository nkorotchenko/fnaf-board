#ifndef GAME_ENERGY_H
#define GAME_ENERGY_H

#define USAGE_MIN 1
#define USAGE_MAX 3

class GameEnergy
{
    float Energy;
    int Usage;

public:
    GameEnergy();

    float GetEnergy() { return Energy; }

    void Update(float elapsed);

    void Set(float energy) { Energy = energy; }

    void SetUsage(int usage);
    int GetUsage() { return Usage; }
    void AddUsage(int usage);
    int GetMaxUsage();
};

#endif