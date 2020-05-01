#ifndef UTILS_SIGNAL_CONTAINER_H
#define UTILS_SIGNAL_CONTAINER_H

#include "Utils/Signal.h"
#include <map>
#include <memory>

namespace utils {

	class SignalsContainer : public utils::Signal {

	public:
		Signal& operator[](const Signal::GUID& guid);
		void Emit(const Signal::GUID& guid);

	private:
		typedef std::map<utils::Signal::GUID, utils::Signal> SignalMap;
		std::unique_ptr<SignalMap> signals;
	};
	
}

#endif // !UTILS_SIGNAL_CONTAINER_H
