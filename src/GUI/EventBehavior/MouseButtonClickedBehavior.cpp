#include "GUI/EventBehavior/MouseButtonClickedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonClickedBehavior::MouseButtonClickedBehavior(utils::StateObject* state)
	{
		this->object = state;
		AddEventType(sf::Event::MouseButtonReleased);
		AddEventType(sf::Event::MouseButtonPressed);
	}

	void gui::MouseButtonClickedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!object)
			return;

		if (event.type == sf::Event::MouseButtonReleased) {
			if (isPressed && event.mouseButton.button == pressedButton) {
				switch (pressedButton)
				{
				case sf::Mouse::Left:
					object->GetSignal(SignalTypes::onLeftMouseButtonReleased)();
					break;
				case sf::Mouse::Right:
					object->GetSignal(SignalTypes::onRightMouseButtonReleased)();
					break;
				}
			}
			isPressed = false;
		}
		else {
			if (event.type == sf::Event::MouseButtonPressed && isPressed == false) {
				isPressed = true;
				pressedButton = event.mouseButton.button;

				switch (pressedButton)
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
	}
}
