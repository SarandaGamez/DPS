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
	
	buttonPlay = std::unique_ptr<gui::Button>(new gui::Button(
		textures.GetTexture("MainMenu/Button"),
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 - 200)));
	buttonLoad = std::unique_ptr<gui::Button>(new gui::Button(
		textures.GetTexture("MainMenu/Button"),
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 - 100)));
	buttonSettings = std::unique_ptr<gui::Button>(new gui::Button(
		textures.GetTexture("MainMenu/Button"),
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2)));
	buttonExit = std::unique_ptr<gui::Button>(new gui::Button(
		textures.GetTexture("MainMenu/Button"),
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 + 100)));

	buttonPlay->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&MenuState::StartTheGame, this));
	buttonExit->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&MenuState::CloseGameWindow, this));
}

void MenuState::OnLeave()
{
	cout << "Menu unloaded" << endl;
}

void MenuState::StartTheGame()
{
	if (buttonPlay->IsMouseInRegion(mousePosition)) {
		transition->Switch(std::unique_ptr<State>(new IntroState));
	}
}

void MenuState::CloseGameWindow()
{
	if (buttonExit->IsMouseInRegion(mousePosition)) {
		this->isGameFinished = true;
	}
}

void MenuState::OnUpdate()
{
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
	buttonPlay->draw(renderWindow);
	buttonLoad->draw(renderWindow);
	buttonSettings->draw(renderWindow);
	buttonExit->draw(renderWindow);
}

void MenuState::OnHandleEvent()
{
	mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}
	buttonExit->HandleEvent(event);
	buttonPlay->HandleEvent(event);
}

