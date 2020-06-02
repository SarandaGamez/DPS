#ifndef CTRL_TURNS_CONTROLLER_H
#define CTRL_TURNS_CONTROLLER_H

#include "Controllers/Controller.h"
#include "GUI/TextButton.h"
#include <SFML/Graphics/Font.hpp>
#include <memory>

namespace ctrl {
	class TurnsController : public ctrl::Controller {
	public:
		TurnsController();
		~TurnsController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Font font;
		std::shared_ptr<gui::TextButton> nextTurnButton;
		void NextTurn();
	};
}

#endif // !CTRL_TURNS_CONTROLLER_H
