#include "Controllers/TriggersController.h"
#include <iostream>
#include <filesystem>
#include "Scripts/InstructionsLoader.h"

ctrl::TriggersController::TriggersController()
{
	scripts::InstructionsLoader instructionsLoader(&instructionsAtlas);
	instructionsLoader.LoadInstructionsFromFile("assets/scripts/instructions.pconfig");
	interpreter.ConnectToInstructionsAtlas(&instructionsAtlas);
	
	std::string path = "assets/scripts/";
	for (const auto& entry : std::filesystem::recursive_directory_iterator(path))
		if (entry.path().extension().string() == ".pscript") {
			interpreter.LoadScriptFromFile(entry.path().string());
			for (auto trigger : *interpreter.GetLoadedTriggers())
				triggers.push_back(trigger);
		}

	if(triggers.empty() == false)
		InitializeTriggers();

	conditionSignals["TEST_CONDITION"].Connect([=]() {
		if (arguments.empty() == false)
			if (arguments[0] == "TRUE")
				return true;
		return false;
		});

	signals["WAIT"].Connect([=]() {
		if (arguments.empty() == false) {
			if (variables.CheckIfExists(arguments[0].substr(1))) {
				if (variables.IsType(arguments[0].substr(1), scripts::VariableType::integer)) {
					int milliseconds = std::any_cast<int>(variables.Get(arguments[0].substr(1)).GetValue());
					std::cout << "WAIT " << std::to_string(milliseconds) << std::endl;
					actions.Wait(milliseconds);
				}
				else {
					std::cout << "WAIT 0" << std::endl;
					actions.Wait(0);
				}
			}
			else {
				std::cout << "WAIT " << arguments[0] << std::endl;
				actions.Wait(std::stoi(arguments[0]));
			}
		}
		});

	signals["SET_REAL"].Connect([=]() {
		if (arguments.size() >= 2) {
			variables.Add(arguments[0], scripts::VariableType::real, std::stof(arguments[1]));
		}
		});
	signals["SET_TEXT"].Connect([=]() {
		if (arguments.size() >= 2) {
			std::string value = arguments[1];
			if(arguments.size() >= 3)
			for (int i = 2; i < arguments.size(); i++)
				value += " " + arguments[i];
				
			variables.Add(arguments[0], scripts::VariableType::text, value);
			std::cout << "SET_TEXT " << arguments[0] << " " << value << std::endl;
		}
		});
	signals["SET_FLAG"].Connect([=]() {
		if (arguments.size() >= 2) {
			if(arguments[1] == "TRUE" || arguments[1] == "1")
				variables.Add(arguments[0], scripts::VariableType::flag, true);
			else
				variables.Add(arguments[0], scripts::VariableType::flag, false);
		}
		});
	signals["SET_INTEGER"].Connect([=]() {
		if (arguments.size() >= 2) {
			std::cout << "SET_INTEGER " << arguments[0] << " " << arguments[1] << std::endl;
			variables.Add(arguments[0], scripts::VariableType::integer, std::stoi(arguments[1]));
		}
		});

	signals.Emit("GAME_PREINITIALIZED");

}

void ctrl::TriggersController::Update(sf::Time elapsedTime)
{
}

void ctrl::TriggersController::HandleEvent(sf::Event event)
{
}

void ctrl::TriggersController::InitializeTriggers()
{
	for (auto trigger : triggers) {
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
	bool result = true;
	for (auto condition : trigger->GetConditions()) {
		for (auto arg = condition->GetArgumentsBegin(); arg != condition->GetArgumentsEnd(); arg++)
			arguments.push_back(*arg);
		if (conditionSignals.Emit(condition->GetName()) == false)
			result = false;
		arguments.clear();
	}
	return result;
}

void ctrl::TriggersController::EmitSignalWithArguments(std::shared_ptr<scripts::ScriptInstruction> instruction)
{
	for (auto arg = instruction->GetArgumentsBegin(); arg != instruction->GetArgumentsEnd(); arg++)
		arguments.push_back(*arg);
	signals.Emit(instruction->GetName());
	arguments.clear();
}
