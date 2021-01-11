#include "GameButton.h"

GameButton::GameButton(PinName pin)
{
    button = new DigitalIn(pin);
    status = 0;
}

bool GameButton::Toggle()
{
    bool toggle = false;

    if (status != !button->read())
    {
        if (!button->read())
        {
            toggle = true;
        }

        status = !button->read();
    }

    return toggle;
}