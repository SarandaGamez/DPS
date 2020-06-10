#include "Utils/SignalObject.h"

utils::Signal& utils::SignalObject::GetSignal(utils::Signal::GUID& id)
{
	if (!id) {
		id = utils::Signal::GetGUID();
	}

	return signals[id];
}

utils::SignalsContainer<>& utils::SignalObject::GetSignals()
{
	return signals;
}