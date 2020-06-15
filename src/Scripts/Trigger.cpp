#include "Scripts/Trigger.h"

namespace scripts {
	void Trigger::AddEvent(std::shared_ptr<ScriptInstruction> event)
	{
		events.push(event);
	}

	void Trigger::AddCondition(std::shared_ptr<ScriptInstruction> condition)
	{
		conditions.push_back(condition);
	}

	void Trigger::AddAction(std::shared_ptr<ScriptInstruction> action)
	{
		actions.push(action);
	}

	bool Trigger::IsEventsQueueEmpty()
	{
		return this->events.empty();
	}

	bool Trigger::IsActionsQueueEmpty()
	{
		return this->actions.empty();
	}

	std::shared_ptr<ScriptInstruction> Trigger::GetEventAndPop()
	{
		auto event = events.front();
		events.pop();
		return event;
	}

	std::shared_ptr<ScriptInstruction> Trigger::GetActionAndPop()
	{
		auto action = actions.front();
		actions.pop();
		return action;
	}

	const std::vector<std::shared_ptr<ScriptInstruction>>& Trigger::GetConditions()
	{
		return conditions;
	}

}