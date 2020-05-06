#include "GUI\GraphicComponent.h"

void gui::GraphicComponent::SetTexture(const sf::Texture& texture)
{
	this->sprite.setTexture(texture);
}

const sf::FloatRect& gui::GraphicComponent::GetGlobalBounds()
{
	return sprite.getGlobalBounds();
}

void gui::GraphicComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}

void gui::GraphicComponent::OnSetPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}
