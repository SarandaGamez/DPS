#ifndef GUI_COMPONENTS_BUILDER_H
#define GUI_COMPONENTS_BUILDER_H

#include "GUI/TextComponent.h"
#include <memory>

namespace gui {
	class ComponentsBuilder {
	public:
		static void SetFont(sf::Font* font);
		static std::shared_ptr<gui::TextComponent> BuildTextComponent(unsigned int characterSize, sf::Vector2f position, const std::string& text = "");
		static std::shared_ptr<gui::TextComponent> BuildTextComponent(const sf::Font& font, unsigned int characterSize, sf::Vector2f position, const std::string& text = "");
	private:
		static sf::Font* font;
	};
}

#endif // !GUI_OMPONENTS_BUILDER_H