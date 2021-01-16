#include <mbed.h>
#include "GameDisplay.h"

#define SCL_PIN PB_10
#define SDA_PIN PB_11

I2C i2c(SDA_PIN, SCL_PIN);

void GameDisplay::Init(GameState *state)
{
    gameState = state;

    display = new SSD1306(&i2c);
    display->begin(true);
    display->setTextSize(1);
    display->setTextColor(WHITE, BLACK);
    display->clearDisplay();
    display->display();

    prevState = gameState->GetState();
}

void GameDisplay::DrawGamePage()
{
    char szText[32];

    GameTime *gameTime = gameState->GetTime();
    sprintf(szText, "%.d", gameTime->GetTimestamp());

    display->setCursor(0, 0);
    display->println(szText);

    display->setCursor(79, 0);
    display->println(gameState->GetTimeString());

    display->setCursor(0, 42);
    display->println(gameState->GetEnergyString());

    display->setCursor(0, 54);
    display->println("Usage:");

    GameEnergy *gameEnergy = gameState->GetEnergy();

    DrawDoor(0, 15, gameState->GetDoorClosed(E_GameDoor::LEFT));
    DrawDoor(128 - 15, 15, gameState->GetDoorClosed(E_GameDoor::RIGHT));

    for (int usage = 0; usage < gameEnergy->GetMaxUsage(); usage++)
    {
        int color = usage < gameEnergy->GetUsage() ? WHITE : BLACK;
        display->fillRect(40 + (usage * 6), 54, 5, 7, color);
    }

    display->display();
}

void GameDisplay::DrawMainMenu()
{
    display->setCursor(31, 7);
    display->println("Five Nights");

    display->setCursor(31, 20);
    display->println("at Freddy's");

    unsigned long currentTimestamp = millis();

    if ((currentTimestamp / 1000) % 2 == 0)
    {
        display->setCursor(16, 50);
        display->println("Press any key...");
    }
    else
    {
        display->fillRect(0, 50, 128, 8, BLACK);
    }

    display->display();
}

void GameDisplay::Display()
{
    E_GameState state = gameState->GetState();

    if (prevState != state)
    {
        display->clearDisplay();
        prevState = state;
    }

    switch (state)
    {
    case E_GameState::MAIN_MENU:
        DrawMainMenu();
        break;
    case E_GameState::GAME:
        DrawGamePage();
        break;

    default:
        break;
    }
}

void GameDisplay::DrawDoor(int x, int y, bool closed)
{
    int width = 15;
    int height = 20;

    display->drawRect(x, y, width, height, WHITE);
    display->fillRect(x + 1, y + 1, width - 2, height - 2, closed ? WHITE : BLACK);
}