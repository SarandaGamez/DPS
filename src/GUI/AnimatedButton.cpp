#include "GUI/AnimatedButton.h"
#include "Utils/Collision.h"

gui::AnimatedButton::AnimatedButton(std::shared_ptr<gui::AnimatedComponent> animated, const sf::Vector2f& position)
{
	gui::ClickableComponent::ClickableComponent();
	this->animated = animated;
	SetPosition(position);
	SetRegion(animated->GetGlobalBounds());
}

void gui::AnimatedButton::SetTexture(const sf::Texture& texture)
{
	this->animated->SetTexture(texture);
}

void gui::AnimatedButton::Update(sf::Time time)
{
	this->animated->Update(time);
	SetRegion(animated->GetGlobalBounds());
}

bool gui::AnimatedButton::IsMouseInRegion(const sf::Vector2f& mousePosition)
{
	if (animated->GetGlobalBounds().contains(mousePosition)) {
		return Collision::PixelPerfectMouseTest(animated->GetSprite(), mousePosition);
	}
	return false;
}

std::shared_ptr<gui::AnimatedComponent> gui::AnimatedButton::GetAnimatedComponent()
{
	return this->animated;
}

void gui::AnimatedButton::OnSetPosition(sf::Vector2f position)
{
	gui::ClickableComponent::OnSetPosition(position);
	animated->SetPosition(position);
	SetRegion(animated->GetGlobalBounds());
}

void gui::AnimatedButton::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*animated, states);
}
