#ifndef GUI_SFML_EVENT_HANDLER_H
#define GUI_SFML_EVENT_HANDLER_H

#include "GUI/UIObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>

namespace gui {

	class EventBehavior {
	public:
		void HandleEvent(const sf::Event& event);
	protected:
		virtual void OnHandleEvent(const sf::Event& event) = 0;
		sf::Event::EventType eventType;
		std::shared_ptr<gui::UIObject> guiObject;
	};
}

#endif // !GUI_SFML_EVENT_HANDLER_H
