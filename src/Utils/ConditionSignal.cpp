#include "Utils/ConditionSignal.h"

namespace utils {
	ConditionSignal::GUID lastConditionGuid = 0;

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

	bool ConditionSignal::operator()() const
	{
		for (auto const& it : slots) {
			if (it.second() == false)
				return false;
		}
		return true;
	}

	ConditionSignal::GUID utils::ConditionSignal::GetGUID()
	{
		return ++lastConditionGuid;
	}
}