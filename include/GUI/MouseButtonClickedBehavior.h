#ifndef GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H

#include "GUI/EventBehavior.h"
#include "GUI/UIObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonClickedBehavior : public gui::EventBehavior {
	public:
		MouseButtonClickedBehavior(gui::UIObject* guiObject);
		virtual void OnHandleEvent(const sf::Event& event);
	private:
		bool isPressed = false;
		sf::Mouse::Button pressedButton;
	};

}

#endif // !GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H
