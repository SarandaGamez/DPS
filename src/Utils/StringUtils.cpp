#include "Utils/StringUtils.h"
#include <vector>

std::vector<unsigned int> findLocation(std::string sample, char findIt)
{
	std::vector<unsigned int> characterLocations;
	for (int i = 0; i < sample.size(); i++)
		if (sample[i] == findIt)
			characterLocations.push_back(i);

	return characterLocations;
}

void BreakNextWordFromIndex(std::string& textToBreak, unsigned int fromIndex){
	size_t index = textToBreak.find(' ', fromIndex);
	textToBreak[index] = '\n';
}

void BreakMultipleLinesFromIndex(std::string& textToBreak, unsigned int beginFromIndex, unsigned int numberOfCharactersInLine, unsigned int numberOfLinesAfterBreak) {
	for (int j = 1; j <= numberOfLinesAfterBreak; j++) {
		BreakNextWordFromIndex(textToBreak, beginFromIndex + numberOfCharactersInLine * j);
	}
}

void BreakTheRestFromIndex(std::string& textToBreak, const std::vector<unsigned int>& existingBreaks, unsigned int numberOfCharactersInLine) {
	unsigned int charactersLeft = textToBreak.length() - existingBreaks[existingBreaks.size() - 1];
	if (charactersLeft > numberOfCharactersInLine) {
		unsigned int numberOfLinesAfterBreak = charactersLeft / numberOfCharactersInLine;
		unsigned int lastExistingBreak = existingBreaks[existingBreaks.size() - 1];
		BreakMultipleLinesFromIndex(textToBreak, lastExistingBreak, numberOfCharactersInLine, numberOfLinesAfterBreak);
	}
}

void BreakTextWithExistingBreaks(std::string& textToBreak, const std::vector<unsigned int>& existingBreaks, unsigned int numberOfCharactersInLine) {
	for (int i = 0; i < existingBreaks.size() - 1; i++) {
		int numberOfLinesAfterBreak = (existingBreaks[i + 1] - existingBreaks[i]) / numberOfCharactersInLine;
		BreakMultipleLinesFromIndex(textToBreak, existingBreaks[i], numberOfCharactersInLine, numberOfLinesAfterBreak);
	}
	BreakTheRestFromIndex(textToBreak, existingBreaks, numberOfCharactersInLine);
}

void BreakTextWithoutExistingBreaks(std::string& textToBreak, unsigned int numberOfCharactersInLine) {
	int blankSpaceIndex = 0;
	int numberOfLinesAfterBreak = (textToBreak.length() - (textToBreak.length() % numberOfCharactersInLine)) / numberOfCharactersInLine;
	for (int k = 0; k < numberOfLinesAfterBreak; k++) {
		for (int i = k * numberOfCharactersInLine; i < numberOfCharactersInLine + numberOfCharactersInLine * k; i++) {
			if (textToBreak[i] == ' ')
				blankSpaceIndex = i;
		}
		textToBreak[blankSpaceIndex] = '\n';
	}
}

std::string utils::StringUtils::BreakLines(const std::string& text, unsigned int numberOfCharactersInLine)
{
	if (text.length() > numberOfCharactersInLine) {
		std::string textToBreak = text;
		std::vector<unsigned int> existingBreaks = findLocation(text, '\n');

		if (existingBreaks.empty() == false) {
			unsigned int numberOfLinesAfterBreak = existingBreaks[0] / numberOfCharactersInLine;
			BreakMultipleLinesFromIndex(textToBreak, 0, numberOfCharactersInLine, numberOfLinesAfterBreak);
		}

		if (existingBreaks.size() >= 2)
			BreakTextWithExistingBreaks(textToBreak, existingBreaks, numberOfCharactersInLine);
		else
			BreakTextWithoutExistingBreaks(textToBreak, numberOfCharactersInLine);

		return textToBreak;
	}
	return text;
}
