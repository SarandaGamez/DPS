#ifndef OVER_STATE_H
#define OVER_STATE_H

#include "State.h"

class OverState : public State {
	sf::Sprite background;

	sf::Font font;
	sf::Text winner;
	sf::Text backToMenuTip;

	std::string winnersName;
public:
	OverState(const std::string& winnersName) : winnersName(winnersName) {}
private:

	virtual void OnUpdate() override;
	virtual void OnDraw() override;
	virtual void OnHandleEvent() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !OVER_STATE_H
