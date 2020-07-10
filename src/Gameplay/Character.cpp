#include "Gameplay/Character.h"

game::Character::Character()
{
	Character("", "", "", 0);
}

game::Character::Character(const std::string& name, const std::string& surname, const std::string& location, unsigned int age)
{
	SetName(name);
	SetSurname(surname);
	SetLocation(location);
	SetAge(age);
}

void game::Character::SetName(const std::string& name)
{
	this->name = name;
}

void game::Character::SetSurname(const std::string& surname)
{
	this->surname = surname;
}

void game::Character::SetLocation(const std::string& location)
{
	this->location = location
}

void game::Character::SetAge(unsigned int age)
{
	this->age = age;
}

const std::string& game::Character::GetName() const
{
	return this->name;
}

const std::string& game::Character::GetSurname() const
{
	return this->surname;
}

const std::string& game::Character::GetLocation() const
{
	return this->location;
}

const unsigned int game::Character::GetAge() const
{
	return this->age;
}
