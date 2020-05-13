
#include "GUI/UICompositeBuilder.h"

namespace gui {
	UICompositeBuilder::UICompositeBuilder()
	{
		Reset();
	}
	void UICompositeBuilder::Reset()
	{
		this->composite = std::shared_ptr<gui::UIComposite>(new gui::UIComposite);
	}
	std::shared_ptr<gui::UIComponent> UICompositeBuilder::Add(std::shared_ptr<gui::UIComponent> component)
	{
		return this->composite->Add(component);
	}
	std::shared_ptr<gui::UIComposite>& UICompositeBuilder::GetResult()
	{
		return this->composite;
	}
}