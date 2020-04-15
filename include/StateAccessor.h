#ifndef STATE_ACCESSOR_H
#define STATE_ACCESSOR_H

#include <memory>
#include "State.h"

class StateAccessor
{
public:
    virtual std::shared_ptr<State> Peek() = 0;
};

#endif // STATE_ACCESSOR_H