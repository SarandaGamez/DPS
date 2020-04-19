#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include "GUI/Button.h"

class MenuState : public State {
	sf::Sprite sprite;
	sf::Font font;
	std::unique_ptr<Button> buttonPlay;
	std::unique_ptr<Button> buttonLoad;
	std::unique_ptr<Button> buttonSettings;
	std::unique_ptr<Button> buttonExit;

private:

	virtual void OnHandleEvent() override;

	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !MENU_STATE_H
