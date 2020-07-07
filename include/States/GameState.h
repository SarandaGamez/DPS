#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include <SFML/Audio.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/UIComposite.h"
#include "Controllers/Controllers.h"
#include <vector>
#include <memory>

class GameState : public State {
	sf::Font font;
	ctrl::Controllers controllers;
private:

	virtual void OnHandleEvent(sf::Event event) override;
	virtual void OnDraw() override;

	virtual void OnUpdate(sf::Time elapsedTimes) override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !GAME_STATE_H
