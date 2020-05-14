#ifndef GUI_DIALOG_WINDOW_BUILDER_H
#define GUI_DIALOG_WINDOW_BUILDER_H

#include "GUI/Window.h"
#include <SFML/Graphics/Font.hpp>
#include "GUI/TextButton.h"
#include "GUI/TextComponent.h"
#include <memory>
#include <vector>

namespace gui {

	class DialogWindowBuilder{

	public:
		DialogWindowBuilder(std::shared_ptr<gui::GraphicComponent> background);
		DialogWindowBuilder(std::shared_ptr<gui::Window> window);

		void Reset(std::shared_ptr<gui::Window> window);
		void Reset(std::shared_ptr<gui::GraphicComponent> background);

		void SetCaption(const std::string& caption, const sf::Font& font);
		std::shared_ptr<gui::TextButton> AddOption(const std::string& caption, const sf::Font& font, const sf::Texture& buttonTexture);

		std::shared_ptr<gui::Window> GetResult();
	private:
		std::shared_ptr<gui::Window> window;
		std::shared_ptr<gui::TextComponent> caption;
		std::vector<std::shared_ptr<gui::TextButton>> buttons;

		void AlignButtons();
	};
}

#endif // !GUI_DIALOG_WINDOW_BUILDER_H
