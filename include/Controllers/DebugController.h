#ifndef CTRL_DEBUG_CONTROLLER_H
#define CTRL_DEBUG_CONTROLLER_H

#include "Controllers/Controller.h"
#include <memory>
#include "GUI/TextComponent.h"
#include "GUI/Window.h"

namespace ctrl {
	class DebugController : public ctrl::Controller {
	public:
		DebugController();
		~DebugController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Font font;
		bool isWindowClosed = false;
		std::shared_ptr<gui::Window> dialogWindow;
		std::shared_ptr<gui::TextComponent> debugText;
	};
}

#endif // !CTRL_DEBUG_CONTROLLER_H