#include "GUI/EventBehavior/MouseButtonReleasedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonReleasedBehavior::MouseButtonReleasedBehavior(utils::StateObject* state)
	{
		this->object = state;
		AddEventType(sf::Event::MouseButtonReleased);
	}

	void gui::MouseButtonReleasedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!object)
			return;

		switch (event.mouseButton.button)
		{
		case sf::Mouse::Left:
			object->GetSignal(SignalTypes::onLeftMouseButtonReleased)();
			break;
		case sf::Mouse::Right:
			object->GetSignal(SignalTypes::onRightMouseButtonReleased)();
			break;
		}
	}
}
