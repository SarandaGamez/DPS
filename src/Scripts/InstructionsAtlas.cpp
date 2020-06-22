#include "Scripts/InstructionsAtlas.h"

void scripts::InstructionsAtlas::AddEvent(const std::string& key, const std::string& event)
{
	this->events.insert(std::make_pair(key, event));
}

void scripts::InstructionsAtlas::AddCondition(const std::string& key, const std::string& condition)
{
	this->conditions.insert(std::make_pair(key, condition));
}

void scripts::InstructionsAtlas::AddAction(const std::string& key, const std::string& action)
{
	this->actions.insert(std::make_pair(key, action));
}

const std::string& scripts::InstructionsAtlas::GetEvent(const std::string& key) const
{
	return events.at(key);
}

const std::string& scripts::InstructionsAtlas::GetCondition(const std::string& key) const
{
	return conditions.at(key);
}

const std::string& scripts::InstructionsAtlas::GetAction(const std::string& key) const
{
	return actions.at(key);
}

std::map<std::string, std::string>* scripts::InstructionsAtlas::GetEventsAtlas()
{
	return &events;
}

std::map<std::string, std::string>* scripts::InstructionsAtlas::GetConditionsAtlas()
{
	return &conditions;
}

std::map<std::string, std::string>* scripts::InstructionsAtlas::GetActionsAtlas()
{
	return &actions;
}
