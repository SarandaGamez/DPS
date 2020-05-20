#include "GUI/EventBehavior/MouseButtonClickedBehavior.h"
#include "GUI/EventBehavior/SignalTypes.h"

namespace gui {
	gui::MouseButtonClickedBehavior::MouseButtonClickedBehavior(utils::SignalObject* signalObject)
	{
		this->signalObject = signalObject;
		AddEventType(sf::Event::MouseButtonReleased);
		AddEventType(sf::Event::MouseButtonPressed);
	}

	void gui::MouseButtonClickedBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!signalObject)
			return;

		if (event.type == sf::Event::MouseButtonReleased) {
			if (isPressed && event.mouseButton.button == pressedButton) {
				switch (pressedButton)
				{
				case sf::Mouse::Left:
					signalObject->GetSignal(SignalTypes::onLeftMouseButtonReleased)();
					break;
				case sf::Mouse::Right:
					signalObject->GetSignal(SignalTypes::onRightMouseButtonReleased)();
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
					signalObject->GetSignal(SignalTypes::onLeftMouseButtonPressed)();
					break;
				case sf::Mouse::Right:
					signalObject->GetSignal(SignalTypes::onRightMouseButtonPressed)();
					break;
				}
			}
		}
	}
}
