#include "Gameplay/ConditionAction.h"

game::ConditionAction::ConditionAction(std::function<bool()> const& condition, std::function<void()> const& slot) : game::Action(slot)
{
	AddCondition(condition);
}

bool game::ConditionAction::CheckConditions()
{
	for (auto condition : conditions)
		if (condition() == false)
			return false;
	return true;
}

void game::ConditionAction::AddCondition(std::function<bool()> const& condition)
{
	conditions.push_back(condition);
}

void game::ConditionAction::Execute()
{
	if (CheckConditions() == true) {
		game::Action::Execute();
	}
}
