#include "Controllers\Controller.h"


StateTransition* ctrl::Controller::transition = nullptr;
std::shared_ptr<sf::RenderWindow> ctrl::Controller::renderWindow = nullptr;
TexturesHolder* ctrl::Controller::textures = nullptr;

unsigned int ctrl::Controller::currentLayer = 0;

void ctrl::Controller::Initialize(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& texturesHolder, StateTransition* transition)
{
	ctrl::Controller::renderWindow = renderWindow;
	ctrl::Controller::textures = &texturesHolder;
	ctrl::Controller::transition = transition;
}