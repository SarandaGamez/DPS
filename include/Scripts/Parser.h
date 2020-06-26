#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <memory>
#include <set>

#include "Scripts/Trigger.h"
#include "Scripts/TriggerBuilder.h"
#include "Scripts/InstructionsSet.h"

namespace scripts {
	class Parser {
		std::set<std::string>* currentAtlas;
		scripts::InstructionsSet* instructionsAtlas;

		std::vector<std::shared_ptr<scripts::Trigger>> triggers;

		bool isTriggerFound = false;
		bool isLookingForArguments = false;
		bool isInstructionFound = false;

		scripts::TriggerBuilder triggerBuilder;

	public:
		Parser();
		void ConnectToInstructionsAtlas(scripts::InstructionsSet* instructionsAtlas);
		void CheckSyntax(std::string phrase);
		std::vector<std::shared_ptr<scripts::Trigger>>* ReturnResult();
	private:

		bool IsInstructionExisting(const std::string& value);
		bool IsSpecialCharacter(char character);

		enum class LoadingState {
			nothing, event, condition, action
		} loadingState = LoadingState::nothing;
	};
}
#endif //!PARSER_H