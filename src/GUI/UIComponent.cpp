#include "GUI\UIComponent.h"

void gui::UIComponent::SetPosition(sf::Vector2f position)
{
	this->position = position;
	OnSetPosition(position);
}

sf::Vector2f gui::UIComponent::GetPosition()
{
	return position;
}

void gui::UIComponent::HandleEvent(const sf::Event& event)
{
	if (CheckEventCondition(event))
		eventBehaviors.HandleEvent(event);
}

void gui::UIComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	OnDraw(target, states);
}

gui::CompoundEventBehavior& gui::UIComponent::GetEventBehaviors()
{
	return eventBehaviors;
}