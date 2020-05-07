#include "GUI\ClickableComponent.h"

bool gui::ClickableComponent::IsMouseInRegion(const sf::Vector2f& mousePosition)
{
	return clickableRegion.contains(mousePosition);
}

void gui::ClickableComponent::SetRegion(const sf::FloatRect& region)
{
	this->clickableRegion = region;
}

const sf::FloatRect& gui::ClickableComponent::GetRegion()
{
	return this->clickableRegion;
}
