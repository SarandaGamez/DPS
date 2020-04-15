#include "StateUpdater.h"

void StateUpdater::ConnectWithAccessor(StateAccessor& accessor)
{
    this->accessor = &accessor;
}

bool StateUpdater::IsRunning()
{
    return isRunning;
}

void StateUpdater::Update(sf::Time deltaTime)
{
    accessor->Peek()->Update(deltaTime);

    if(accessor->Peek()->IsGameFinished() == true)
        isRunning = false;

}

void StateUpdater::HandleEvent(sf::Event event)
{
    accessor->Peek()->HandleEvent(event);
}

void StateUpdater::Draw()
{
    accessor->Peek()->Draw();
}