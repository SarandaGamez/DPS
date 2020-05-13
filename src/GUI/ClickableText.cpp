#include "GUI/ClickableText.h"
#include "GUI/EventBehavior/MouseButtonReleasedBehavior.h"

namespace gui {

	ClickableText::ClickableText(const sf::Font& font, const std::string& caption, const sf::Vector2f& position)
	{
		SetFont(font);
		SetText(caption);
		SetPosition(position);
	}
	void ClickableText::SetFont(const sf::Font& font)
	{
		this->text.SetFont(font);
	}
	void ClickableText::SetText(const std::string& string)
	{
		this->text.SetText(string);
	}
	void ClickableText::SetCharacterSize(unsigned int size)
	{
		this->SetCharacterSize(size);
	}

	void ClickableText::Update()
	{
		this->text.Update();
	}

	void ClickableText::OnSetPosition(sf::Vector2f position)
	{
		gui::ClickableComponent::OnSetPosition(position);
		text.SetPosition(position);
		SetRegion(text.GetGlobalBounds());
	}

	void ClickableText::OnDraw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(text, states);
	}
}