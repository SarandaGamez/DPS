#ifndef BUTTON_H
#define BUTTON_H

#include <sfml/Graphics/Sprite.hpp>
#include <sfml/Graphics/Image.hpp>
#include <sfml/Graphics.hpp>

class Button : public sf::Drawable{
public:
	Button(const sf::Texture& normalTexture, const sf::Texture& clickedTexture, const sf::Font& font, const std::string& text,const sf::Vector2f& position);
	void SetText(std::string text);
	void SetPosition(sf::Vector2f position);
	void CheckClick(sf::Vector2f click);
	void SetClicked(bool state);
	bool IsClicked();

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	sf::Sprite normalSprite;
	sf::Sprite clickedSprite;
	sf::Sprite* currentSprite;
	sf::Text text;
	bool isClicked;
};

#endif // BUTTON_H