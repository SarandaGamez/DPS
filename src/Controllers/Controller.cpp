#include "Controllers\Controller.h"

ctrl::Controller::Controller(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& texturesHolder, StateTransition* transition)
{
	this->renderWindow = renderWindow;
	this->textures = &texturesHolder;
	this->transition = transition;
}

unsigned int ctrl::Controller::currentLayer = 0;