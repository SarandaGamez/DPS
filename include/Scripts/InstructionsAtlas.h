#ifndef SCRIPTS_INSTRUCTIONS_ATLAS_H
#define SCRIPTS_INSTRUCTIONS_ATLAS_H

#include <map>
#include <string>

namespace scripts {
	class InstructionsAtlas {
	public:
		void AddEvent(const std::string& key, const std::string& event);
		void AddCondition(const std::string& key, const std::string& condition);
		void AddAction(const std::string& key, const std::string& action);

		const std::string& GetEvent(const std::string& key) const;
		const std::string& GetCondition(const std::string& key) const;
		const std::string& GetAction(const std::string& key) const;

		std::map<std::string, std::string>* GetEventsAtlas();
		std::map<std::string, std::string>* GetConditionsAtlas();
		std::map<std::string, std::string>* GetActionsAtlas();
	private:
		std::map<std::string, std::string> events;
		std::map<std::string, std::string> conditions;
		std::map<std::string, std::string> actions;
	};
}

#endif // !SCRIPTS_INSTRUCTIONS_ATLAS_H
