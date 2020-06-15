#include "Scripts/TriggerBuilder.h"

namespace scripts {
	scripts::TriggerBuilder::TriggerBuilder()
	{
		Reset();
	}

	void scripts::TriggerBuilder::Reset()
	{
		trigger = std::unique_ptr<scripts::Trigger>(new scripts::Trigger);
		instruction = std::unique_ptr<scripts::ScriptInstruction>(new scripts::ScriptInstruction);
		instructionsAtlas = nullptr;
	}

	std::shared_ptr<scripts::Trigger> scripts::TriggerBuilder::GetResult()
	{
		return std::move(trigger);
	}

	void scripts::TriggerBuilder::SetAtlas(std::vector<std::string>& instructionAtlas)
	{
		this->instructionsAtlas = &instructionAtlas;
	}

	bool scripts::TriggerBuilder::IsExistingInstruction(const std::string& instruction)
	{
		if (instructionsAtlas != nullptr)
			return std::any_of(instructionsAtlas->begin(), instructionsAtlas->end(), [instruction](std::string str) { return instruction == str; });
		return false;
	}

	void scripts::TriggerBuilder::AddInstruction(const std::string& instructionName)
	{
		this->instruction = std::unique_ptr<scripts::ScriptInstruction>(new scripts::ScriptInstruction(instructionName));
	}

	void scripts::TriggerBuilder::AddArgument(const std::string& argument)
	{
		instruction->AddArgument(argument);
	}

	void scripts::TriggerBuilder::BuildEvent()
	{
		trigger->AddEvent(std::move(instruction));
	}

	void scripts::TriggerBuilder::BuildCondition()
	{
		trigger->AddCondition(std::move(instruction));
	}

	void scripts::TriggerBuilder::BuildAction()
	{
		trigger->AddAction(std::move(instruction));
	}
}