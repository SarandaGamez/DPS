#ifndef CTRL_DEBUG_CONTROLLER_H
#define CTRL_DEBUG_CONTROLLER_H

#include "Controllers/Controller.h"

namespace ctrl {
	class DebugController : public ctrl::Controller {
	public:
		DebugController(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& textures, StateTransition* transition);
		~DebugController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		bool isWindowClosed = false;
	};
}

#endif // !CTRL_DEBUG_CONTROLLER_H