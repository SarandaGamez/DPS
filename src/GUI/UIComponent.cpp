#include "GUI\UIComponent.h"

void gui::UIComponent::SetPosition(sf::Vector2f position)
{
	this->position = position;
}

sf::Vector2f gui::UIComponent::GetPosition()
{
	return position;
}

void gui::UIComponent::HandleEvent(const sf::Event& event)
{
	eventBehaviors.HandleEvent(event);
}
