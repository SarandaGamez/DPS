#include "GUI/EventBehavior/SignalTypes.h"
#include "GUI/EventBehavior/MouseButtonHoveredBehavior.h"

namespace gui {

	MouseButtonHoveredBehavior::MouseButtonHoveredBehavior(gui::UIObject* guiObject, gui::UIState* state)
	{
		this->guiObject = guiObject;
		this->state = state;
		AddEventType(sf::Event::MouseMoved);
	}

	void MouseButtonHoveredBehavior::OnHandleEvent(const sf::Event& event)
	{
		if (!guiObject)
			return;

		if (state->IsMouseInRegion() == true && haveEntered == false) {
			guiObject->GetSignal(SignalTypes::onMouseEnter)();
			haveEntered = true;
			return;
		}
		
		if (state->IsMouseInRegion() == false && haveEntered == true) {
			guiObject->GetSignal(SignalTypes::onMouseLeave)();
			haveEntered = false;
			return;
		}
	}
}
