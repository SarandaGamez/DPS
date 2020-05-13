#include "GUI/MouseButtonPressedBehavior.h"
#include "GUI/SignalTypes.h"

namespace gui {
	gui::MouseButtonPressedBehavior::MouseButtonPressedBehavior(gui::UIObject* guiObject)
	{
		this->guiObject = guiObject;
		AddEventType(sf::Event::MouseButtonPressed);
	}

	void gui::MouseButtonPressedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!guiObject)
			return;

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
