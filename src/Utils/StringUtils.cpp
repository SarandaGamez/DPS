#include "Utils/StringUtils.h"

std::string utils::StringUtils::BreakLines(const std::string& text, unsigned int numberOfCharactersInLine)
{
	if (text.length() > numberOfCharactersInLine) {

		int blankSpaceIndex = 0;
		std::string breakText = text;
		int numberOfLines = (text.length() - (text.length() % numberOfCharactersInLine)) / numberOfCharactersInLine;

		for (int k = 0; k < numberOfLines; k++) {
			for (int i = k * numberOfCharactersInLine; i < numberOfCharactersInLine + numberOfCharactersInLine * k; i++) {
				if (text[i] == ' ')
					blankSpaceIndex = i;
			}
			breakText[blankSpaceIndex] = '\n';
		}

		return breakText;
	}
}
