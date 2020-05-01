#include "Utils/Signal.h"

namespace utils {
	Signal::GUID lastGuid = 0;

	int Signal::Connect(std::function<void()> const& slot) const
	{
		slots.insert(std::make_pair(++currentId, slot));
		return currentId;
	}

	void Signal::Disconnect(unsigned int id) const
	{
		slots.erase(id);
	}

	void Signal::Disconnect_all() const
	{
		slots.clear();
	}

	void Signal::operator()() const
	{
		for (auto const& it : slots) {
			it.second();
		}
	}

	Signal::GUID utils::Signal::GetGUID()
	{
		return ++lastGuid;
	}

}