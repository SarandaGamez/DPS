#include "StateUpdater.h"

void StateUpdater::ConnectWithAccessor(StateAccessor& accessor)
{
    this->accessor = &accessor;
}

void StateUpdater::Update(sf::Time deltaTime)
{
    accessor->Peek()->Update(deltaTime);

}

void StateUpdater::HandleEvent(sf::Event event)
{
    accessor->Peek()->HandleEvent(event);
}

void StateUpdater::Draw()
{
    accessor->Peek()->Draw();
}