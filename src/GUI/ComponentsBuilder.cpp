#include "GUI/ComponentsBuilder.h"

std::shared_ptr<gui::TextComponent> gui::ComponentsBuilder::BuildTextComponent(const sf::Font& font, unsigned int characterSize, sf::Vector2f position, const std::string& text)
{
	auto textComponent = std::shared_ptr<gui::TextComponent>(new gui::TextComponent());
	textComponent->SetText(text);
	textComponent->SetFont(font);
	textComponent->SetCharacterSize(characterSize);
	textComponent->SetPosition(position);
	return textComponent;
}