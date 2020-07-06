#ifndef CTRL_CONTROLLERS_H
#define CTRL_CONTROLLERS_H

#include "Controllers/Controller.h"
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>
#include <vector>
#include <memory>

namespace ctrl {
	class Controllers : public ctrl::Controller{
	public:
		void Add(ctrl::Controller* controller);
		void HandleEvent(sf::Event event);
		void Update(sf::Time elapsedTimes);
		void Draw();
	private:
		std::vector<std::shared_ptr<ctrl::Controller>> controllers;

	};
}

#endif // !CTRL_CONTROLLERS_H
