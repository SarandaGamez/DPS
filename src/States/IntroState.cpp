#include "States/IntroState.h"
#include "States/MenuState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void IntroState::OnEnter()
{
}

void IntroState::OnLeave()
{
}

void IntroState::OnUpdate()
{
	cout << "Intro updated" << endl;
	transition->Switch(std::unique_ptr<State>(new MenuState));
}
