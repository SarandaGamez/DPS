#include "States/LobbyState.h"
#include "States/GameState.h"
#include "StatesMachine.h"
#include <iostream>

using std::cout;
using std::endl;

void LobbyState::OnEnter()
{
	cout << "Lobby loaded" << endl;
}

void LobbyState::OnLeave()
{
	cout << "Lobby unloaded" << endl;
}

void LobbyState::OnHandleEvent()
{
}

void LobbyState::OnDraw()
{
}

void LobbyState::OnUpdate()
{
	transition->Switch(std::unique_ptr<State>(new GameState));
}