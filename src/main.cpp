#include <mbed.h>

#include "Game.h"

void UpdateInput(Game *game);

DigitalOut led(LED1);

GameButton leftDoorButton(PB_12);

SPI spi(PB_15, PB_14, PB_13);
DigitalOut ledLatch(PB_1);

//Serial Debug(USBTX, USBRX);

int main()
{
  //millisStart();

  led = 0;

  spi.lock();
  ledLatch = 0;

  spi.write(0b11000010);

  ledLatch = 1;
  spi.unlock();

  wait_ms(1000);

  Game game;
  game.Init();

  int ups = 0;

  //Debug.printf("time = %lu", millis());

  while (1)
  {
    if (ups == 0)
    {
      game.Display();
    }

    UpdateInput(&game);

    wait_ms(15);

    ups++;
    if (ups == 60)
    {
      led = !led;
      ups = 0;
      game.Update();
    }
  }
}

void UpdateInput(Game *game)
{
  if (leftDoorButton.Toggle())
  {
    game->ToggleButton(E_GameButton::LEFT_DOOR);
  }
}