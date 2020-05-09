#ifndef GUI_GRAPHIC_COMPONENT_H
#define GUI_GRAPHIC_COMPONENT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GUI/UIComponent.h"

namespace gui {

	class GraphicComponent : public gui::UIComponent{
		sf::Sprite sprite;

	public:
		void SetTexture(const sf::Texture& texture);
		sf::FloatRect GetGlobalBounds() const;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
	};
}

#endif // GUI_GRAPHIC_COMPONENT_H