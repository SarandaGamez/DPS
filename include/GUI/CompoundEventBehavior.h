#ifndef GUI_EVENT_HANDLER_H
#define GUI_EVENT_HANDLER_H

#include <SFML/Window/Event.hpp>
#include <list>
#include <memory>
#include "GUI/EventBehavior.h"

namespace gui {

	class CompoundEventBehavior : public gui::EventBehavior {
	public:
		void HandleEvent(const sf::Event& event);
		void Add(std::shared_ptr<EventBehavior> eventBehavior);
		void Remove(std::shared_ptr<EventBehavior> eventBehavior);
		std::list<std::shared_ptr<EventBehavior>> GetChildren();
	private:
		std::list<std::shared_ptr<EventBehavior>> children;
	};
}

#endif // !GUI_EVENT_HANDLER_H
