#include "Controllers/TriggersController.h"
#include <iostream>

ctrl::TriggersController::TriggersController()
{
	interpreter.LoadScriptFromFile("assets/scripts/test.pscript");
	triggers = interpreter.GetLoadedTriggers();
	InitializeTriggers();

	conditionSignals["TEST_CONDITION"].Connect([=]() {
		return true;
		});


	signals["WAIT"].Connect([=]() {
		if (arguments.empty() == false) {
			std::cout << "WAIT " << arguments[0] << std::endl;
			actions.Wait(std::stoi(arguments[0]));
		}
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
		auto instruction = trigger->GetActionAndPop();
		if (trigger->GetConditions().size() > 0)
		{
			signals[eventName].Connect([=]() {
				AddConditionAction(trigger, instruction);
				});
		}
		else
		{
			signals[eventName].Connect([=]() {
				AddAction(instruction);
				});
		}
	}
}

void ctrl::TriggersController::AddAction(std::shared_ptr<scripts::ScriptInstruction> instruction)
{
	actions.Push(new game::Action([=]() {
		EmitSignalWithArguments(instruction);
		}));
}

void ctrl::TriggersController::AddConditionAction(std::shared_ptr<scripts::Trigger> trigger, std::shared_ptr<scripts::ScriptInstruction> instruction)
{
	actions.Push(new game::Action([=]() {
		if (CheckConditions(trigger))
			EmitSignalWithArguments(instruction);
		}));
}

bool ctrl::TriggersController::CheckConditions(std::shared_ptr<scripts::Trigger> trigger) const
{
	for (auto condition : trigger->GetConditions())
		if (conditionSignals.Emit(condition->GetName()) == false)
			return false;
	return true;
}

void ctrl::TriggersController::EmitSignalWithArguments(std::shared_ptr<scripts::ScriptInstruction> instruction)
{
	for (auto arg = instruction->GetArgumentsBegin(); arg != instruction->GetArgumentsEnd(); arg++)
		arguments.push_back(*arg);
	signals.Emit(instruction->GetName());
	arguments.clear();
}
