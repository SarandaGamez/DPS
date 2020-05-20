#ifndef GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H
#define GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H

#include "GUI/EventBehavior/EventBehavior.h"
#include "Utils/SignalObject.h"
#include "GUI/UIState.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class MouseButtonHoveredBehavior : public gui::EventBehavior {
		gui::UIState* state;
		bool haveEntered = false;
	public:
		MouseButtonHoveredBehavior(utils::SignalObject* signalObject, gui::UIState* state);
		virtual void OnHandleEvent(const sf::Event& event);
	};

}

#endif // !GUI_MOUSE_BUTTON_MOVE_BEHAVIOR_H
