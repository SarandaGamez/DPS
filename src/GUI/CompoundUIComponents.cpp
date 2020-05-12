#include "GUI/CompoundUIComponents.h"

std::shared_ptr<gui::UIComponent> gui::CompoundUIComponents::Add(std::shared_ptr<gui::UIComponent> component)
{
	this->children.push_back(component);
	return component;
}

void gui::CompoundUIComponents::Remove(std::shared_ptr<gui::UIComponent> component)
{
	this->children.remove(component);
}

const std::list<std::shared_ptr<gui::UIComponent>>& gui::CompoundUIComponents::GetComponents()
{
	return this->children;
}

void gui::CompoundUIComponents::Update()
{
	if (children.empty())
		return;

	for (auto component : children)
		component->Update();
}

void gui::CompoundUIComponents::HandleEvent(const sf::Event& event)
{
	if (children.empty())
		return;

	for (auto component : children)
		component->HandleEvent(event);
}

void gui::CompoundUIComponents::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (children.empty())
		return;

	for (auto component : children)
		component->draw(target, states);
}

void gui::CompoundUIComponents::OnSetPosition(sf::Vector2f position)
{
	if (children.empty())
		return;

	for (auto component : children)
		component->SetPosition({ component->GetPosition().x + position.x - compositePosition.x,
			component->GetPosition().y + position.y - compositePosition.y });

	this->compositePosition = position;
}
