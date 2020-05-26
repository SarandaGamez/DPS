#ifndef CTRL_CONTROLLER_H
#define CTRL_CONTROLLER_H

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "Utils/SignalObject.h"
#include "StateTransition.h"
#include "TexturesHolder.h"

namespace ctrl {

	class Controller : public utils::SignalObject{
	public:
		Controller(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& texturesHolder, StateTransition* transition);

		virtual void Update(sf::Time time) = 0;
		virtual void HandleEvent(sf::Event event) = 0;
		virtual void Draw() const = 0;
	protected:
		TexturesHolder* textures;
		StateTransition* transition;
		std::shared_ptr<sf::RenderWindow> renderWindow;
		static unsigned int currentLayer;
	};
}

#endif // !CTRL_CONTROLLER_H
