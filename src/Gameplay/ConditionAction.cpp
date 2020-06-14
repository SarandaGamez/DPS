#include "Gameplay/ConditionAction.h"

game::ConditionAction::ConditionAction(std::function<void()> const& slot, std::function<bool()> const& conditions) : game::Action(slot)
{
	this->conditions = conditions;
}

bool game::ConditionAction::CheckConditions()
{
	return conditions();
}

void game::ConditionAction::Execute()
{
	if (CheckConditions() == true) {
		game::Action::Execute();
	}
}
