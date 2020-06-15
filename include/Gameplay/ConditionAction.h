#ifndef GAME_CONDITION_ACTION_H
#define GAME_CONDITION_ACTION_H

#include "Gameplay/Action.h"

namespace game {
	class ConditionAction : public game::Action {
	public:
		ConditionAction(std::function<bool()> const& condition, std::function<void()> const& slot);
		virtual bool CheckConditions();
		virtual void AddCondition(std::function<bool()> const& condition);
		virtual void Execute() override;
	private:
		std::vector <std::function<bool()>> conditions;
		
	};
}

#endif // !GAME_CONDITION_ACTION_H
