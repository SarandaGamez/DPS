#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <memory>

#include "Scripts/Trigger.h"
#include "Scripts/TriggerBuilder.h"
#include "Scripts/InstructionsAtlas.h"

namespace scripts {
	class Parser {
		std::map<std::string, std::string>* currentAtlas;
		scripts::InstructionsAtlas* instructionsAtlas;

		std::vector<std::shared_ptr<scripts::Trigger>> triggers;

		bool isTriggerFound = false;
		bool isLookingForArguments = false;
		bool isInstructionFound = false;

		scripts::TriggerBuilder triggerBuilder;

	public:
		Parser();
		void ConnectToInstructionsAtlas(scripts::InstructionsAtlas* instructionsAtlas);
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