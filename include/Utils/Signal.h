#ifndef UTILS_SIGNAL_H
#define UTILS_SIGNAL_H

#include <functional>
#include <map>

namespace utils {

	class Signal {

	public:
		typedef std::size_t GUID;

		Signal() : currentId(0) {}

		// copy creates new signal
		Signal(Signal const& other) : currentId(0) {}

		// connects a member function to this Signal
		template <typename T>
		int Connect_member(T* inst, void (T::* func)(void)) {
			return connect([=]() {
				(inst->*func)();
				});
		}

		// connects a const member function to this Signal
		template <typename T>
		int Connect_member(T* inst, void (T::* func)(void) const) {
			return connect([=]() {
				(inst->*func)();
				});
		}

		// connects a std::function to the signal. The returned
		// value can be used to disconnect the function again
		int Connect(std::function<void()> const& slot) const;

		// disconnects a previously connected function
		void Disconnect(unsigned int id) const;

		// disconnects all previously connected functions
		void Disconnect_all() const;

		// calls all connected functions
		void operator()() const;

		static Signal::GUID GetGUID();
	private:
		typedef std::map<unsigned int, std::function<void()>> SlotsMap;
		mutable SlotsMap slots;
		mutable unsigned int currentId;
	};

}

#endif // !UTILS_SIGNAL_H
