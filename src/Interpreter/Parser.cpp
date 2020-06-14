#include "Interpreter/Parser.h"
#include <iostream>

namespace scripts {
	Parser::Parser()
	{
		eventsAtlas.push_back("GAME_INITIALIZED");
		eventsAtlas.push_back("EVERY_SEC_MIN");
		eventsAtlas.push_back("EVERY_SEC");
		eventsAtlas.push_back("EVERY");
		eventsAtlas.push_back("CLICKED_FAX");
		eventsAtlas.push_back("CLICKED_MAP");
		eventsAtlas.push_back("CLICKED_NOTEPAD");
		eventsAtlas.push_back("CLICKED_NEXTTURN");
		eventsAtlas.push_back("CLICKED_MENU");
		eventsAtlas.push_back("TURN_CHANGE_FINISHED");
		eventsAtlas.push_back("TURN_CHANGE_STARTED");
		eventsAtlas.push_back("TURN_CHANGE_INTERRUPTED");
		eventsAtlas.push_back("CLOSED_FAX");
		eventsAtlas.push_back("CLOSED_MAP");
		eventsAtlas.push_back("CLOSED_NOTEPAD");
		eventsAtlas.push_back("CLOSED_MENU");
		eventsAtlas.push_back("OPENED_FAX");
		eventsAtlas.push_back("OPENED_MAP");
		eventsAtlas.push_back("OPENED_NOTEPAD");
		eventsAtlas.push_back("OPENED_MENU");

		conditionsAtlas.push_back("IS_FAX_OPEN");
		conditionsAtlas.push_back("IS_MAP_OPEN");
		conditionsAtlas.push_back("IS_NOTEPAD_OPEN");
		conditionsAtlas.push_back("IS_MENU_OPEN");
		conditionsAtlas.push_back("IS_FAX_CLOSE");
		conditionsAtlas.push_back("IS_MAP_CLOSE");
		conditionsAtlas.push_back("IS_NOTEPAD_CLOSE");
		conditionsAtlas.push_back("IS_MENU_CLOSE");
		conditionsAtlas.push_back("IS_EQUAL");
		conditionsAtlas.push_back("IS_GREATER_THAN");
		conditionsAtlas.push_back("IS_LESS_THAN");
		conditionsAtlas.push_back("IS_GREATER_OR_EQUAL");
		conditionsAtlas.push_back("IS_LESS_OR_EQUAL");
		conditionsAtlas.push_back("IS_TRUE");
		conditionsAtlas.push_back("IS_FALSE");

		actionsAtlas.push_back("SHOW_FAX_BUTTON");
		actionsAtlas.push_back("SHOW_MAP_BUTTON");
		actionsAtlas.push_back("SHOW_NOTEPAD_BUTTON");
		actionsAtlas.push_back("SHOW_MENU_BUTTON");
		actionsAtlas.push_back("OPEN_FAX");
		actionsAtlas.push_back("OPEN_MAP");
		actionsAtlas.push_back("OPEN_NOTEPAD");
		actionsAtlas.push_back("OPEN_MENU");
		actionsAtlas.push_back("CLOSE_FAX");
		actionsAtlas.push_back("CLOSE_MAP");
		actionsAtlas.push_back("CLOSE_NOTEPAD");
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

		if (phrase == "TRIGGER") {
			isTriggerFound = true;
			tempTrigger = std::shared_ptr<Trigger>(new Trigger);
		}
		else if (phrase == "WHEN") {
			loadingState = LoadingState::event;
		}
		else if (phrase == "IF") {
			loadingState = LoadingState::condition;
		}
		else if (phrase == "ACTIONS") {
			loadingState = LoadingState::action;
		}


		if (phrase == "}") {
			triggers.push_back(tempTrigger);
			isTriggerFound = false;
		}
		else if (isTriggerFound == true) {

			switch (loadingState)
			{
			case LoadingState::event:
				if (isInstructionFound == false && IsEventInstruction(phrase)) {
					CreateInstruction(phrase);
				}
				else if (isInstructionFound == true) {
					LoadEvent(phrase);
				}
				break;
			case LoadingState::condition:
				if (isInstructionFound == false && IsConditionInstruction(phrase)) {
					CreateInstruction(phrase);
				}
				else if (isInstructionFound == true) {
					LoadCondition(phrase);
				}
				break;
			case LoadingState::action:
				if (isInstructionFound == false && IsActionInstruction(phrase)) {
					CreateInstruction(phrase);
				}
				else if (isInstructionFound == true) {
					LoadAction(phrase);
				}
				break;
			}
		}
	}


