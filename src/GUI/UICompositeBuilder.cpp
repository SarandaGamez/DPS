
#include "GUI/UICompositeBuilder.h"

namespace gui {
	UICompositeBuilder::UICompositeBuilder()
	{
		Reset();
	}
	void UICompositeBuilder::Reset()
	{
		this->composite = std::shared_ptr<gui::CompoundUIComponents>(new gui::CompoundUIComponents);
	}
	std::shared_ptr<gui::UIComponent> UICompositeBuilder::Add(std::shared_ptr<gui::UIComponent> component)
	{
		return this->composite->Add(component);
	}
	std::shared_ptr<gui::CompoundUIComponents>& UICompositeBuilder::GetResult()
	{
		return this->composite;
	}
}