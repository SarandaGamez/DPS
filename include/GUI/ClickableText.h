#ifndef GUI_CLICKABLE_TEXT_H
#define GUI_CLICKABLE_TEXT_H

#include <sfml/Graphics.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/TextComponent.h"

namespace gui {

	class ClickableText : public gui::ClickableComponent {

	public:
		ClickableText(const sf::Font& font, const std::string& caption, const sf::Vector2f& position);
		void SetFont(const sf::Font& font);
		void SetText(const std::string& string);
		void SetCharacterSize(unsigned int size);
		void Update();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		gui::TextComponent text;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
	};
}

#endif // GUI_CLICKABLE_TEXT_H