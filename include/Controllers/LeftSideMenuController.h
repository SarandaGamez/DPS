#ifndef CTRL_LEFT_SIDE_MENU_CONTROLLER_H
#define CTRL_LEFT_SIDE_MENU_CONTROLLER_H

#include "GUI/UIComponent.h"
#include "Controllers/Controller.h"
#include "GUI/Window.h"

namespace ctrl {
	class LeftSideMenuController : public ctrl::Controller {
	public:
		LeftSideMenuController();
		~LeftSideMenuController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		std::shared_ptr<gui::Window> menuWindow;
		void OpenMenu();
		void CloseMenu();
	};
}

#endif // !CTRL_LEFT_SIDE_MENU_CONTROLLER_H
