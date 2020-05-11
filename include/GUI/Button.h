#ifndef BUTTON_H
#define BUTTON_H

#include <sfml/Graphics.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/GraphicComponent.h"

namespace gui {

	class Button : public gui::ClickableComponent {

	public:
		Button(const sf::Texture& texture, const sf::Vector2f& position);
		void SetTexture(const sf::Texture& texture);
		void Update();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	private:
		gui::GraphicComponent graphic;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
	};
}

#endif // BUTTON_H