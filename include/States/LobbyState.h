#ifndef LOBBY_STATE_H
#define LOBBY_STATE_H

#include "State.h"

class LobbyState : public State {
private:

	virtual void OnHandleEvent() override;
	virtual void OnDraw() override;

	virtual void OnUpdate() override;

	virtual void OnEnter() override;
	virtual void OnLeave() override;
};

#endif // !LOBBY_STATE_H
