#ifndef GUI_MOUSE_BUTTON_RELEASED_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_RELEASED_BEHAVIOR_H

#include "GUI/EventBehavior/EventBehavior.h"
#include "Utils/StateObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonReleasedBehavior : public gui::EventBehavior {
	public:
		MouseButtonReleasedBehavior(utils::StateObject* state);
		virtual void OnHandleEvent(const sf::Event& event);
	};

}

#endif // !GUI_MOUSE_BUTTON_RELEASEDq_BEHAVIOR_H
