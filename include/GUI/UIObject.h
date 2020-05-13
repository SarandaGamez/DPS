#ifndef GUI_UIOBJECT_H
#define GUI_UIOBJECT_H

#include "GUI/EventBehavior/SignalTypes.h"
#include "Utils/SignalsContainer.h"

namespace gui {

	class UIObject {
	public:
		utils::Signal& GetSignal(utils::Signal::GUID& id);

	protected:
		utils::SignalsContainer& GetSignals();

	private:
		utils::SignalsContainer signals;
	};
}

#endif