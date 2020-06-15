#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>
#include <memory>

#include "Scripts/Trigger.h"
#include "Scripts/TriggerBuilder.h"

namespace scripts {
	class Parser {
		std::vector<std::string> eventsAtlas;
		std::vector<std::string> conditionsAtlas;
		std::vector<std::string> actionsAtlas;

		std::vector<std::shared_ptr<scripts::Trigger>> triggers;

		bool isTriggerFound = false;
		bool isLookingForArguments = false;
		bool isInstructionFound = false;

		scripts::TriggerBuilder triggerBuilder;

	public:
		Parser();
		void CheckSyntax(std::string phrase);
		std::vector<std::shared_ptr<scripts::Trigger>>* ReturnResult();
	private:

		bool IsSpecialCharacter(char character);

		enum class LoadingState {
			nothing, event, condition, action
		} loadingState = LoadingState::nothing;
	};
}
#endif //!PARSER_H