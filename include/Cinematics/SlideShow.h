#ifndef SLIDESHOW_H
#define SLIDESHOW_H

#include <vector>
#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Cinematics/Slide.h"

class Slideshow {

	int currentSlide;
	std::vector <std::shared_ptr<Slide>> slides;
public:
	Slideshow();
	void Add(const std::string& caption, const sf::Font& font, const sf::Texture& texture);
	void Draw(std::shared_ptr<sf::RenderWindow> renderWindow);
	void Next();
	bool IsOver();

};

#endif // SLIDESHOW_H
