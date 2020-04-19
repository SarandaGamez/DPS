#include "States/MenuState.h"
#include "States/IntroState.h"
#include "StatesMachine.h"
#include <iostream>
#include <memory>
#include <sfml/Window/Mouse.hpp>

using std::cout;
using std::endl;


void MenuState::OnEnter()
{
	cout << "Menu loaded" << endl;
	textures.Load("MainMenu/Button", "assets/GUI/MainMenu/button.png");
	textures.Load("MainMenu/ButtonClicked", "assets/GUI/MainMenu/buttonClicked.png");
	font.loadFromFile("assets/fonts/cinematic.ttf");
	
	buttonPlay = std::unique_ptr<Button>(new Button(
		textures.GetTexture("MainMenu/Button"),
		textures.GetTexture("MainMenu/ButtonClicked"),
		font,
		"play",
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 - 100)));
	buttonExit = std::unique_ptr<Button>(new Button(
		textures.GetTexture("MainMenu/Button"),
		textures.GetTexture("MainMenu/ButtonClicked"),
		font,
		"exit",
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2)));
}

void MenuState::OnLeave()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::OnUpdate()
{
	if (buttonExit->IsClicked())
		isGameFinished = true;

	if (buttonPlay->IsClicked())
		transition->Switch(std::unique_ptr<State>(new IntroState));
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
	renderWindow->draw(*buttonPlay);
	renderWindow->draw(*buttonExit);
}

void MenuState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}

	if (event.type == sf::Event::MouseButtonReleased) {
		buttonPlay->CheckClick(renderWindow->mapPixelToCoords({ sf::Mouse::getPosition(*renderWindow) }));
		buttonExit->CheckClick(renderWindow->mapPixelToCoords({ sf::Mouse::getPosition(*renderWindow) }));
	}
}

