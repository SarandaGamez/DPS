#include "Controllers/DebugController.h"

ctrl::DebugController::DebugController()
{
}

ctrl::DebugController::~DebugController()
{
}

void ctrl::DebugController::Update(sf::Time time)
{
	if(isWindowClosed)
		renderWindow->close();
}

void ctrl::DebugController::HandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::Escape && currentLayer == 0) {
			isWindowClosed = true;
		}
	}
}

void ctrl::DebugController::Draw() const
{
}
