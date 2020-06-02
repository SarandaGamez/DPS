#include "States/OverState.h"
#include "StatesMachine.h"
#include "States/MenuState.h"


void OverState::OnUpdate(sf::Time elapsedTimes)
{
}

void OverState::OnDraw()
{
}

void OverState::OnHandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
		transition->Switch(std::unique_ptr<State>(new MenuState()));
}

void OverState::OnEnter()
{
}

void OverState::OnLeave()
{
}
