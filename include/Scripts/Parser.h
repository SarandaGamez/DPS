#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <memory>

#include "Scripts/Trigger.h"

namespace scripts {
	class Parser {
		std::vector<std::string> eventsAtlas;
		std::vector<std::string> conditionsAtlas;
		std::vector<std::string> actionsAtlas;

		std::vector<std::shared_ptr<Trigger>> triggers;

		std::shared_ptr<ScriptInstruction> tempInstruction;
		std::shared_ptr<Trigger> tempTrigger;

		bool isTriggerFound = false;
		bool isLookingForArguments = false;
		bool isInstructionFound = false;

	public:
		Parser();
		void CheckSyntax(std::string phrase);
		std::vector<std::shared_ptr<Trigger>>* ReturnResult();
	private:
		bool IsEventInstruction(const std::string& phrase);
		bool IsConditionInstruction(const std::string& phrase);
		bool IsActionInstruction(const std::string& phrase);

		void LoadEvent(const std::string& phrase);
		void LoadCondition(const std::string& phrase);
		void LoadAction(const std::string& phrase);

		void FinishEventLoading();
		void FinishConditionLoading();
		void FinishActionLoading();

		void CreateInstruction(const std::string& phrase);
		void LoadArgument(const std::string& phrase);

		bool IsSpecialCharacter(char character);
		bool IsPartOfCodeSyntax(const std::string& phrase);

		enum class LoadingState {
			nothing, event, condition, action
		} loadingState = LoadingState::nothing;
	};
}
#endif //!PARSER_H