#include "GUI\GraphicComponent.h"

gui::GraphicComponent::GraphicComponent(const sf::Texture& texture)
{
	SetTexture(texture);
}

void gui::GraphicComponent::SetTexture(const sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

sf::FloatRect gui::GraphicComponent::GetGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

sf::Sprite& gui::GraphicComponent::GetSprite()
{
	return this->sprite;
}

void gui::GraphicComponent::OnSetPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

void gui::GraphicComponent::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
