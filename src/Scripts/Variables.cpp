#include "Scripts/Variables.h"

scripts::Field::Field(const scripts::VariableType& type, const std::any& value)
{
	this->type = type;
	this->value = value;
}

void scripts::Field::SetValue(const std::any& value)
{
	this->value = value;
}

void scripts::Field::SetType(const scripts::VariableType& type)
{
	this->type = type;
}

const std::any& scripts::Field::GetValue() const
{
	return value;
}

const scripts::VariableType& scripts::Field::GetType() const
{
	return type;
}

const scripts::Field& scripts::Variables::Get(const std::string& key)
{
	return *fields[key];
}

void scripts::Variables::Add(const std::string& key, const scripts::VariableType& type, const std::any& value)
{
	this->fields[key] = new scripts::Field(type, value);
}

bool scripts::Variables::IsType(const std::string& key, const scripts::VariableType& type)
{
	return fields[key]->GetType() == type;
}

bool scripts::Variables::CheckIfExists(const std::string& key)
{
	return fields.count(key) > 0;
}
