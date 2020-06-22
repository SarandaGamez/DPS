#ifndef SCRIPTS_VARIABLES_H
#define SCRIPTS_VARIABLES_H

#include <map>
#include <any>
#include <string>

namespace scripts {
	enum class VariableType {
		real, text, flag, integer
	};

	class Field {
	public:
		Field(const scripts::VariableType& type, const std::any& value);
		void SetValue(const std::any& value);
		void SetType(const scripts::VariableType& type);
		const std::any& GetValue() const;
		const scripts::VariableType& GetType() const;
	private:
		std::any value;
		scripts::VariableType type;
	};

	class Variables {
	public:
		const scripts::Field& Get(const std::string& key);
		void Add(const std::string& key, const scripts::VariableType& type, const std::any& value);
		bool IsType(const std::string& key, const scripts::VariableType& type);
		bool CheckIfExists(const std::string& key);
	private:
		std::map<std::string, scripts::Field*> fields;
	};
}

#endif // !SCRIPTS_VARIABLES_H
