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

bool game::ActionsQueue::IsWaiting() const
{
	return this->isWaiting;
}

void game::ActionsQueue::Wait(unsigned int milliseconds)
{
	this->isWaiting = true;
	this->waitTime = milliseconds;
}

void game::ActionsQueue::UpdateElapsedTime(sf::Time elapsedTime)
{
	if(IsWaiting())
	this->elapsedTime += elapsedTime;
	if (this->elapsedTime.asMilliseconds() >= waitTime) {
		this->waitTime = 0;
		isWaiting = false;
		this->elapsedTime = sf::Time::Zero;
	}
}
