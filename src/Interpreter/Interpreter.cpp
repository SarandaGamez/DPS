#include "Interpreter/Interpreter.h"
#include <fstream>
#include <iostream>

namespace scripts {
	void Interpreter::LoadScriptFromFile(const std::string& source)
	{
		std::fstream file(source, std::ios::in | std::ios::out);

		if (file.good())
		{
			std::string line;
			while (!file.eof())
			{
				std::getline(file, line);
				auto queue = lexer.FindPhrases(line);

				while (!queue.empty())
				{
					phrasesQueue.push(queue.front());
					queue.pop();
				}
			}
			file.close();
		}

		while (!phrasesQueue.empty())
		{
			parser.CheckSyntax(phrasesQueue.front());
			phrasesQueue.pop();
		}
		triggers = parser.ReturnResult();

	}

	void Interpreter::ShowLoadedPhrases()
	{
		while (!phrasesQueue.empty())
		{
			std::cout << phrasesQueue.front() << std::endl;
			phrasesQueue.pop();
		}
	}

	std::vector<std::shared_ptr<Trigger>>* Interpreter::GetLoadedTriggers()
	{
		return triggers;
	}
}