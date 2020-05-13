#include "GUI\EventBehavior.h"

namespace gui {
	   
	void EventBehavior::HandleEvent(const sf::Event& event)
	{
		if (!guiObject)
			return;

		if (eventType.empty())
			return;

		for(auto type: eventType)
			if(event.type == type)
				OnHandleEvent(event);
	}
	void EventBehavior::AddEventType(sf::Event::EventType eventType)
	{
		this->eventType.push_back(eventType);
	}
}
