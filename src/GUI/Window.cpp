#include "GUI\Window.h"

void gui::Window::SetBackground(std::shared_ptr<gui::GraphicComponent> background)
{
	this->background = background;
}

std::shared_ptr<gui::GraphicComponent> gui::Window::GetBackground()
{
	return background;
}

sf::FloatRect gui::Window::GetWindowArea()
{
	return this->background->GetGlobalBounds();
}

void gui::Window::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	background->draw(target, states);
	gui::UIComposite::OnDraw(target, states);
}

void gui::Window::OnSetPosition(sf::Vector2f position)
{
	gui::UIComposite::OnSetPosition(position);
	background->SetPosition(position);
}
