#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include "Utils/Signal.h"

namespace game {
	class Action{
	public:
		Action(std::function<void()> const& slot);
		virtual void Execute();
	private:
		utils::Signal signal;
	};
}

#endif // !GAME_ACTION_H