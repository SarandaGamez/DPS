#ifndef GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H

#include "GUI/EventBehavior/EventBehavior.h"
#include "Utils/StateObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonClickedBehavior : public gui::EventBehavior {
	public:
		MouseButtonClickedBehavior(utils::StateObject* state);
		virtual void OnHandleEvent(const sf::Event& event);
	private:
		bool isPressed = false;
		sf::Mouse::Button pressedButton;
	};

}

#endif // !GUI_MOUSE_BUTTON_CLICKED_BEHAVIOR_H
