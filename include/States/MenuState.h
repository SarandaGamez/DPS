#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include "GUI/ClickableText.h"

class MenuState : public State {
	sf::Sprite sprite;
	sf::Font font;
	std::unique_ptr<gui::ClickableText> buttonPlay;
	std::unique_ptr<gui::ClickableText> buttonLoad;
	std::unique_ptr<gui::ClickableText> buttonSettings;
	std::unique_ptr<gui::ClickableText> buttonExit;

private:

	virtual void OnHandleEvent() override;

	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;

	void StartTheGame();
	void CloseGameWindow();
};

#endif // !MENU_STATE_H
