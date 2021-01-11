#ifndef GAME_BUTTON_H
#define GAME_BUTTON_H

#include <mbed.h>

class GameButton
{
    int status;
    DigitalIn *button;
public:
    GameButton(PinName pin);
    bool Toggle();
};

#endif