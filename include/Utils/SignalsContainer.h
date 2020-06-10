#ifndef UTILS_SIGNAL_CONTAINER_H
#define UTILS_SIGNAL_CONTAINER_H

#include "Utils/Signal.h"
#include <map>
#include <memory>

namespace utils {
	
	template<typename T = Signal::GUID>
	class SignalsContainer: public utils::Signal {

	public:
		Signal& operator[](const T& guid);
		void Emit(const T& guid);

	private:
		typedef std::map<T, utils::Signal> SignalMap;
		std::unique_ptr<SignalMap> signals;
	};
	
	template<typename T>
	inline Signal& SignalsContainer<T>::operator[](const T& guid)
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
	inline void SignalsContainer<T>::Emit(const T& guid)
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

#endif // !UTILS_SIGNAL_CONTAINER_H
