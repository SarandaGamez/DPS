#include "Controllers\Controller.h"


StateTransition* ctrl::Controller::transition = nullptr;
std::shared_ptr<sf::RenderWindow> ctrl::Controller::renderWindow = nullptr;
TexturesHolder* ctrl::Controller::textures = nullptr;

unsigned int ctrl::Controller::currentLayer = 0;
game::ActionsQueue ctrl::Controller::actions;
utils::SignalsContainer<std::string> ctrl::Controller::signals;
utils::ConditionSignalsContainer<std::string> ctrl::Controller::conditionSignals;
std::vector<std::string> ctrl::Controller::arguments;
scripts::InstructionsSet ctrl::Controller::instructionsAtlas;
scripts::Variables ctrl::Controller::variables;
std::list<std::shared_ptr<gui::UIComponent>> ctrl::Controller::drawablesList;

void ctrl::Controller::Initialize(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& texturesHolder, StateTransition* transition)
{
	ctrl::Controller::renderWindow = renderWindow;
	ctrl::Controller::textures = &texturesHolder;
	ctrl::Controller::transition = transition;
}
