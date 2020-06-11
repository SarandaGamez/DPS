#ifndef GUI_CLICKABLE_COMPONENT_H
#define GUI_CLICKABLE_COMPONENT_H

#include "GUI/UIComponent.h"
#include <SFML/Graphics/Rect.hpp>

namespace gui {

	class ClickableComponent : public gui::UIComponent {
		sf::FloatRect clickableRegion;
		
	public:
		ClickableComponent();
		virtual bool IsMouseInRegion(const sf::Vector2f& mousePosition);
		void SetRegion(const sf::FloatRect& region);
		sf::FloatRect GetRegion();

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual bool CheckEventCondition(const sf::Event& event);
	};
}

#endif // !GUI_CLICKABLE_COMPONENT_H
