#include "Utils/SignalsContainer.h"

namespace utils {
	Signal& utils::SignalsContainer::operator[](const Signal::GUID& guid)
	{
		if (!signals) {
			signals.reset(new SignalMap);
		}

		auto signalItr = signals->find(guid);

		if (signalItr == signals->end()) {
			signalItr = signals->insert(
				std::pair<Signal::GUID, Signal>(guid, Signal())
			).first;
		}

		return signalItr->second;
	}

	void SignalsContainer::Emit(const Signal::GUID& guid)
	{
		if (!signals || !guid) {
			return;
		}

		auto signalItr = signals->find(guid);

		if (signalItr != signals->end()) {
			signalItr->second();
		}
	}
}