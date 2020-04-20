#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include <SFML/Audio.hpp>

class GameState : public State {
	sf::Sprite background;
private:

	virtual void OnHandleEvent() override;
	virtual void OnDraw() override;

	virtual void OnUpdate() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !GAME_STATE_H
