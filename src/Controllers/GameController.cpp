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
		signals["GAME_INITIALIZED"]();
	}

	if (actions.IsBlocked() == false && actions.IsWaiting() == false) {
		if (actions.IsEmpty() == false) {
			actions.ExecuteAndPop();
		}
	}
	actions.UpdateElapsedTime(elapsedTime);
}

void ctrl::GameController::HandleEvent(sf::Event event)
{
}
