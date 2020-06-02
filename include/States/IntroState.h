#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"
#include "Cinematics/SlideShow.h"

class IntroState : public State {

private:
	sf::Font font; 
	sf::Texture texture;
	std::shared_ptr<Slideshow> slideshow;

	virtual void OnHandleEvent(sf::Event event) override;
	virtual void OnUpdate(sf::Time elapsedTimes) override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;

	virtual void OnDraw() override;
};

#endif // !INTRO_STATE_H
