#include "GUI/Button.h"
#include "GUI/MouseButtonReleasedBehavior.h"

namespace gui {

	Button::Button(const sf::Texture& texture, const sf::Vector2f& position)
	{
		SetTexture(texture);
		SetPosition(position);
		SetRegion(graphic.GetGlobalBounds());
	}

	void Button::SetTexture(const sf::Texture& texture)
	{
		this->graphic.SetTexture(texture);
	}

	void Button::Update()
	{
		this->graphic.Update();
	}

	void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(graphic, states);
	}

	void Button::OnSetPosition(sf::Vector2f position)
	{
		gui::ClickableComponent::OnSetPosition(position);
		graphic.SetPosition(position);
		SetRegion(graphic.GetGlobalBounds());
	}
}