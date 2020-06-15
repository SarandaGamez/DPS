#include "Controllers/TriggersController.h"
#include "Gameplay/ConditionAction.h"
#include <iostream>

ctrl::TriggersController::TriggersController()
{
	interpreter.LoadScriptFromFile("assets/scripts/test.pscript");
	triggers = interpreter.GetLoadedTriggers();
	InitializeTriggers();

	conditionSignals["TEST_CONDITION"].Connect([=]() {
		return true;
		});

}

void ctrl::TriggersController::Update(sf::Time elapsedTime)
{
}

void ctrl::TriggersController::HandleEvent(sf::Event event)
{
}

void ctrl::TriggersController::InitializeTriggers()
{
	for (auto trigger : *triggers) {
		while (trigger->IsEventsQueueEmpty() == false) {
			ConnectToSignal(trigger);
		}
	}
}

void ctrl::TriggersController::ConnectToSignal(std::shared_ptr<scripts::Trigger> trigger)
{
	std::string eventName = trigger->GetEventAndPop()->GetName();
	while (trigger->IsActionsQueueEmpty() == false)
	{
		std::string actionName = trigger->GetActionAndPop()->GetName();
		if (trigger->GetConditions().size() > 0)
		{
			signals[eventName].Connect([=]() {
				AddConditionAction(trigger, actionName);
				});
		}
		else
		{
			signals[eventName].Connect([=]() {
				AddAction(actionName);
				});
		}
	}
}

void ctrl::TriggersController::AddAction(const std::string& actionName)
{
	actions.Push(new game::Action([=]() {
		signals.Emit(actionName);
		}));
}

void ctrl::TriggersController::AddConditionAction(std::shared_ptr<scripts::Trigger> trigger, const std::string& actionName)
{
	actions.Push(new game::ConditionAction([=]() {
		for (auto condition : trigger->GetConditions())
			if (conditionSignals.Emit(condition->GetName()) == false)
				return false;
		return true;
		},
		[=]() {
			signals.Emit(actionName);
		}));
}
