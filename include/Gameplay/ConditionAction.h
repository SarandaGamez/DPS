#ifndef GAME_CONDITION_ACTION_H
#define GAME_CONDITION_ACTION_H

#include "Gameplay/Action.h"

namespace game {
	class ConditionAction : public game::Action {
	public:
		ConditionAction(std::function<void()> const& slot, std::function<bool()> const& conditions);
		virtual bool CheckConditions();
		virtual void Execute() override;
	private:
		std::function<bool()> conditions;
	};
}

#endif // !GAME_CONDITION_ACTION_H
