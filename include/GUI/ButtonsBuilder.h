#ifndef GUI_TEXT_BUTTON_BUILDER_H
#define GUI_TEXT_BUTTON_BUILDER_H

#include "GUI/TextButton.h"
#include "GUI/HoverableComponent.h"

namespace gui {

	class ButtonsBuilder {

	public:
		void SetTexture(const sf::Texture& texture);
		void SetFont(const sf::Font& font);
		std::shared_ptr<gui::HoverableComponent> BuildHoverableRegion(sf::FloatRect region);
		std::shared_ptr<gui::ClickableComponent> BuildClickableRegion(sf::FloatRect region);
		std::shared_ptr<gui::TextButton> BuildTextButton(const std::string& text, sf::Vector2f position);

	private:
		const sf::Texture* texture;
		const sf::Font* font;
	};
}

#endif // GUI_TEXT_BUTTON_BUILDER_H