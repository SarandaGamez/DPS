#ifndef GUI_ANIMATED_BUTTON_H
#define GUI_ANIMATED_BUTTON_H

#include <sfml/Graphics.hpp>
#include "GUI/ClickableComponent.h"
#include "GUI/AnimatedComponent.h"

namespace gui {

	class AnimatedButton : public gui::ClickableComponent {

	public:
		AnimatedButton(std::shared_ptr<gui::AnimatedComponent> animated, const sf::Vector2f& position);
		void SetTexture(const sf::Texture& texture);
		virtual void Update(sf::Time time) override;
		virtual bool IsMouseInRegion(const sf::Vector2f& mousePosition) override;
		std::shared_ptr<gui::AnimatedComponent> GetAnimatedComponent();

	private:
		std::shared_ptr<gui::AnimatedComponent> animated;

	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // GUI_ANIMATED_BUTTON_H