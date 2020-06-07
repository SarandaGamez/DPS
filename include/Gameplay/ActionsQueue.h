#ifndef GAME_ACTIONS_QUEUE_H
#define GAME_ACTIONS_QUEUE_H

#include "Gameplay/Action.h"
#include <queue>
#include <memory>

namespace game {
	class ActionsQueue {
	public:
		void Push(game::Action* action);
		void ExecuteAndPop();
		bool IsEmpty() const;
		bool IsReadyForNext() const;
		void SetReadyForNext(bool isReady);
	private:
		std::queue<std::shared_ptr<game::Action>> actions;
		bool isReadyForNext = false;
	};
}

#endif // !GAME_ACTIONS_QUEUE_H
