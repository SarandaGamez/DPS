#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"

class MenuState : public State {
	sf::Sprite sprite;


private:

	virtual void OnHandleEvent() override;

	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !MENU_STATE_H
