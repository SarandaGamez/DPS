#include "GUI/UIComposite.h"

std::shared_ptr<gui::UIComponent> gui::UIComposite::Add(std::shared_ptr<gui::UIComponent> component)
{
	this->children.push_back(component);
	return component;
}

void gui::UIComposite::Remove(std::shared_ptr<gui::UIComponent> component)
{
	this->children.remove(component);
}

const std::list<std::shared_ptr<gui::UIComponent>>& gui::UIComposite::GetComponents()
{
	return this->children;
}

void gui::UIComposite::Update()
{
	if (children.empty())
		return;

	for (auto component : children)
		component->Update();
}

void gui::UIComposite::HandleEvent(const sf::Event& event)
{
	if (children.empty())
		return;
	
	if (IsActive())
	for (auto component : children)
		component->HandleEvent(event);
}

void gui::UIComposite::OnSetPosition(sf::Vector2f position)
{
	if (children.empty())
		return;

		for (auto component : children)
			component->SetPosition({ component->GetPosition().x + position.x - compositePosition.x,
				component->GetPosition().y + position.y - compositePosition.y });

	this->compositePosition = position;
}

void gui::UIComposite::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (children.empty())
		return;

	if (IsVisible())
		for (auto component : children)
			component->draw(target, states);
}
