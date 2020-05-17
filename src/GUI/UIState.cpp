#include "GUI/UIState.h"


void gui::UIState::SetActive(bool isActive)
{
	this->isActive = isActive;
}

void gui::UIState::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

void gui::UIState::SetMouseInRegion(bool isMouseInRegion)
{
	this->isMouseInRegion = isMouseInRegion;
}

bool gui::UIState::IsActive() const
{
	return isActive;
}

bool gui::UIState::IsVisible() const
{
	return isVisible;
}

bool gui::UIState::IsMouseInRegion() const
{
	return this->isMouseInRegion;
}
