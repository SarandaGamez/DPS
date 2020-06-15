#ifndef TRIGGER_H
#define TRIGGER_H

#include <string>
#include <queue>
#include <vector>
#include <memory>
#include "ScriptInstruction.h"

namespace scripts {
	class Trigger {
		std::queue<std::shared_ptr<ScriptInstruction>> events;
		std::vector<std::shared_ptr<ScriptInstruction>> conditions;
		std::queue<std::shared_ptr<ScriptInstruction>> actions;

	public:
		void AddEvent(std::shared_ptr<ScriptInstruction> event);
		void AddCondition(std::shared_ptr<ScriptInstruction> condition);
		void AddAction(std::shared_ptr<ScriptInstruction> action);

		bool IsEventsQueueEmpty();
		bool IsActionsQueueEmpty();

		std::shared_ptr<ScriptInstruction> GetEventAndPop();
		std::shared_ptr<ScriptInstruction> GetActionAndPop();

		const std::vector<std::shared_ptr<ScriptInstruction>>& GetConditions();
	};
}
#endif // !TRIGGER_H