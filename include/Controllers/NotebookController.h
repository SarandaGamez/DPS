#ifndef CTRL_NOTEBOOK_CONTROLLER_H
#define CTRL_NOTEBOOK_CONTROLLER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>
#include "Controllers/Controller.h"
#include "GUI/ClickableComponent.h"
#include "GUI/Notebook.h"

namespace ctrl {

	class NotebookController : public ctrl::Controller {
	public:
		NotebookController(std::shared_ptr<sf::RenderWindow> renderWindow, TexturesHolder& textures, StateTransition* transition);
		~NotebookController();

		virtual void Update(sf::Time time);
		virtual void HandleEvent(sf::Event event);
		virtual void Draw() const;
	private:
		sf::Font font;
		std::shared_ptr<gui::Notebook> notebook;
		std::shared_ptr<gui::Window> notebookWindow;
		std::shared_ptr<gui::ClickableComponent> button;
		void OpenNotebook();
		void CloseNotebook();
	};
}

#endif // ! CTRL_NOTEBOOK_CONTROLLER_H
