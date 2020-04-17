#ifndef GAME_H
#define GAME_H

#include "StatesMachine.h"
#include "StateUpdater.h"
#include <SFML/Graphics.hpp>
#include <string>


class Game {
	StatesMachine statesMachine;
	StateUpdater updater;
	std::shared_ptr<sf::RenderWindow> renderWindow;
public:
	Game();

	void RunLoop();

};

#endif // !GAME_H