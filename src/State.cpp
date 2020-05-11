#include "State.h"
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

sf::Vector2f State::mousePosition = { 0,0 };

void State::ConnectWithStateTransition(StateTransition* transition)
{
	this->transition = transition;
}

void State::ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	this->renderWindow = renderWindow;
}

void State::HandleEvent(sf::Event event)
{
	this->event = event;
	mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };
	OnHandleEvent();
}

void State::Update(sf::Time deltaTime)
{
	if (!transition) throw std::runtime_error("Cannot find StateTransition object");
	if (!renderWindow) throw std::runtime_error("Cannot find sf::RenderWindow object");

	this->deltaTime = deltaTime;
	OnUpdate();
}

void State::Draw()
{
	OnDraw();
}

bool State::IsGameFinished()
{
	return isGameFinished;
}
