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
	font.loadFromFile("assets/fonts/cinematic.ttf");

	sf::Vector2f windowCenter = { renderWindow->getSize().x / 2.0f, renderWindow->getSize().y / 2.0f };
	
	components.Add(std::shared_ptr<gui::ClickableText>(new gui::ClickableText(font, "Play", { 0, -200 })))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&MenuState::StartTheGame, this));
	components.Add(std::shared_ptr<gui::ClickableText>(new gui::ClickableText(font, "Load", { 0, -100 })));
	components.Add(std::shared_ptr<gui::ClickableText>(new gui::ClickableText(font, "Settings", { 0,0 })));
	components.Add(std::shared_ptr<gui::ClickableText>(new gui::ClickableText(font, "Exit", { 0, 100 })))
		->GetSignal(gui::SignalTypes::onLeftMouseButtonReleased).Connect(std::bind(&MenuState::CloseGameWindow, this));

	components.SetPosition(windowCenter);

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
	components.Update(deltaTime);
}

void MenuState::OnDraw()
{
	renderWindow->draw(sprite);
	renderWindow->draw(components);
}

void MenuState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;
	}

	components.HandleEvent(event);
}

