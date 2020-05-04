#include "GUI\EventBehavior.h"

namespace gui {
	   
	void EventBehavior::HandleEvent(const sf::Event& event)
	{
		if (eventType == event.type)
			OnHandleEvent(event);
	}
}
