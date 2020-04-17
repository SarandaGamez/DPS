#include "States/IntroState.h"
#include "States/MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::OnEnter()
{
	font.loadFromFile("assets/fonts/cinematic.ttf");
	textures.Load("cinematic-intro-1", "assets/cinematics/intro/intro1.png");
	textures.Load("cinematic-intro-2", "assets/cinematics/intro/intro2.png");
	textures.Load("cinematic-intro-3", "assets/cinematics/intro/intro3.png");
	textures.Load("cinematic-intro-4", "assets/cinematics/intro/intro4.png");
	slideshow = std::make_shared<Slideshow>(font);
	slideshow->add("TESTESTSETSET 1", textures.GetTexture("cinematic-intro-1"));
	slideshow->add("TESTESTSETSET 2", textures.GetTexture("cinematic-intro-2"));
	slideshow->add("TESTESTSETSET 3", textures.GetTexture("cinematic-intro-3"));
	slideshow->add("TESTESTSETSET 4", textures.GetTexture("cinematic-intro-4"));
}

void IntroState::OnLeave()
{
}

void IntroState::OnHandleEvent()
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape)
			isGameFinished = true;


		if (slideshow->isOver())
			transition->Switch(std::unique_ptr<State>(new MenuState));

		slideshow->next();
	}
}

void IntroState::OnUpdate()
{
	cout << "Intro updated" << endl;


}

void IntroState::OnDraw()
{
	slideshow->draw(renderWindow);
}

