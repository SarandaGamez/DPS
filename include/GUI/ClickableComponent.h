#ifndef GUI_CLICKABLE_COMPONENT_H
#define GUI_CLICKABLE_COMPONENT_H

#include "GUI/UIComponent.h"
#include <SFML/Graphics/Rect.hpp>

namespace gui {

	class ClickableComponent : public gui::UIComponent {
		sf::FloatRect clickableRegion;
		
	public:
		bool IsMouseInRegion(const sf::Vector2f& mousePosition);
		void SetRegion(const sf::FloatRect& region);
		const sf::FloatRect& GetRegion();
	};
}

#endif // !GUI_CLICKABLE_COMPONENT_H
