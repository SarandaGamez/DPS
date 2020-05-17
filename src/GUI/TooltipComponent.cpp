#include "GUI/TooltipComponent.h"

gui::TooltipComponent::TooltipComponent(const sf::Texture& texture, const sf::Font& font, const std::string& text, const sf::Vector2f& position)
{
	background = std::make_shared<gui::GraphicComponent>(texture);
	caption = std::make_shared<gui::TextComponent>();
	caption->SetFont(font);
	caption->SetText(text);
	ScaleText(background->GetGlobalBounds().width / text.length());
	SetPosition(position);
}

void gui::TooltipComponent::Update()
{
	gui::UIComponent::Update();
	background->Update();
	caption->Update();
}

void gui::TooltipComponent::ScaleText(unsigned int characterSize)
{
	if (characterSize >= 28)
		caption->SetCharacterSize(28);
	else
		caption->SetCharacterSize(characterSize);
}

void gui::TooltipComponent::OnSetPosition(sf::Vector2f position)
{
	gui::UIComponent::OnSetPosition(position);
	background->SetPosition(position);
	sf::FloatRect bgr = background->GetGlobalBounds();
	caption->SetPosition({ bgr.left + bgr.width / 2, bgr.top + bgr.height / 2 });
	caption->SetPosition({ caption->GetPosition().x - caption->GetGlobalBounds().width / 2, caption->GetPosition().y - caption->GetGlobalBounds().height / 2 });
}

void gui::TooltipComponent::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
{
	gui::UIComponent::OnDraw(target, states);
	target.draw(*background, states);
	target.draw(*caption, states);
}