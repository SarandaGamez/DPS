#ifndef STATE_UPDATER_H
#define STATE_UPDATER_H

#include "StateAccessor.h"
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

class StateUpdater
{
    bool isRunning = true;
    StateAccessor* accessor = nullptr;
public:
    void ConnectWithAccessor(StateAccessor& accessor);
    void HandleEvent(sf::Event event);
    void Update(sf::Time elapsedTime);
    void Draw();

    bool IsRunning();
};

#endif // STATE_UPDATER_H