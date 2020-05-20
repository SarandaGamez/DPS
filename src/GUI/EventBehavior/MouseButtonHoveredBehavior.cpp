#include "GUI/EventBehavior/SignalTypes.h"
#include "GUI/EventBehavior/MouseButtonHoveredBehavior.h"

namespace gui {

	MouseButtonHoveredBehavior::MouseButtonHoveredBehavior(utils::SignalObject* signalObject, gui::UIState* state)
	{
		this->signalObject = signalObject;
		this->state = state;
		AddEventType(sf::Event::MouseMoved);
	}

	void MouseButtonHoveredBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!signalObject)
			return;

		if (state->IsMouseInRegion() == true && haveEntered == false) {
			signalObject->GetSignal(SignalTypes::onMouseEnter)();
			haveEntered = true;
			return;
		}
		
		if (state->IsMouseInRegion() == false && haveEntered == true) {
			signalObject->GetSignal(SignalTypes::onMouseLeave)();
			haveEntered = false;
			return;
		}
	}
}
