#ifndef INTRO_STATE_H
#define INTRO_STATE_H

#include "State.h"

class IntroState : public State {
private:

	virtual void OnUpdate() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !INTRO_STATE_H
