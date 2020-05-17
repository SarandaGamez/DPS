#include "GUI/ButtonsBuilder.h"

void gui::ButtonsBuilder::SetTexture(const sf::Texture& texture)
{
	this->texture = &texture;
}

void gui::ButtonsBuilder::SetFont(const sf::Font& font)
{
	this->font = &font;
}

std::shared_ptr<gui::HoverableComponent> gui::ButtonsBuilder::BuildHoverableRegion(sf::FloatRect region)
{
	auto hoverable = std::shared_ptr<gui::HoverableComponent>(new HoverableComponent);
	hoverable->SetRegion(region);
	return hoverable;
}

std::shared_ptr<gui::ClickableComponent> gui::ButtonsBuilder::BuildClickableRegion(sf::FloatRect region)
{
	auto clickable = std::shared_ptr<gui::ClickableComponent>(new ClickableComponent);
	clickable->SetRegion(region);
	return clickable;
}

std::shared_ptr<gui::TextButton> gui::ButtonsBuilder::BuildTextButton(const std::string& text, sf::Vector2f position)
{
	return std::shared_ptr<gui::TextButton>(new gui::TextButton (*texture, *font, text, position));
}
