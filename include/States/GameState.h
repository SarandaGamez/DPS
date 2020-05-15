#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "State.h"
#include <SFML/Audio.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/UIComposite.h"
#include "GUI/UICompositeBuilder.h"
#include "GUI/Window.h"
#include <vector>
#include <memory>

class GameState : public State {
	sf::Sprite background;
	sf::Font font;
	std::vector<std::shared_ptr<gui::UIComposite>> components;
	gui::UICompositeBuilder compositeBuilder;
	std::shared_ptr<gui::Window> dialogWindow;
	unsigned short currentLayer = 0;
private:

	virtual void OnHandleEvent() override;
	virtual void OnDraw() override;

	virtual void OnUpdate() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;

	void OpenDialog();
	void CloseDialog();
	void AddUIComponent(std::shared_ptr<gui::UIComponent> component);
};

#endif // !GAME_STATE_H
