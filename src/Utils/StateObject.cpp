#include "Utils/StateObject.h"

void utils::StateObject::SetActive(bool isActive)
{
	this->isActive = isActive;
}

void utils::StateObject::SetVisible(bool isVisible)
{
	this->isVisible = isVisible;
}

void utils::StateObject::SetMouseInRegion(bool isMouseInRegion)
{
	this->isMouseInRegion = isMouseInRegion;
}

bool utils::StateObject::IsActive() const
{
	return isActive;
}

bool utils::StateObject::IsVisible() const
{
	return isVisible;
}

bool utils::StateObject::IsMouseInRegion() const
{
	return isMouseInRegion;
}
