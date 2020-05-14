#ifndef GUI_GRAPHIC_COMPONENT_H
#define GUI_GRAPHIC_COMPONENT_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "GUI/UIComponent.h"

namespace gui {

	class GraphicComponent : public gui::UIComponent{
		sf::Sprite sprite;

	public:
		GraphicComponent(const sf::Texture& texture);
		void SetTexture(const sf::Texture& texture);
		sf::FloatRect GetGlobalBounds() const;
		sf::Sprite& GetSprite();

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // GUI_GRAPHIC_COMPONENT_H