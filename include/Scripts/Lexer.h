#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <queue>

namespace scripts {
	class Lexer {
	public:
		std::queue<std::string> FindPhrases(const std::string& line);
	private:
		bool IsSpecialCharacter(const char& character) const;
		bool backslashFound = false;
	};
}

#endif // !LEXER_H
