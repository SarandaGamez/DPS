#include "GUI/ClickableStructuresBuilder.h"

gui::ClickableStructuresBuilder::ClickableStructuresBuilder() {
	Reset();
}

void gui::ClickableStructuresBuilder::Reset()
{
	components.clear();
	SetPosition({ 0,0 });
	regionSize = { 0,0 };
}

std::shared_ptr<gui::ClickableComponent> gui::ClickableStructuresBuilder::Add(const std::shared_ptr<gui::ClickableComponent>& component)
{
	components.push_back(component);
	regionSize.x += component->GetRegion().width;
	regionSize.y += component->GetRegion().height;
	return component;
}

std::shared_ptr<gui::UIComposite> gui::ClickableStructuresBuilder::MakeHorizontal(float regionWidth)
{
	auto composite = std::shared_ptr<gui::UIComposite>(new gui::UIComposite);
	float numberOfComponents = components.size();
	if (numberOfComponents > 0) {
		float spaceBetweenObjects = (regionWidth - regionSize.x) / (numberOfComponents + 1);

		for (int i = 0; i < components.size(); i++) {
			components[i]->SetPosition({ spaceBetweenObjects + (components[i]->GetRegion().width + spaceBetweenObjects) * i, 0 });
			composite->Add(components[i]);
		}
		composite->SetPosition({ centerPosition.x - regionWidth / 2, centerPosition.y });
	}
	return composite;
}

std::shared_ptr<gui::UIComposite> gui::ClickableStructuresBuilder::MakeVertical(float regionHeight)
{
	auto composite = std::shared_ptr<gui::UIComposite>(new gui::UIComposite); 
	float numberOfComponents = components.size();
	if (numberOfComponents > 0) {
		float spaceBetweenObjects = (regionHeight - regionSize.y) / (numberOfComponents + 1);

		float maxWidth = 0;
		for (int i = 0; i < components.size(); i++) {
			components[i]->SetPosition({0, spaceBetweenObjects + (components[i]->GetRegion().height + spaceBetweenObjects) * i});
			composite->Add(components[i]);
			if (maxWidth < components[i]->GetRegion().width)
				maxWidth = components[i]->GetRegion().width;
		}
		composite->SetPosition({ centerPosition.x - maxWidth / 2, centerPosition.y - regionHeight / 2});
	}
	return composite;
}

void gui::ClickableStructuresBuilder::SetPosition(const sf::Vector2f& centerPosition)
{
	this->centerPosition = centerPosition;
}
