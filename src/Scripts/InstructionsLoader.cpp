#include "Scripts/InstructionsLoader.h"
#include <fstream>

namespace scripts {
	InstructionsLoader::InstructionsLoader(scripts::InstructionsSet* instructionsAtlas)
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

			switch (currentInstructionType)
			{
			case scripts::InstructionsLoader::InstructionType::event:
				atlas->AddEvent(frontPhrase);
				break;
			case scripts::InstructionsLoader::InstructionType::condition:
				atlas->AddCondition(frontPhrase);
				break;
			case scripts::InstructionsLoader::InstructionType::action:
				atlas->AddAction(frontPhrase);
				break;
			}

		}
	}
}