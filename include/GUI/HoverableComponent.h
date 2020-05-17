#ifndef GUI_HOVERABLE_COMPONENT_H
#define GUI_HOVERABLE_COMPONENT_H

#include "GUI/UIComponent.h"

namespace gui {

	class HoverableComponent : public gui::UIComponent {
		sf::FloatRect hoverableRegion;

	public:
		HoverableComponent();
		bool IsMouseInRegion(const sf::Vector2f& mousePosition);
		void SetRegion(const sf::FloatRect& region);
		sf::FloatRect GetRegion();

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual bool CheckEventCondition(const sf::Event& event);
	};
}

#endif // !GUI_HOVERABLE_COMPONENT_H
