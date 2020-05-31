#include "GUI/ComponentsBuilder.h"

sf::Font* gui::ComponentsBuilder::font = nullptr;

void gui::ComponentsBuilder::SetFont(sf::Font* font)
{
	gui::ComponentsBuilder::font = font;
}

std::shared_ptr<gui::TextComponent> gui::ComponentsBuilder::BuildTextComponent(unsigned int characterSize, sf::Vector2f position, const std::string& text)
{
	return BuildTextComponent(*font, characterSize, position, text);
}

std::shared_ptr<gui::TextComponent> gui::ComponentsBuilder::BuildTextComponent(const sf::Font& font, unsigned int characterSize, sf::Vector2f position, const std::string& text)
{
	auto textComponent = std::shared_ptr<gui::TextComponent>(new gui::TextComponent());
	textComponent->SetText(text);
	textComponent->SetFont(font);
	textComponent->SetCharacterSize(characterSize);
	textComponent->SetPosition(position);
	return textComponent;
}