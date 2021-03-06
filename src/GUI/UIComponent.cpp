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

void gui::UIComponent::SetLayer(unsigned short layer)
{
	this->layer = layer;
}

unsigned short gui::UIComponent::GetLayer() const
{
	return this->layer;
}
void gui::UIComponent::HandleEvent(const sf::Event& event)
{
	if(IsActive())
		if (CheckEventCondition(event))
			eventBehaviors.HandleEvent(event);
}

void gui::UIComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(IsVisible())
		OnDraw(target, states);
}

gui::CompoundEventBehavior& gui::UIComponent::GetEventBehaviors()
{
	return eventBehaviors;
}