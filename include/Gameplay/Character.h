#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>

namespace game {
	class Character {
	public:
		Character();
		Character(const std::string& name, const std::string& surname, const std::string& location, unsigned int age);
		void SetName(const std::string& name);
		void SetSurname(const std::string& surname);
		void SetLocation(const std::string& location);
		void SetAge(unsigned int age);

		const std::string& GetName() const;
		const std::string& GetSurname() const;
		const std::string& GetLocation() const;
		const unsigned int GetAge() const;
	private:
		std::string name;
		std::string surname;
		std::string location;
		unsigned int age;

	};
}

#endif // !GAME_CHARACTER_H
