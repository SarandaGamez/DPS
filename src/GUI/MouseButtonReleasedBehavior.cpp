#include "GUI/MouseButtonReleasedBehavior.h"
#include "GUI/SignalTypes.h"

namespace gui {
	gui::MouseButtonReleasedBehavior::MouseButtonReleasedBehavior(gui::UIObject* guiObject)
	{
		this->guiObject = guiObject;
		this->eventType = sf::Event::MouseButtonReleased;
	}

	void gui::MouseButtonReleasedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!guiObject)
			return;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			guiObject->GetSignal(SignalTypes::onLeftMouseButtonReleased)();
			break;
		case sf::Mouse::Right:
			guiObject->GetSignal(SignalTypes::onRightMouseButtonReleased)();
			break;
		}
	}
}
