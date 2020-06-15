#ifndef SCRIPTS_SCRIPT_INSTRUCTION_H
#define SCRIPTS_SCRIPT_INSTRUCTION_H

#include <string>
#include <vector>

namespace scripts {
	class ScriptInstruction {
		std::string name;
		std::vector<std::string> arguments;

	public:
		ScriptInstruction(std::string name);
		ScriptInstruction();

		void SetName(std::string name);
		std::string GetName();

		void AddArgument(std::string argument);
		std::vector<std::string>::const_iterator GetArgumentsBegin();
		std::vector<std::string>::const_iterator GetArgumentsEnd();

		void Clear();
	};
}

#endif // !SCRIPTS_SCRIPT_INSTRUCTION_H