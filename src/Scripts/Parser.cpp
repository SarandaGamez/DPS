#include "Scripts/Parser.h"
#include <iostream>

namespace scripts {
	const std::string TRIGGER_SYNTAX = "TRIGGER";
	const std::string EVENT_SYNTAX = "WHEN";
	const std::string CONDITION_SYNTAX = "IF";
	const std::string ACTION_SYNTAX = "ACTIONS";

	Parser::Parser()
	{
		eventsAtlas.push_back("GAME_INITIALIZED");
		eventsAtlas.push_back("EVERY_SEC_MIN");
		eventsAtlas.push_back("EVERY_SEC");
		eventsAtlas.push_back("EVERY");
		eventsAtlas.push_back("CLICKED_FAX");
		eventsAtlas.push_back("CLICKED_MAP");
		eventsAtlas.push_back("CLICKED_NOTEBOOK");
		eventsAtlas.push_back("CLICKED_NEXTTURN");
		eventsAtlas.push_back("CLICKED_MENU");
		eventsAtlas.push_back("TURN_CHANGE_FINISHED");
		eventsAtlas.push_back("TURN_CHANGE_STARTED");
		eventsAtlas.push_back("TURN_CHANGE_INTERRUPTED");
		eventsAtlas.push_back("CLOSED_FAX");
		eventsAtlas.push_back("CLOSED_MAP");
		eventsAtlas.push_back("CLOSED_NOTEBOOK");
		eventsAtlas.push_back("CLOSED_MENU");
		eventsAtlas.push_back("OPENED_FAX");
		eventsAtlas.push_back("OPENED_MAP");
		eventsAtlas.push_back("OPENED_NOTEBOOK");
		eventsAtlas.push_back("OPENED_MENU");

		conditionsAtlas.push_back("IS_FAX_OPEN");
		conditionsAtlas.push_back("IS_MAP_OPEN");
		conditionsAtlas.push_back("IS_NOTEBOOK_OPEN");
		conditionsAtlas.push_back("IS_MENU_OPEN");
		conditionsAtlas.push_back("IS_FAX_CLOSE");
		conditionsAtlas.push_back("IS_MAP_CLOSE");
		conditionsAtlas.push_back("IS_NOTEBOOK_CLOSE");
		conditionsAtlas.push_back("IS_MENU_CLOSED");
		conditionsAtlas.push_back("IS_EQUAL");
		conditionsAtlas.push_back("IS_GREATER_THAN");
		conditionsAtlas.push_back("IS_LESS_THAN");
		conditionsAtlas.push_back("IS_GREATER_OR_EQUAL");
		conditionsAtlas.push_back("IS_LESS_OR_EQUAL");
		conditionsAtlas.push_back("IS_TRUE");
		conditionsAtlas.push_back("IS_FALSE");
		conditionsAtlas.push_back("TEST_CONDITION");

		actionsAtlas.push_back("SHOW_FAX_BUTTON");
		actionsAtlas.push_back("SHOW_MAP_BUTTON");
		actionsAtlas.push_back("SHOW_NOTEBOOK_BUTTON");
		actionsAtlas.push_back("SHOW_MENU_BUTTON");
		actionsAtlas.push_back("HIDE_FAX_BUTTON");
		actionsAtlas.push_back("HIDE_MAP_BUTTON");
		actionsAtlas.push_back("HIDE_NOTEBOOK_BUTTON");
		actionsAtlas.push_back("HIDE_MENU_BUTTON");
		actionsAtlas.push_back("OPEN_FAX");
		actionsAtlas.push_back("OPEN_MAP");
		actionsAtlas.push_back("OPEN_NOTEBOOK");
		actionsAtlas.push_back("OPEN_MENU");
		actionsAtlas.push_back("CLOSE_FAX");
		actionsAtlas.push_back("CLOSE_MAP");
		actionsAtlas.push_back("CLOSE_NOTEBOOK");
		actionsAtlas.push_back("CLOSE_MENU");
		actionsAtlas.push_back("MOVE_TO_NEXT_TURN");
		actionsAtlas.push_back("DISPLAY_DIALOG");
		actionsAtlas.push_back("SET_INTEGER");
		actionsAtlas.push_back("SET_REAL");
		actionsAtlas.push_back("SET_TEXT");
		actionsAtlas.push_back("SET_FLAG");
		actionsAtlas.push_back("WAIT");

	}

	void Parser::CheckSyntax(std::string phrase)
	{
		std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);

		if (phrase == TRIGGER_SYNTAX) {
			isTriggerFound = true;
			triggerBuilder.Reset();
		}
		else if (isTriggerFound == true) {

			if (phrase[0] == '(' && isLookingForArguments == false) {
				isLookingForArguments = true;
			}
			else if (phrase[0] == ')' && isLookingForArguments == true) {
				isLookingForArguments = false;
			}
			else if (isInstructionFound == true && isLookingForArguments == false) {
				isInstructionFound = false;
				switch (loadingState)
				{
				case LoadingState::event:
					triggerBuilder.BuildEvent();
					break;
				case LoadingState::condition:
					triggerBuilder.BuildCondition();
					break;
				case LoadingState::action:
					triggerBuilder.BuildAction();
					break;
				}
			}
			if (phrase == EVENT_SYNTAX) {
				loadingState = LoadingState::event;
				triggerBuilder.SetAtlas(eventsAtlas);
			}
			else if (phrase == CONDITION_SYNTAX) {
				loadingState = LoadingState::condition;
				triggerBuilder.SetAtlas(conditionsAtlas);
			}
			else if (phrase == ACTION_SYNTAX) {
				loadingState = LoadingState::action;
				triggerBuilder.SetAtlas(actionsAtlas);
			}
			else if (phrase == "}") {
				triggers.push_back(triggerBuilder.GetResult());
				isTriggerFound = false;
			}
			else if (isLookingForArguments == true) {
				if (IsSpecialCharacter(phrase[0]) == false || phrase[0] == '$')
					triggerBuilder.AddArgument(phrase);
			}
			else if (isInstructionFound == false && triggerBuilder.IsExistingInstruction(phrase)) {
				isInstructionFound = true;
				triggerBuilder.AddInstruction(phrase);
			}
		}
	}

	std::vector<std::shared_ptr<scripts::Trigger>>* scripts::Parser::ReturnResult()
	{
		return &triggers;
	}

	bool scripts::Parser::IsSpecialCharacter(char character)
	{
		std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', ':', ',', '.', '=', '#', '$' };
		return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c) { return character == c; });
	}
}