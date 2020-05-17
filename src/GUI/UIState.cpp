#include "GUI/UIState.h"


void gui::UIState::SetActive(bool isActive)
{
	this->isActive = isActive;
}

void gui::UIState::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

bool gui::UIState::IsActive() const
{
	return isActive;
}

bool gui::UIState::IsVisible() const
{
	return isVisible;
}