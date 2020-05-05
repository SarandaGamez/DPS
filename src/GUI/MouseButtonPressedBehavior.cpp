#include "GUI/MouseButtonPressedBehavior.h"
#include "GUI/SignalTypes.h"

namespace gui {
	gui::MouseButtonPressedBehavior::MouseButtonPressedBehavior(std::shared_ptr<gui::UIObject> guiObject)
	{
		this->guiObject = guiObject;
		this->eventType = sf::Event::MouseButtonPressed;
	}

	void gui::MouseButtonPressedBehavior::OnHandleEvent(const sf::Event& event)
	{
		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			guiObject->GetSignal(SignalTypes::onLeftMouseButtonPressed)();
			break;
		case sf::Mouse::Right:
			guiObject->GetSignal(SignalTypes::onRightMouseButtonPressed)();
			break;
		}
	}
}
