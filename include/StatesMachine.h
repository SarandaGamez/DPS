#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include <memory>
#include <stack>
#include "StateTransition.h"
#include "StateAccessor.h"
#include <SFML/Graphics/RenderWindow.hpp>

class StatesMachine : public StateTransition, public StateAccessor {
	std::stack<std::shared_ptr<State>> states;
	std::shared_ptr<sf::RenderWindow> renderWindow;
public:
	void ConnectWithRenderWindow(std::shared_ptr<sf::RenderWindow> renderWindow);

	virtual void Push(std::shared_ptr<State> state);
	virtual void Pop();
	virtual void Switch(std::shared_ptr<State> state);
	virtual std::shared_ptr<State> Peek();
};

#endif // !STATE_MACHINE_H
