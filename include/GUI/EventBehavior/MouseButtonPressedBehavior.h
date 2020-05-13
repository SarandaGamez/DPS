#ifndef GUI_MOUSE_BUTTON_PRESSED_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_PRESSED_BEHAVIOR_H

#include "GUI/EventBehavior/EventBehavior.h"
#include "GUI/UIObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonPressedBehavior : public gui::EventBehavior {
	public:
		MouseButtonPressedBehavior(gui::UIObject* guiObject);
		virtual void OnHandleEvent(const sf::Event& event);
	};

}

#endif // !GUI_MOUSE_BUTTON_PRESSED_BEHAVIOR_H
