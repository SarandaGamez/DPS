#ifndef UTILS_SIGNAL_OBJECT_H
#define UTILS_SIGNAL_OBJECT_H

#include "GUI/EventBehavior/SignalTypes.h"
#include "Utils/SignalsContainer.h"

namespace utils {

	class SignalObject {
	public:
		utils::Signal& GetSignal(utils::Signal::GUID& id);

	protected:
		utils::SignalsContainer<>& GetSignals();

	private:
		utils::SignalsContainer<> signals;
	};
}

#endif