#ifndef SCRIPTS_INSTRUCTIONS_LOADER_H
#define SCRIPTS_INSTRUCTIONS_LOADER_H

#include "Scripts/Lexer.h"
#include "Scripts/InstructionsAtlas.h"
#include <memory>

namespace scripts {
	class InstructionsLoader {

		enum class InstructionType {
			event, condition, action
		} currentInstructionType;

		Lexer lexer;
		std::queue<std::string> phrasesQueue;
		scripts::InstructionsAtlas* atlas;
	public:
		InstructionsLoader(scripts::InstructionsAtlas* instructionsAtlas);
		void LoadInstructionsFromFile(const std::string& source);
	};
}
#endif // !SCRIPTS_INSTRUCTIONS_LOADER_H