#ifndef GUI_TEXT_BUTTON_H
#define GUI_TEXT_BUTTON_H

#include <sfml/Graphics.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/Button.h"
#include "GUI/TextComponent.h"

namespace gui {

	class TextButton : public gui::Button {

	public:
		TextButton(const sf::Texture& texture, const sf::Font& font, const std::string& text, sf::Vector2f position);

		gui::TextComponent& GetText();
		void Update();
		void draw(std::shared_ptr<sf::RenderWindow> renderWindow) const;

	private:
		gui::TextComponent text;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
	};
}

#endif // GUI_TEXT_BUTTON_H