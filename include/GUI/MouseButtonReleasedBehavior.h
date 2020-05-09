#ifndef GUI_MOUSE_BUTTON_RELEASED_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_RELEASED_BEHAVIOR_H

#include "GUI/EventBehavior.h"
#include "GUI/UIObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonReleasedBehavior : public gui::EventBehavior {
	public:
		MouseButtonReleasedBehavior(gui::UIObject* guiObject);
		virtual void OnHandleEvent(const sf::Event& event);
	};

}

#endif // !GUI_MOUSE_BUTTON_RELEASEDq_BEHAVIOR_H
