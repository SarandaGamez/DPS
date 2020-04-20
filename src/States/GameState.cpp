#include "States/GameState.h"
#include "States/OverState.h"
#include "StatesMachine.h"

#include <iostream>

using std::cout;
using std::endl;


void GameState::OnEnter()
{
	cout << "Loading textures" << endl;
	textures.Load("OfficeBackground", "assets/GUI/Office/ProsecutorsOffice.png");
	cout << "Loading textures done" << endl;

	background.setTexture(textures.GetTexture("OfficeBackground"));
	cout << "Game loaded" << endl;
}

void GameState::OnLeave()
{
	cout << "Game unloaded" << endl;
}

void GameState::OnUpdate()
{
}

void GameState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		isGameFinished = true;
}

void GameState::OnDraw()
{
	renderWindow->draw(background);
}