	std::vector<std::shared_ptr<Trigger>>* Parser::ReturnResult()
	{
		return &triggers;
	}

	bool Parser::IsEventInstruction(const std::string& phrase)
	{
		return std::any_of(eventsAtlas.begin(), eventsAtlas.end(), [phrase](std::string str) { return phrase == str; });
	}

	bool Parser::IsConditionInstruction(const std::string& phrase)
	{
		return std::any_of(conditionsAtlas.begin(), conditionsAtlas.end(), [phrase](std::string str) { return phrase == str; });
	}

	bool Parser::IsActionInstruction(const std::string& phrase)
	{
		return std::any_of(actionsAtlas.begin(), actionsAtlas.end(), [phrase](std::string str) { return phrase == str; });
	}

	void Parser::LoadEvent(const std::string& phrase)
	{
		if (phrase[0] == '(') {
			isLookingForArguments = true;
		}
		else if (isLookingForArguments == true) {
			if (IsSpecialCharacter(phrase[0]) == false || phrase[0] == '$')
				tempInstruction->AddArgument(phrase);
		}
		else if (phrase[0] == ')' || isLookingForArguments == false) {
			FinishEventLoading();
		}
	}

	void Parser::LoadCondition(const std::string& phrase)
	{
		if (phrase[0] == '(') {
			isLookingForArguments = true;
		}
		else if (isLookingForArguments == true) {
			if (IsSpecialCharacter(phrase[0]) == false || phrase[0] == '$')
				tempInstruction->AddArgument(phrase);
		}
		else if (phrase[0] == ')' || isLookingForArguments == false) {
			FinishConditionLoading();
		}
	}

	void Parser::LoadAction(const std::string& phrase)
	{
		if (phrase[0] == '(') {
			isLookingForArguments = true;
		}
		else if (isLookingForArguments == true) {
			if (IsSpecialCharacter(phrase[0]) == false || phrase[0] == '$')
				tempInstruction->AddArgument(phrase);
		}
		if (phrase[0] == ')' || isLookingForArguments == false) {
			FinishActionLoading();
		}
	}

	void Parser::FinishEventLoading()
	{
		isInstructionFound = false;
		tempTrigger->AddEvent(tempInstruction);
		loadingState = LoadingState::nothing;
	}

	void Parser::FinishConditionLoading()
	{
		isInstructionFound = false;
		tempTrigger->AddCondition(tempInstruction);
		loadingState = LoadingState::nothing;
	}

	void Parser::FinishActionLoading()
	{
		isInstructionFound = false;
		tempTrigger->AddAction(tempInstruction);
		loadingState = LoadingState::nothing;
	}

	void Parser::CreateInstruction(const std::string& phrase)
	{
		tempInstruction = std::shared_ptr<ScriptInstruction>(new ScriptInstruction);
		tempInstruction->SetName(phrase);
		isInstructionFound = true;
	}

	void Parser::LoadArgument(const std::string& phrase)
	{
	}

	bool Parser::IsSpecialCharacter(char character)
	{
		std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', ':', ',', '.', '=', '#', '$' };
		return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c) { return character == c; });
	}

	bool Parser::IsPartOfCodeSyntax(const std::string& phrase)
	{
		std::vector<std::string> stringsArray = { "TRIGGER:", "WHEN:", "IF:", "ACTION:" };
		return std::any_of(stringsArray.begin(), stringsArray.end(), [phrase](std::string str) { return phrase == str; });
	}
}