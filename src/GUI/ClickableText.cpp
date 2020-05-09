#include "GUI/ClickableText.h"
#include "GUI/MouseButtonReleasedBehavior.h"

namespace gui {

	ClickableText::ClickableText(const sf::Font& font, const std::string& caption, const sf::Vector2f& position)
	{
		SetFont(font);
		SetText(caption);
		SetPosition(position);

		GetEventBehaviors().Add(std::make_shared<gui::MouseButtonReleasedBehavior>(this));
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

	void ClickableText::draw(std::shared_ptr<sf::RenderWindow> renderWindow) const
	{
		renderWindow->draw(this->text);
	}

	void ClickableText::OnSetPosition(sf::Vector2f position)
	{
		gui::ClickableComponent::OnSetPosition(position);
		text.SetPosition(position);
		SetRegion(text.GetGlobalBounds());
	}
}