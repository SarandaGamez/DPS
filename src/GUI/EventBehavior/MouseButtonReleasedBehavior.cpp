#include "GUI/EventBehavior/MouseButtonReleasedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonReleasedBehavior::MouseButtonReleasedBehavior(utils::SignalObject* signalObject)
	{
		this->signalObject = signalObject;
		AddEventType(sf::Event::MouseButtonReleased);
	}

	void gui::MouseButtonReleasedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!signalObject)
			return;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			signalObject->GetSignal(SignalTypes::onLeftMouseButtonReleased)();
			break;
		case sf::Mouse::Right:
			signalObject->GetSignal(SignalTypes::onRightMouseButtonReleased)();
			break;
		}
	}
}
