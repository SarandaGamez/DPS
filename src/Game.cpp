#include "Game.h"
#include "States/IntroState.h"
#include "config.h"

Game::Game(){

	std::string title = GAME_TITLE + " " + GAME_VERSION_MAJOR + "." + GAME_VERSION_MINOR + "-" + GAME_VERSION_RELEASE;

	renderWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode::getDesktopMode(), title, sf::Style::Fullscreen);
	renderWindow->setFramerateLimit(60);
	renderWindow->setVerticalSyncEnabled(true);
	renderWindow->setKeyRepeatEnabled(false);

	statesMachine.ConnectWithRenderWindow(renderWindow);
	statesMachine.Push(std::unique_ptr<State>(new IntroState));
	updater.ConnectWithAccessor(statesMachine);


}

void Game::RunLoop()
{
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;

	while (renderWindow->isOpen())
	{
		if (!updater.IsRunning())
			renderWindow->close();

		while (renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				renderWindow->close();
			updater.HandleEvent(event);
		}

		deltaTime = clock.getElapsedTime();
		updater.Update(deltaTime);
		clock.restart();

		renderWindow->clear();
		updater.Draw();
		renderWindow->display();
	}
}
