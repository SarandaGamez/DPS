#include "GUI\EventBehavior.h"

namespace gui {
	   
	void EventBehavior::HandleEvent(const sf::Event& event)
	{
		if (eventType == event.type)
			OnHandleEvent(event);
	}

	EventBehavior::EventBehavior(std::shared_ptr<gui::UIObject> guiObject)
	{
		this->guiObject = guiObject;
	}
}
