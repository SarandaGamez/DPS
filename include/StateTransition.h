#ifndef STATE_TRANSITION_H
#define STATE_TRANSITION_H

#include "State.h"
#include <memory>

class StateTransition
{
public:
    virtual void Pop() = 0;
    virtual void Push(std::shared_ptr<State> state) = 0;
    virtual void Switch(std::shared_ptr<State> state) = 0;
};

#endif // STATE_TRANSITION_H