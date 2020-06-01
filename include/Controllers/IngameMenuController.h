#ifndef CTRL_INGAME_MENU_CONTROLLER_H
#define CTRL_INGAME_MENU_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/TextButton.h"
#include "GUI/Window.h"
#include <memory>

namespace ctrl {
	class IngameMenuController : public ctrl::Controller {
	public:
		IngameMenuController();
		~IngameMenuController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Font font;
		std::shared_ptr<gui::Window> menuWindow;
		std::shared_ptr<gui::TextButton> button;
		void OpenMenu();
		void CloseMenu();
	};
}

#endif // !CTRL_INGAME_MENU_CONTROLLER_H