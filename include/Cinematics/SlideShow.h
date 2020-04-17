#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <vector>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

class Slideshow {

	int currentSlide = 0;
	std::vector<std::shared_ptr<sf::Sprite>> sprites;
	std::vector<std::string> captions;
	sf::Text text;
public:
	Slideshow(const sf::Font& font);
	void add(const std::string& caption, const sf::Texture& texture);
	void draw(std::shared_ptr<sf::RenderWindow> renderWindow);
	void next();
	bool isOver();

};

#endif // SLIDESHOW_H
