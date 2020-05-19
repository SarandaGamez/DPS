#ifndef UITLS_STRING_UTILS_H
#define UTILS_STRING_UTILS_H

#include <string>>

namespace utils {

	class StringUtils {
	public:
		static std::string BreakLines(const std::string& text, unsigned int numberOfCharactersInLine);
	};
}

#endif // !UITLS_STRING_UTILS_H
