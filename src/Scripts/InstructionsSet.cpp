#include "Scripts/InstructionsSet.h"

void scripts::InstructionsSet::AddEvent(const std::string& event)
{
	this->events.insert(event);
}

void scripts::InstructionsSet::AddCondition(const std::string& condition)
{
	this->conditions.insert(condition);
}

void scripts::InstructionsSet::AddAction(const std::string& action)
{
	this->actions.insert(action);
}

std::set<std::string>* scripts::InstructionsSet::GetEventsAtlas()
{
	return &events;
}

std::set<std::string>* scripts::InstructionsSet::GetConditionsAtlas()
{
	return &conditions;
}

std::set<std::string>* scripts::InstructionsSet::GetActionsAtlas()
{
	return &actions;
}

bool scripts::InstructionsSet::IsEventInSet(const std::string& key)
{
	return events.count(key) > 0;
}

bool scripts::InstructionsSet::IsConditionInSet(const std::string& key)
{
	return conditions.count(key) > 0;
}

bool scripts::InstructionsSet::IsActionInSet(const std::string& key)
{
	return actions.count(key) > 0;
}
