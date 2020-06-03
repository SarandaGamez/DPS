#include "Gameplay/Action.h"

game::Action::Action(std::function<void()> const& slot)
{
	signal.Connect(slot);
}

void game::Action::Execute()
{
	signal();
}
