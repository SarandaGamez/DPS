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
		void Update(sf::Time time) override;

	private:
		gui::TextComponent text;

		void ScaleText(unsigned int characterSize);

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // GUI_TEXT_BUTTON_H