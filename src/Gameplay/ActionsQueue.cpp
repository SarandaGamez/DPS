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

bool game::ActionsQueue::IsEmpty() const
{
	return actions.empty();
}

bool game::ActionsQueue::IsReadyForNext() const
{
	return isReadyForNext;
}

void game::ActionsQueue::SetReadyForNext(bool isReady)
{
	this->isReadyForNext = isReady;
}
