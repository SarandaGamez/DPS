#ifndef GUI_TEXT_COMPONENT_H
#define GUI_TEXT_COMPONENT_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "GUI/UIComponent.h"

namespace gui {

	class TextComponent : public gui::UIComponent {
		sf::Text text;

	public:
		void SetFont(const sf::Font& font);
		void SetText(const std::string& text);
		void SetCharacterSize(unsigned int size);
		const sf::FloatRect& GetGlobalBounds();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
	};
}


#endif // GUI_TEXT_COMPONENT_H