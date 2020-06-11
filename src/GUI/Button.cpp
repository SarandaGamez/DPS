#include "GUI/Button.h"
#include "GUI/EventBehavior/MouseButtonReleasedBehavior.h"
#include "Utils/Collision.h"

namespace gui {

	Button::Button(const sf::Texture& texture, const sf::Vector2f& position)
	{
		gui::ClickableComponent::ClickableComponent();
		graphic = std::make_shared<gui::GraphicComponent>(texture);
		SetPosition(position);
		SetRegion(graphic->GetGlobalBounds());
	}

	void Button::SetTexture(const sf::Texture& texture)
	{
		this->graphic->SetTexture(texture);
	}

	void Button::Update(sf::Time time)
	{
		this->graphic->Update(time);
	}

	bool Button::IsMouseInRegion(const sf::Vector2f& mousePosition)
	{
		return Collision::PixelPerfectMouseTest(graphic->GetSprite(), mousePosition);
	}

	std::shared_ptr<gui::GraphicComponent> Button::GetGraphicComponent()
	{
		return this->graphic;
	}
	
	void Button::OnSetPosition(sf::Vector2f position)
	{
		gui::ClickableComponent::OnSetPosition(position);
		graphic->SetPosition(position);
		SetRegion(graphic->GetGlobalBounds());
	}

	void Button::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*graphic, states);
	}
}