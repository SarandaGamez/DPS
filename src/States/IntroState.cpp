#include "States/IntroState.h"
#include "States/GameState.h"
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
	slideshow = std::make_shared<Slideshow>();
	slideshow->Add("There was a country where people were ruled by burgeois bastards", font, textures.GetTexture("cinematic-intro-1"));
	slideshow->Add("People were very upset by this situation. They wanted equality!", font, textures.GetTexture("cinematic-intro-2"));
	slideshow->Add("Afters years of capitalists despotism, poor people started a revolution", font, textures.GetTexture("cinematic-intro-3"));
}

void IntroState::OnLeave()
{
}

void IntroState::OnHandleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Escape)
			renderWindow->close();


		if (slideshow->IsOver())
			transition->Switch(std::unique_ptr<State>(new GameState));

		slideshow->Next();
	}
}

void IntroState::OnUpdate(sf::Time elapsedTimes)
{
	cout << "Intro updated" << endl;


}

void IntroState::OnDraw()
{
	slideshow->Draw(renderWindow);
}

