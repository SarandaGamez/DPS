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

			if (IsSpecialCharacter(character))
			{
				if (!phrase.empty())
				{
					phrasesQueue.push(phrase);
					phrase.clear();
				}

				if (character != '	' && character != ' ')
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
		std::vector<char> charactersArray = { ' ', '\t', '{', '}', '(', ')', '"', ';', ',', '.', '=' };
		return std::any_of(charactersArray.begin(), charactersArray.end(), [character](char c) { return character == c; });
	}
}