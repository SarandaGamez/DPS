#ifndef CTRL_GAME_CONTROLLER_H
#define CTRL_GAME_CONTROLLER_H

#include "Controllers/Controller.h"

namespace ctrl {
	class GameController : public ctrl::Controller{
	public:
		GameController();
		~GameController();
		virtual void Update(sf::Time elapsedTime) override;
		virtual void HandleEvent(sf::Event event) override;
	private:
		bool isGameInitialized = false;
	};
}

#endif // !CTRL_GAME_CONTROLLER_H
