#ifndef SCRIPTS_INSTRUCTIONS_SET_H
#define SCRIPTS_INSTRUCTIONS_SET_H

#include <set>
#include <string>

namespace scripts {
	class InstructionsSet {
	public:
		void AddEvent(const std::string& event);
		void AddCondition(const std::string& condition);
		void AddAction(const std::string& action);

		std::set<std::string>* GetEventsAtlas();
		std::set<std::string>* GetConditionsAtlas();
		std::set<std::string>* GetActionsAtlas();

		bool IsEventInSet(const std::string& event);
		bool IsConditionInSet(const std::string& condtion);
		bool IsActionInSet(const std::string& action);
	private:
		std::set<std::string> events;
		std::set<std::string> conditions;
		std::set<std::string> actions;
	};
}

#endif // !SCRIPTS_INSTRUCTIONS_SET_H
