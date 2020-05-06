#include "GUI\TextComponent.h"

void gui::TextComponent::SetFont(const sf::Font& font)
{
	this->text.setFont(font);
}

void gui::TextComponent::SetText(const std::string& text)
{
	this->text.setString(text);
}

void gui::TextComponent::SetCharacterSize(unsigned int size)
{
	this->text.setCharacterSize(size);
}

const sf::FloatRect& gui::TextComponent::GetGlobalBounds()
{
	return this->text.getGlobalBounds();
}

void gui::TextComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text, states);
}

void gui::TextComponent::OnSetPosition(sf::Vector2f position)
{
	text.setPosition(position);
}
