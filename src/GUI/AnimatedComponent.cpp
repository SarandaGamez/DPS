#include "GUI/AnimatedComponent.h"

gui::AnimatedComponent::AnimatedComponent(const sf::Texture& texture)
{
	SetTexture(texture);
	SetLooped(false);
	Stop();
}

void gui::AnimatedComponent::SetTexture(const sf::Texture& texture)
{
	this->sprite.setTexture(texture);
	this->texture = texture;
}

void gui::AnimatedComponent::AddAnimation(const std::string& aniname, unsigned int numberOfFrames, unsigned int row, unsigned int width, unsigned int height)
{
	effects::Animation animation;
	animation.setSpriteSheet(texture);
	for (int i = 0; i < numberOfFrames; i++) {
		animation.addFrame(sf::IntRect(width * i, row, width, height));
	}
	animations[aniname] = animation;
}

void gui::AnimatedComponent::Play(const std::string& aniname)
{
	Stop();
	sprite.play(animations.at(aniname));
}

void gui::AnimatedComponent::Stop()
{
	sprite.stop();
}

void gui::AnimatedComponent::SetLooped(bool isLooped)
{
	sprite.setLooped(isLooped);
}

void gui::AnimatedComponent::SetFrameTime(sf::Time time)
{
	sprite.setFrameTime(time);
}

sf::FloatRect gui::AnimatedComponent::GetGlobalBounds() const
{
	return sprite.getGlobalBounds();
}

effects::AnimatedSprite& gui::AnimatedComponent::GetSprite()
{
	return sprite;
}

void gui::AnimatedComponent::Update(sf::Time time)
{
	sprite.update(time);
}

void gui::AnimatedComponent::OnSetPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

void gui::AnimatedComponent::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
