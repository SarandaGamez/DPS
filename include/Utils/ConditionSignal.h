#ifndef UTILS_CONDITION_SIGNAL_H
#define UTILS_CONDITION_SIGNAL_H

#include <functional>
#include <map>

namespace utils {

	class ConditionSignal {

	public:
		typedef std::size_t GUID;

		ConditionSignal() : currentId(0) {}

		// copy creates new signal
		ConditionSignal(ConditionSignal const& other) : currentId(0) {}

		// connects a std::function to the signal. The returned
		// value can be used to disconnect the function again
		int Connect(std::function<bool()> const& slot) const;

		// disconnects a previously connected function
		void Disconnect(ConditionSignal::GUID id) const;

		// disconnects all previously connected functions
		void Disconnect_all() const;

		// calls all connected functions
		void operator()() const;

		static ConditionSignal::GUID GetGUID();
	private:
		typedef std::map<unsigned int, std::function<bool()>> SlotsMap;
		mutable SlotsMap slots;
		mutable unsigned int currentId;
	};

}

#endif // !UTILS_CONDITION_SIGNAL_H
