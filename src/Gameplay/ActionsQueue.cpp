#include "Gameplay/ActionsQueue.h"

void game::ActionsQueue::Push(game::Action* action)
{
	actions.push(std::shared_ptr<game::Action>(action));
}

void game::ActionsQueue::ExecuteAndPop()
{
	actions.front()->Execute();
	actions.pop();
}

bool game::ActionsQueue::IsEmpty()
{
	return actions.empty();
}
