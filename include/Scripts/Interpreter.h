#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "Lexer.h"
#include "Parser.h"
#include "Trigger.h"
#include <string>
#include <queue>
#include "Scripts/InstructionsSet.h"

namespace scripts {
	class Interpreter {
		Lexer lexer;
		Parser parser;
		std::queue<std::string> phrasesQueue;
		std::vector<std::shared_ptr<Trigger>>* triggers;
	public:
		void ConnectToInstructionsAtlas(scripts::InstructionsSet* instructionsAtlas);
		void LoadScriptFromFile(const std::string& source);
		void ShowLoadedPhrases();
		std::vector<std::shared_ptr<Trigger>>* GetLoadedTriggers();
	};
}

#endif // !INTERPRETER_H
