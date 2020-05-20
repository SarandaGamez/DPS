#include "GUI/EventBehavior/MouseButtonPressedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonPressedBehavior::MouseButtonPressedBehavior(utils::SignalObject* signalObject)
	{
		this->signalObject = signalObject;
		AddEventType(sf::Event::MouseButtonPressed);
	}

	void gui::MouseButtonPressedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!signalObject)
			return;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			signalObject->GetSignal(SignalTypes::onLeftMouseButtonPressed)();
			break;
		case sf::Mouse::Right:
			signalObject->GetSignal(SignalTypes::onRightMouseButtonPressed)();
			break;
		}
	}
}
