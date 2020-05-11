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
	font.loadFromFile("assets/fonts/cinematic.ttf");

	buttonPlay = std::unique_ptr<gui::ClickableText>(new gui::ClickableText(
		font, "Play",
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 - 200)));
	buttonLoad = std::unique_ptr<gui::ClickableText>(new gui::ClickableText(
		font, "Load",
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2 - 100)));
	buttonSettings = std::unique_ptr<gui::ClickableText>(new gui::ClickableText(
		font, "Settings",
		sf::Vector2f(renderWindow->getSize().x / 2, renderWindow->getSize().y / 2)));
	buttonExit = std::unique_ptr<gui::ClickableText>(new gui::ClickableText(
		font, "Exit",
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
	transition->Switch(std::unique_ptr<State>(new IntroState));
}

void MenuState::CloseGameWindow()
{
	this->isGameFinished = true;

}

void MenuState::OnUpdate()
{
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
	renderWindow->draw(*buttonPlay);
	renderWindow->draw(*buttonLoad);
	renderWindow->draw(*buttonSettings);
	renderWindow->draw(*buttonExit);
}

void MenuState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}
	buttonExit->HandleEvent(event);
	buttonPlay->HandleEvent(event);
}

