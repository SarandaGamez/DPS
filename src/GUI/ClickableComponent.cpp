#include "GUI/ClickableComponent.h"
#include "GUI/EventBehavior/MouseButtonClickedBehavior.h"

gui::ClickableComponent::ClickableComponent()
{
	GetEventBehaviors().Add(std::make_shared<gui::MouseButtonClickedBehavior>(this));
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

bool gui::ClickableComponent::CheckEventCondition(const sf::Event& event)
{
	sf::Vector2f mousePosition = { static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) };
	gui::UIComponent::SetMouseInRegion(IsMouseInRegion(mousePosition));
	return gui::UIComponent::IsMouseInRegion();
}
