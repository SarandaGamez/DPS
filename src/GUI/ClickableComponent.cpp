#include "GUI\ClickableComponent.h"
#include "GUI\MouseButtonReleasedBehavior.h"

gui::ClickableComponent::ClickableComponent()
{
	GetEventBehaviors().Add(std::make_shared<gui::MouseButtonReleasedBehavior>(this));
}

bool gui::ClickableComponent::IsMouseInRegion(const sf::Vector2f& mousePosition)
{
	return clickableRegion.contains(mousePosition);
}

void gui::ClickableComponent::SetRegion(const sf::FloatRect& region)
{
	this->clickableRegion = region;
}

sf::FloatRect gui::ClickableComponent::GetRegion()
{
	return this->clickableRegion;
}

void gui::ClickableComponent::OnSetPosition(sf::Vector2f position)
{
	SetRegion({ position.x, position.y, clickableRegion.width, clickableRegion.height });
}
