#include "..\..\include\GUI\UIObject.h"

utils::Signal& gui::UIObject::GetSignal(utils::Signal::GUID& id)
{
	if (!id) {
		id = utils::Signal::GetGUID();
	}

	return signals[id];
}

utils::SignalsContainer& gui::UIObject::GetSignals()
{
	return signals;
}