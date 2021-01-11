#include <mbed.h>
#include "Game.h"

void Game::Init()
{
    gameState = new GameState();
    gameDisplay = new GameDisplay();

    gameDisplay->Init(gameState);

    millisStart();
}

void Game::Update()
{
    unsigned long current = millis();
    elapsed = (current - lastUpdated) / 1000.0f;
    lastUpdated = current;

    gameState->Update(elapsed);
}

void Game::Display()
{
    gameDisplay->Display();
}

void Game::ToggleButton(E_GameButton button)
{
    GameEnergy *gameEnergy = gameState->GetEnergy();
    E_GameState state = gameState->GetState();

    if (state == E_GameState::MAIN_MENU)
    {
        gameState->NewGame();
    }
    else if (state == E_GameState::GAME)
    {
        switch (button)
        {
        case E_GameButton::LEFT_DOOR:
            gameEnergy->SetDoor(E_GameDoor::LEFT, !gameEnergy->GetDoorClosed(E_GameDoor::LEFT));
            break;

        case E_GameButton::RIGHT_DOOR:
            gameEnergy->SetDoor(E_GameDoor::RIGHT, !gameEnergy->GetDoorClosed(E_GameDoor::RIGHT));
            break;

        default:
            break;
        }
    }
}