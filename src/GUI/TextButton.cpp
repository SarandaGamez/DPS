#include "GUI/MouseButtonReleasedBehavior.h"
#include "GUI/TextButton.h"

namespace gui {

	TextButton::TextButton(const sf::Texture& texture, const sf::Font& font, const std::string& text = "", sf::Vector2f position = { 0,0 }) : gui::Button(texture, position)
	{
		GetText().SetFont(font);
		GetText().SetText(text);
		SetPosition(position);
	}

	gui::TextComponent& TextButton::GetText()
	{
		return this->text;
	}

	void TextButton::Update()
	{
		gui::Button::Update();
		text.Update();
	}

	void TextButton::OnSetPosition(sf::Vector2f position)
	{
		gui::Button::OnSetPosition(position);
		sf::FloatRect buttonGraphic = gui::Button::GetRegion();
		text.SetPosition({ buttonGraphic.left + buttonGraphic.width / 2, buttonGraphic.top + buttonGraphic.height / 2});
		text.SetPosition({ text.GetPosition().x - text.GetGlobalBounds().width / 2, text.GetPosition().y - text.GetGlobalBounds().height / 2 });
	}

	void TextButton::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		gui::Button::draw(target, states);
		target.draw(text, states);
	}

}