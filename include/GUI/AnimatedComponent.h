#ifndef GUI_ANIMATED_COMPONENT_H
#define GUI_ANIMATED_COMPONENT_H

#include <SFML/Graphics/Texture.hpp>
#include "Effects/AnimatedSprite.h"
#include "Effects/Animation.h"
#include "GUI/UIComponent.h"
#include <map>

namespace gui {

	class AnimatedComponent : public gui::UIComponent{
		effects::AnimatedSprite sprite;
		std::map<std::string, effects::Animation> animations;
		sf::Texture texture;

	public:
		AnimatedComponent(const sf::Texture& texture);
		void SetTexture(const sf::Texture& texture);
		void AddAnimation(const std::string& aniname, unsigned int numberOfFrames, unsigned int row, unsigned int width, unsigned int height);
		void Play(const std::string& aniname);
		void Stop();
		void SetLooped(bool isLooped);
		void SetFrameTime(sf::Time time);
		sf::FloatRect GetGlobalBounds() const;
		effects::AnimatedSprite& GetSprite();

		virtual void Update(sf::Time time);
	protected:
		virtual void OnSetPosition(sf::Vector2f position);
		virtual void OnDraw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}

#endif // GUI_ANIMATED_COMPONENT_H