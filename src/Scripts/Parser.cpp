#include "Scripts/Parser.h"
#include <iostream>

namespace scripts {
	const std::string TRIGGER_SYNTAX = "TRIGGER";
	const std::string EVENT_SYNTAX = "WHEN";
	const std::string CONDITION_SYNTAX = "IF";
	const std::string ACTION_SYNTAX = "ACTIONS";

	Parser::Parser()
	{
		currentAtlas = nullptr;
	}

	void Parser::ConnectToInstructionsAtlas(scripts::InstructionsAtlas* instructionsAtlas)
	{
		this->instructionsAtlas = instructionsAtlas;
	}

	void Parser::CheckSyntax(std::string phrase)
	{
		std::transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);

		if (phrase == TRIGGER_SYNTAX) {
			isTriggerFound = true;
			triggerBuilder.Reset();
		}
		else if (isTriggerFound == true) {

			if (phrase[0] == '(' && isInstructionFound == true && isLookingForArguments == false) {
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
				currentAtlas = instructionsAtlas->GetEventsAtlas();
				loadingState = LoadingState::event;
			}
			else if (phrase == CONDITION_SYNTAX) {
				loadingState = LoadingState::condition;
				currentAtlas = instructionsAtlas->GetConditionsAtlas();
			}
			else if (phrase == ACTION_SYNTAX) {
				loadingState = LoadingState::action;
				currentAtlas = instructionsAtlas->GetActionsAtlas();
			}
			else if (phrase == "}") {
				triggers.push_back(triggerBuilder.GetResult());
				isTriggerFound = false;
			}
			else if (isLookingForArguments == true) {
				if (IsSpecialCharacter(phrase[0]) == false || phrase[0] == '$')
					triggerBuilder.AddArgument(phrase);
			}
			else if (isInstructionFound == false && IsInstructionExisting(phrase)) {
				isInstructionFound = true;
				triggerBuilder.AddInstruction(phrase);
			}
		}
	}

	std::vector<std::shared_ptr<scripts::Trigger>>* scripts::Parser::ReturnResult()
	{
		return &triggers;
	}

	bool Parser::IsInstructionExisting(const std::string& value)
	{
		if (currentAtlas != nullptr) {
			auto valueFinder = currentAtlas->begin();
			valueFinder = currentAtlas->find(value);
			return valueFinder != currentAtlas->end();
		}
		return false;
	}

	bool scripts::Parser::IsSpecialCharacter(char character)
	{
		std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', ':', ',', '.', '=', '#', '$' };
		return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c) { return character == c; });
	}
}