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
}

void ctrl::DebugController::Draw() const
{
}
