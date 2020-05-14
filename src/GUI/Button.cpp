#include "GUI/Button.h"
#include "GUI/EventBehavior/MouseButtonReleasedBehavior.h"

namespace gui {

	Button::Button(const sf::Texture& texture, const sf::Vector2f& position)
	{
		graphic = std::make_shared<gui::GraphicComponent>(texture);
		SetPosition(position);
		SetRegion(graphic->GetGlobalBounds());
	}

	void Button::SetTexture(const sf::Texture& texture)
	{
		this->graphic->SetTexture(texture);
	}

	void Button::Update()
	{
		this->graphic->Update();
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