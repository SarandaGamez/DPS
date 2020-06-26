#include "Scripts/InstructionsLoader.h"
#include <fstream>

namespace scripts {
	InstructionsLoader::InstructionsLoader(scripts::InstructionsAtlas* instructionsAtlas)
	{
		this->atlas = instructionsAtlas;
	}
	void scripts::InstructionsLoader::LoadInstructionsFromFile(const std::string& source)
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

		std::string key = "";
		currentInstructionType = InstructionType::event;
		while (!phrasesQueue.empty())
		{
			std::string frontPhrase = phrasesQueue.front();
			phrasesQueue.pop();

			if (frontPhrase == ";") {
				switch (currentInstructionType)
				{
				case scripts::InstructionsLoader::InstructionType::event:
					currentInstructionType = InstructionType::condition;
					break;
				case scripts::InstructionsLoader::InstructionType::condition:
					currentInstructionType = InstructionType::action;
					break;
				case scripts::InstructionsLoader::InstructionType::action:
					currentInstructionType = InstructionType::condition;
					break;
				}
			}

			else if (key != "") {
				switch (currentInstructionType)
				{
				case scripts::InstructionsLoader::InstructionType::event:
					atlas->AddEvent(key, frontPhrase);
					break;
				case scripts::InstructionsLoader::InstructionType::condition:
					atlas->AddCondition(key, frontPhrase);
					break;
				case scripts::InstructionsLoader::InstructionType::action:
					atlas->AddAction(key, frontPhrase);
					break;
				}
				key = "";
			}
			else {
				key = frontPhrase;
			}
		}
	}
}