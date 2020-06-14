#include "Interpreter\ScriptInstruction.h"

namespace scripts {
	ScriptInstruction::ScriptInstruction(std::string name)
	{
		this->name = name;
	}

	ScriptInstruction::ScriptInstruction()
	{
	}

	void ScriptInstruction::SetName(std::string name)
	{
		this->name = name;
	}

	std::string ScriptInstruction::GetName()
	{
		return name;
	}

	void ScriptInstruction::AddArgument(std::string argument)
	{
		this->arguments.push_back(argument);
	}

	std::vector<std::string>::const_iterator ScriptInstruction::GetArgumentsBegin()
	{
		return arguments.cbegin();
	}

	std::vector<std::string>::const_iterator ScriptInstruction::GetArgumentsEnd()
	{
		return arguments.cend();
	}

	void ScriptInstruction::Clear()
	{
		name = "[EMPTY]";
		arguments.clear();
	}
}