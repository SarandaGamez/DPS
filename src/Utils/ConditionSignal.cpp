#include "Utils/ConditionSignal.h"

namespace utils {
	ConditionSignal::GUID lastGuid = 0;

	int ConditionSignal::Connect(std::function<bool()> const& slot) const
	{
		slots.insert(std::make_pair(++currentId, slot));
		return currentId;
	}

	void ConditionSignal::Disconnect(ConditionSignal::GUID id) const
	{
		slots.erase(id);
	}

	void ConditionSignal::Disconnect_all() const
	{
		slots.clear();
	}

	void ConditionSignal::operator()() const
	{
		for (auto const& it : slots) {
			it.second();
		}
	}

	ConditionSignal::GUID utils::ConditionSignal::GetGUID()
	{
		return ++lastGuid;
	}
}