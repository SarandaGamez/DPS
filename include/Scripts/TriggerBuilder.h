#ifndef SCRIPTS_TRIGGER_BUILDER_H
#define SCRIPTS_TRIGGER_BUILDER_H

#include "Scripts/Trigger.h"
#include "Scripts/ScriptInstruction.h"

namespace scripts {
	class TriggerBuilder {
		std::unique_ptr<scripts::Trigger> trigger;
		std::unique_ptr<scripts::ScriptInstruction> instruction;
		std::vector<std::string>* instructionsAtlas;
	public:
		TriggerBuilder();
		void Reset();
		std::shared_ptr<scripts::Trigger> GetResult();
		void SetAtlas(std::vector<std::string>& instructionAtlas);
		bool IsExistingInstruction(const std::string& instruction);
		void AddInstruction(const std::string& instructionName);
		void AddArgument(const std::string& argument);
		void BuildEvent();
		void BuildCondition();
		void BuildAction();

	};
}

#endif // !SCRIPTS_TRIGGER_BUILDER_H
