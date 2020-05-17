#ifndef GUI_TOOLTIP_COMPONENT_H
#define GUI_TOOLTIP_COMPONENT_H

#include "GUI/UIComponent.h"
#include "GUI/GraphicComponent.h"
#include "GUI/TextComponent.h"

namespace gui {

	class TooltipComponent : public gui::UIComponent {

	public:
		TooltipComponent(const sf::Texture& texture, const sf::Font& font, const std::string& text, const sf::Vector2f& position);
		void Update();
		void ScaleText(unsigned int characterSize);
	private:
		std::shared_ptr<gui::GraphicComponent> background;
		std::shared_ptr<gui::TextComponent> caption;

	protected:
		virtual void OnSetPosition(sf::Vector2f position) override;
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // !GUI_TOOLTIP_COMPONENT_H