#ifndef GUI_SFML_EVENT_HANDLER_H
#define GUI_SFML_EVENT_HANDLER_H

#include "Utils/SignalObject.h"
#include <SFML/Window/Event.hpp>
#include <memory>
#include <vector>

namespace gui {

	class EventBehavior {
	public:
		void HandleEvent(const sf::Event& event);
	protected:
		virtual void OnHandleEvent(const sf::Event& event) = 0;
		void AddEventType(sf::Event::EventType eventType);
		utils::SignalObject* signalObject;

	private:
		std::vector<sf::Event::EventType> eventType;
	};
}

#endif // !GUI_SFML_EVENT_HANDLER_H
