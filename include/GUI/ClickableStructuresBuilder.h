#ifndef GUI_CLICKABLE_STRUCTURES_BUILDER_H
#define GUI_CLICKABLE_STRUCTURES_BUILDER_H

#include "GUI/ClickableComponent.h"
#include "GUI/UIComposite.h"
#include <memory>
#include <vector>

namespace gui {
	class ClickableStructuresBuilder {
	public:
		ClickableStructuresBuilder();
		/*
		\brief Removes the components from the structure
		*/
		void Reset();
		/*
		\brief Adds new component to the structure
		\params component - new element of the structure
		\returns last added component
		*/
		std::shared_ptr<gui::ClickableComponent> Add(const std::shared_ptr<gui::ClickableComponent>& component);
		/*
		\brief Aligns components horizontaly based on the centerPosition
		\params regionWidth - width of the outer structure
		- regionWidth has to be greater than the sum of the width of elements in structure
		\returns UIComposite object containing the structure of components
		*/
		std::shared_ptr<gui::UIComposite> MakeHorizontal(float regionWidth);
		/*
		\brief Aligns components verticaly based on the centerPosition
		\params regionHeight - height of the outer structure
		- regionHeight has to be greater than the sum of the height of elements in structure
		\returns UIComposite object containing the structure of components
		*/
		std::shared_ptr<gui::UIComposite> MakeVertical(float regionHeight);
		/*
		\brief Sets the position of the center of the structure
		\params centerPosition - center position of the structure
		In case of using it as an inner structure of a window, the centerPosition:
		- has to be at least (0,0)
		- can be at most (widthOfTheWindow, heightOfTheWindow)
		*/
		void SetPosition(const sf::Vector2f& centerPosition);
	private:
		std::vector<std::shared_ptr<gui::ClickableComponent>> components;
		sf::Vector2f centerPosition;
		sf::Vector2f regionSize;
	};
}

#endif // !GUI_STRUCTURES_BUILDER_H
