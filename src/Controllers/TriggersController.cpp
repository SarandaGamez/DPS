#include "Controllers/TriggersController.h"
#include "Gameplay/ConditionAction.h"
#include <iostream>

ctrl::TriggersController::TriggersController()
{
	interpreter.LoadScriptFromFile("assets/scripts/test.pscript");
	triggers = interpreter.GetLoadedTriggers();

	for (auto trigger : *triggers) {
		while (trigger->IsEventsQueueEmpty() == false) {
			std::string eventName = trigger->GetEventAndPop()->GetName();
			while (trigger->IsActionsQueueEmpty() == false) {
				std::string actionName = trigger->GetActionAndPop()->GetName();
				signals[eventName].Connect([=]() {
					if (trigger->GetConditions().size() == 0)
						AddAction(actionName);
					else
						AddConditionAction(trigger, actionName);
					});
			}
		}
	}

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
