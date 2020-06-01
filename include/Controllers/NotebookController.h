#ifndef CTRL_NOTEBOOK_CONTROLLER_H
#define CTRL_NOTEBOOK_CONTROLLER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include "Controllers/Controller.h"
#include "GUI/ClickableComponent.h"
#include "GUI/Notebook.h"
#include "GUI/Button.h"

namespace ctrl {

	class NotebookController : public ctrl::Controller {
	public:
		NotebookController();
		~NotebookController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Font font;
		std::shared_ptr<gui::Notebook> notebook;
		std::shared_ptr<gui::Window> notebookWindow;
		std::shared_ptr<gui::ClickableComponent> button;
		std::shared_ptr<gui::Button> leftArrow;
		std::shared_ptr<gui::Button> rightArrow;
	};
}

#endif // ! CTRL_NOTEBOOK_CONTROLLER_H
