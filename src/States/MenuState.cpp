#include "States/MenuState.h"
#include "States/LobbyState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;


void MenuState::OnEnter()
{
	cout << "Menu loaded" << endl;
}

void MenuState::OnLeave()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
}

void MenuState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}
}

