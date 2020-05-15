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
	if(isActive)
		if (CheckEventCondition(event))
			eventBehaviors.HandleEvent(event);
}

void gui::UIComponent::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if(isVisible)
		OnDraw(target, states);
}

void gui::UIComponent::SetActive(bool isActive)
{
	this->isActive = isActive;
}

void gui::UIComponent::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

void gui::UIComponent::SetLayer(unsigned short layer)
{
	this->layer = layer;
}

bool gui::UIComponent::IsActive() const
{
	return isActive;
}

bool gui::UIComponent::IsVisible() const
{
	return isVisible;
}

unsigned short gui::UIComponent::GetLayer() const
{
	return this->layer;
}

gui::CompoundEventBehavior& gui::UIComponent::GetEventBehaviors()
{
	return eventBehaviors;
}