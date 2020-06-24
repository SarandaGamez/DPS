#include "Controllers/TriggersController.h"
#include <iostream>
#include <filesystem>

ctrl::TriggersController::TriggersController()
{
	instructionsAtlas.AddEvent("GAME_PREINITIALIZED", "GAME_PREINITIALIZED");
	instructionsAtlas.AddEvent("GAME_INITIALIZED", "GAME_INITIALIZED");
	instructionsAtlas.AddEvent("EVERY_SEC_MIN", "EVERY_SEC_MIN");
	instructionsAtlas.AddEvent("EVERY_SEC", "EVERY_SEC");
	instructionsAtlas.AddEvent("EVERY", "EVERY");
	instructionsAtlas.AddEvent("CLICKED_FAX", "CLICKED_FAX");
	instructionsAtlas.AddEvent("CLICKED_MAP", "CLICKED_MAP");
	instructionsAtlas.AddEvent("CLICKED_NOTEBOOK", "CLICKED_NOTEBOOK");
	instructionsAtlas.AddEvent("CLICKED_NEXTTURN", "CLICKED_NEXTTURN");
	instructionsAtlas.AddEvent("CLICKED_MENU", "CLICKED_MENU");
	instructionsAtlas.AddEvent("TURN_CHANGE_FINISHED", "TURN_CHANGE_FINISHED");
	instructionsAtlas.AddEvent("TURN_CHANGE_STARTED", "TURN_CHANGE_STARTED");
	instructionsAtlas.AddEvent("TURN_CHANGE_INTERRUPTED", "TURN_CHANGE_INTERRUPTED");
	instructionsAtlas.AddEvent("CLOSED_FAX", "CLOSED_FAX");
	instructionsAtlas.AddEvent("CLOSED_MAP", "CLOSED_MAP");
	instructionsAtlas.AddEvent("CLOSED_NOTEBOOK", "CLOSED_NOTEBOOK");
	instructionsAtlas.AddEvent("CLOSED_MENU", "CLOSED_MENU");
	instructionsAtlas.AddEvent("OPENED_FAX", "OPENED_FAX");
	instructionsAtlas.AddEvent("OPENED_MAP", "OPENED_MAP");
	instructionsAtlas.AddEvent("OPENED_NOTEBOOK", "OPENED_NOTEBOOK");
	instructionsAtlas.AddEvent("OPENED_MENU", "OPENED_MENU");

	instructionsAtlas.AddCondition("IS_FAX_OPEN", "IS_FAX_OPEN");
	instructionsAtlas.AddCondition("IS_MAP_OPEN", "IS_MAP_OPEN");
	instructionsAtlas.AddCondition("IS_NOTEBOOK_OPEN", "IS_NOTEBOOK_OPEN");
	instructionsAtlas.AddCondition("IS_MENU_OPEN", "IS_MENU_OPEN");
	instructionsAtlas.AddCondition("IS_FAX_CLOSED", "IS_FAX_CLOSED");
	instructionsAtlas.AddCondition("IS_MAP_CLOSED", "IS_MAP_CLOSED");
	instructionsAtlas.AddCondition("IS_NOTEBOOK_CLOSED", "IS_NOTEBOOK_CLOSED");
	instructionsAtlas.AddCondition("IS_MENU_CLOSED", "IS_MENU_CLOSED");
	instructionsAtlas.AddCondition("IS_EQUAL", "IS_EQUAL");
	instructionsAtlas.AddCondition("IS_GREATER_THAN", "IS_GREATER_THAN");
	instructionsAtlas.AddCondition("IS_LESS_THAN", "IS_LESS_THAN");
	instructionsAtlas.AddCondition("IS_GREATER_OR_EQUAL", "IS_GREATER_OR_EQUAL");
	instructionsAtlas.AddCondition("IS_LESS_OR_EQUAL", "IS_LESS_OR_EQUAL");
	instructionsAtlas.AddCondition("IS_TRUE", "IS_TRUE");
	instructionsAtlas.AddCondition("IS_FALSE", "IS_FALSE");
	instructionsAtlas.AddCondition("TEST_CONDITION", "TEST_CONDITION");

	instructionsAtlas.AddAction("SHOW_FAX_BUTTON", "SHOW_FAX_BUTTON");
	instructionsAtlas.AddAction("SHOW_MAP_BUTTON", "SHOW_MAP_BUTTON");
	instructionsAtlas.AddAction("SHOW_NOTEBOOK_BUTTON", "SHOW_NOTEBOOK_BUTTON");
	instructionsAtlas.AddAction("SHOW_MENU_BUTTON", "SHOW_MENU_BUTTON");
	instructionsAtlas.AddAction("HIDE_FAX_BUTTON", "HIDE_FAX_BUTTON");
	instructionsAtlas.AddAction("HIDE_MAP_BUTTON", "HIDE_MAP_BUTTON");
	instructionsAtlas.AddAction("HIDE_NOTEBOOK_BUTTON", "HIDE_NOTEBOOK_BUTTON");
	instructionsAtlas.AddAction("HIDE_MENU_BUTTON", "HIDE_MENU_BUTTON");
	instructionsAtlas.AddAction("OPEN_FAX", "OPEN_FAX");
	instructionsAtlas.AddAction("OPEN_MAP", "OPEN_MAP");
	instructionsAtlas.AddAction("OPEN_NOTEBOOK", "OPEN_NOTEBOOK");
	instructionsAtlas.AddAction("OPEN_MENU", "OPEN_MENU");
	instructionsAtlas.AddAction("CLOSE_FAX", "CLOSE_FAX");
	instructionsAtlas.AddAction("CLOSE_MAP", "CLOSE_MAP");
	instructionsAtlas.AddAction("CLOSE_NOTEBOOK", "CLOSE_NOTEBOOK");
	instructionsAtlas.AddAction("CLOSE_MENU", "CLOSE_MENU");
	instructionsAtlas.AddAction("MOVE_TO_NEXT_TURN", "MOVE_TO_NEXT_TURN");
	instructionsAtlas.AddAction("DISPLAY_DIALOG", "DISPLAY_DIALOG");
	instructionsAtlas.AddAction("SET_INTEGER", "SET_INTEGER");
	instructionsAtlas.AddAction("SET_REAL", "SET_REAL");
	instructionsAtlas.AddAction("SET_TEXT", "SET_TEXT");
	instructionsAtlas.AddAction("SET_FLAG", "SET_FLAG");
	instructionsAtlas.AddAction("WAIT", "WAIT");

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
