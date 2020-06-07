#ifndef CTRL_CONTROLLER_H
#define CTRL_CONTROLLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "Utils/SignalObject.h"
#include "StateTransition.h"
#include "TexturesHolder.h"
#include "Gameplay/ActionsQueue.h"

namespace ctrl {

	class Controller : public utils::SignalObject{
	public:

		static void Initialize(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& texturesHolder, StateTransition* transition);

		virtual void Update(sf::Time time) {}
		virtual void HandleEvent(sf::Event event) {}
		virtual void Draw() const {}
	protected:
		static TexturesHolder* textures;
		static StateTransition* transition;
		static std::shared_ptr<sf::RenderWindow> renderWindow;
		static unsigned int currentLayer;
		static game::ActionsQueue actions;
	};
}

#endif // !CTRL_CONTROLLER_H
