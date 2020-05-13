#include "GUI\Window.h"

void gui::Window::SetBackground(std::shared_ptr<gui::GraphicComponent> background)
{
	this->background = background;
	Remove(this->background);
	Add(this->background);
}

void gui::Window::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	gui::CompoundUIComponents::draw(target, states);
	background->draw(target, states);
}