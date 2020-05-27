#include "GUI/EventBehavior/SignalTypes.h"
#include "GUI/EventBehavior/MouseButtonHoveredBehavior.h"

namespace gui {

	MouseButtonHoveredBehavior::MouseButtonHoveredBehavior(utils::StateObject* state)
	{
		this->object = state;
		AddEventType(sf::Event::MouseMoved);
	}

	void MouseButtonHoveredBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!object)
			return;

		if (object->IsMouseInRegion() == true && haveEntered == false) {
			object->GetSignal(SignalTypes::onMouseEnter)();
			haveEntered = true;
			return;
		}
		
		if (object->IsMouseInRegion() == false && haveEntered == true) {
			object->GetSignal(SignalTypes::onMouseLeave)();
			haveEntered = false;
			return;
		}
	}
}
