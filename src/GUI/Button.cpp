#include "GUI/Button.h"

Button::Button(const sf::Texture& normalTexture, const sf::Texture& clickedTexture, const sf::Font& font, const std::string& text, const sf::Vector2f& position)
{
	normalSprite.setTexture(normalTexture);
	clickedSprite.setTexture(clickedTexture);
	currentSprite = &normalSprite;
	isClicked = false;
	this->text.setFont(font);
	this->text.setCharacterSize(35);
	SetText(text);
	SetPosition(position);

}

void Button::CheckClick(sf::Vector2f click)
{
	bool contains = currentSprite->getGlobalBounds().contains(click);
	SetClicked(contains);
}

 void Button::SetText(std::string text)
{
	 this->text.setString(text);
}

 void Button::SetPosition(sf::Vector2f position)
 {
	 this->normalSprite.setPosition(position);
	 this->clickedSprite.setPosition(position);
	 this->text.setPosition(position.x + 5, position.y + 5);
 }

 void Button::SetClicked(bool state)
 {
	 this->isClicked = state;
	 if (isClicked) {
		 this->currentSprite = &clickedSprite;
		 return;
	 }
	 this->currentSprite = &normalSprite;
 }

 bool Button::IsClicked()
 {
	 return isClicked;
 }

 void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
 {
	 target.draw(*currentSprite, states);
	 target.draw(text, states);
 }
