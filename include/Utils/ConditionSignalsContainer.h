#ifndef UTILS_CONDITION_SIGNAL_CONTAINER_H
#define UTILS_CONDITION_SIGNAL_CONTAINER_H

#include "Utils/ConditionSignal.h"
#include <map>
#include <memory>

namespace utils {
	
	template<typename T = ConditionSignal::GUID>
	class ConditionSignalsContainer : public utils::ConditionSignal {

	public:
		ConditionSignal& operator[](const T& guid);
		bool Emit(const T& guid);

	private:
		typedef std::map<T, utils::ConditionSignal> ConditionSignalMap;
		std::unique_ptr<ConditionSignalMap> signals;
	};
	
	template<typename T>
	inline ConditionSignal& ConditionSignalsContainer<T>::operator[](const T& guid)
	{
		if (!signals) {
			signals.reset(new ConditionSignalMap);
		}
		auto signalItr = signals->find(guid);

		if (signalItr == signals->end()) {
			signalItr = signals->insert(
				std::pair<T, ConditionSignal>(guid, ConditionSignal())
			).first;
		}

		return signalItr->second;
	}

	template<typename T>
	inline bool ConditionSignalsContainer<T>::Emit(const T& guid)
	{
		if (!signals) {
			return false;
		}

		auto signalItr = signals->find(guid);

		if (signalItr != signals->end()) {
			if (signalItr->second() == false)
				return false;
		}
		return true;
	}

}

#endif // !UTILS_CONDITION_SIGNAL_CONTAINER_H
