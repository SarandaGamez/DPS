#include "State.h"
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

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
	OnHandleEvent(event);
}

void State::Update(sf::Time deltaTime)
{
	if (!transition) throw std::runtime_error("Cannot find StateTransition object");
	if (!renderWindow) throw std::runtime_error("Cannot find sf::RenderWindow object");

	OnUpdate(deltaTime);
}

void State::Draw()
{
	OnDraw();
}