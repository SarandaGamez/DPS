#include "Scripts/Lexer.h"

namespace scripts {
	std::queue<std::string> Lexer::FindPhrases(const std::string& line)
	{
		std::string phrase;
		std::queue<std::string> phrasesQueue;

		for (auto character : line)
		{
			if (phrase == "//")
				return phrasesQueue;

			if (backslashFound == true) {
				backslashFound = false;
				if (character == 'n') {
					phrase.push_back('\n');
					phrasesQueue.push(phrase);
					phrase.clear();
					continue;
				}
			}

			if (IsSpecialCharacter(character))
			{
				if (character == '\\') {
					backslashFound = true;
				}

				if (!phrase.empty())
				{
					phrasesQueue.push(phrase);
					phrase.clear();
				}

				if (character != '	' && character != ' ' && character != '\\')
				{
					phrase.push_back(character);
					phrasesQueue.push(phrase);
					phrase.clear();
				}

			}
			else
			{
				phrase.push_back(character);
			}
		}

		if (!phrase.empty())
			phrasesQueue.push(phrase);

		return phrasesQueue;
	}

	bool Lexer::IsSpecialCharacter(const char& character) const
	{
		std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', '.', '=', '\\' };
		return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c) { return character == c; });
	}
}