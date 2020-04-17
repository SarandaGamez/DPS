#include "StatesMachine.h"


void StatesMachine::ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	this->renderWindow = renderWindow;
}

void StatesMachine::Push(std::shared_ptr<State> state) {
	std::shared_ptr<State> topState = Peek();

	if (topState)
		topState->OnHide();

	states.push(state);

	Peek()->ConnectWithRenderWindow(renderWindow);
	Peek()->ConnectWithStateTransition(this);
	Peek()->OnEnter();
}


void StatesMachine::Pop(){
	if(this->states.empty()) {
		throw std::runtime_error("Attempted to pop from an empty game state stack");
	}

	states.top()->OnLeave();
	states.pop();
}

std::shared_ptr<State> StatesMachine::Peek(){
	if(!states.empty())
		return states.top();
	else
		return nullptr;
}

void StatesMachine::Switch(std::shared_ptr<State> state){
	std::shared_ptr<State> currentState = Peek();

	if(currentState)
		Pop();
		
	Push(state);
}