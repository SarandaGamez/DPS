#include "Cinematics/SlideShow.h"

Slideshow::Slideshow(const sf::Font& font)
{
	this->text.setFont(font); 
	currentSlide = 0;
}

void Slideshow::add(const std::string & caption, const sf::Texture & texture)
{
	captions.push_back(caption);
	sprites.push_back(std::make_shared<sf::Sprite>(texture));
	text.setString(captions[currentSlide]);
	text.setPosition(100, sprites[currentSlide]->getPosition().y + sprites[currentSlide]->getGlobalBounds().getSize().y - text.getLocalBounds().getSize().y - 100);
}


void Slideshow::draw(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	renderWindow->draw(*sprites[currentSlide]);
	renderWindow->draw(text);
}

void Slideshow::next()
{
	if (!isOver()) {
		currentSlide++;
		text.setString(captions[currentSlide]);
		text.setPosition(100, sprites[currentSlide]->getPosition().y + sprites[currentSlide]->getGlobalBounds().getSize().y - text.getLocalBounds().getSize().y - 10);
	}
}

bool Slideshow::isOver()
{
	return currentSlide == captions.size() - 1;
}