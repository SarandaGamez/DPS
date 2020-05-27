#ifndef GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H

#include "GUI/EventBehavior/EventBehavior.h"
#include "Utils/SignalObject.h"
#include "Utils/StateObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonHoveredBehavior : public gui::EventBehavior {
		bool haveEntered = false;
	public:
		MouseButtonHoveredBehavior(utils::StateObject* state);
		virtual void OnHandleEvent(const sf::Event& event);
	};

}

#endif // !GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H
