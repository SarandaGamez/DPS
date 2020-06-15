#ifndef UTILS_CONDITION_SIGNAL_CONTAINER_H
#define UTILS_CONDITION_SIGNAL_CONTAINER_H

#include "Utils/ConditionSignal.h"
#include <map>
#include <memory>

namespace utils {
	
	template<typename T = Signal::GUID>
	class ConditionSignalsContainer : public utils::ConditionSignal {

	public:
		ConditionSignal& operator[](const T& guid);
		void Emit(const T& guid);

	private:
		typedef std::map<T, utils::ConditionSignal> SignalMap;
		std::unique_ptr<SignalMap> signals;
	};
	
	template<typename T>
	inline ConditionSignal& ConditionSignalsContainer<T>::operator[](const T& guid)
	{
		if (!signals) {
			signals.reset(new SignalMap);
		}

		auto signalItr = signals->find(guid);

		if (signalItr == signals->end()) {
			signalItr = signals->insert(
				std::pair<T, Signal>(guid, Signal())
			).first;
		}

		return signalItr->second;
	}

	template<typename T>
	inline void ConditionSignalsContainer<T>::Emit(const T& guid)
	{
		if (!signals) {
			return;
		}

		auto signalItr = signals->find(guid);

		if (signalItr != signals->end()) {
			signalItr->second();
		}
	}

}

#endif // !UTILS_CONDITION_SIGNAL_CONTAINER_H
