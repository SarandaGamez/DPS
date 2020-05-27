#include "GUI/HoverableComponent.h"
#include "GUI/EventBehavior/MouseButtonHoveredBehavior.h"

gui::HoverableComponent::HoverableComponent()
{
	GetEventBehaviors().Add(std::shared_ptr<gui::MouseButtonHoveredBehavior>(new gui::MouseButtonHoveredBehavior(this)));
}

bool gui::HoverableComponent::IsMouseInRegion(const sf::Vector2f& mousePosition)
{
	return hoverableRegion.contains(mousePosition);
}

void gui::HoverableComponent::SetRegion(const sf::FloatRect& region)
{
	this->hoverableRegion = region;
}

sf::FloatRect gui::HoverableComponent::GetRegion()
{
	return this->hoverableRegion;
}

void gui::HoverableComponent::OnSetPosition(sf::Vector2f position)
{
	SetRegion({ position.x, position.y, hoverableRegion.width, hoverableRegion.height });
}

bool gui::HoverableComponent::CheckEventCondition(const sf::Event& event)
{
	sf::Vector2f mousePosition = { static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) };
	gui::UIComponent::SetMouseInRegion(IsMouseInRegion(mousePosition));
	return true;
}
