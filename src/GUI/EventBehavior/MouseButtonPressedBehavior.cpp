#include "GUI/EventBehavior/MouseButtonPressedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonPressedBehavior::MouseButtonPressedBehavior(utils::StateObject* state)
	{
		this->object = state;
		AddEventType(sf::Event::MouseButtonPressed);
	}

	void gui::MouseButtonPressedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!object)
			return;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			object->GetSignal(SignalTypes::onLeftMouseButtonPressed)();
			break;
		case sf::Mouse::Right:
			object->GetSignal(SignalTypes::onRightMouseButtonPressed)();
			break;
		}
	}
}
