#include "Controllers/GameController.h"

ctrl::GameController::GameController()
{
}

ctrl::GameController::~GameController()
{
}

void ctrl::GameController::Update(sf::Time elapsedTime)
{
	if (isGameInitialized == false) {
		isGameInitialized = true;
		signals["GAME_INITIALIZATION"]();
	}
}

void ctrl::GameController::HandleEvent(sf::Event event)
{
}
