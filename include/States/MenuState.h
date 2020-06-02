#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "State.h"
#include "GUI/UIComponent.h"
#include "GUI/UIComposite.h"
#include "GUI/ClickableText.h"

class MenuState : public State {
	sf::Sprite sprite;
	sf::Font font;
	gui::UIComposite components;

private:

	virtual void OnHandleEvent(sf::Event event) override;

	virtual void OnUpdate(sf::Time elapsedTimes) override;
	virtual void OnDraw() override;
	virtual void OnEnter() override;
	virtual void OnLeave() override;

	void StartTheGame();
	void CloseGameWindow();
};

#endif // !MENU_STATE_H
