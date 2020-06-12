#ifndef GAME_ACTIONS_QUEUE_H
#define GAME_ACTIONS_QUEUE_H

#include "Gameplay/Action.h"
#include <queue>
#include <memory>
#include <SFML/System/Time.hpp>

namespace game {
	class ActionsQueue {
	public:
		void Push(game::Action* action);
		void ExecuteAndPop();
		bool IsEmpty() const;
		bool IsReadyForNext() const;
		void SetReadyForNext(bool isReady);
		bool IsWaiting() const;
		void Wait(unsigned int milliseconds);
		void UpdateElapsedTime(sf::Time elapsedTime);
	private:
		std::queue<std::shared_ptr<game::Action>> actions;
		bool isReadyForNext = false;
		bool isWaiting;
		unsigned int waitTime;
		sf::Time elapsedTime;
	};
}

#endif // !GAME_ACTIONS_QUEUE_H
