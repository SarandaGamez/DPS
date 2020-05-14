#include "GUI\Window.h"

void gui::Window::SetBackground(std::shared_ptr<gui::GraphicComponent> background)
{
	this->background = background;
	Remove(this->background);
	Add(this->background);
}

sf::FloatRect gui::Window::GetWindowArea()
{
	return this->background->GetGlobalBounds();
}

void gui::Window::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	gui::UIComposite::OnDraw(target, states);
	background->draw(target, states);
}