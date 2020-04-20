#include "Cinematics/SlideShow.h"


Slideshow::Slideshow()
{
	currentSlide = 0;
}

void Slideshow::Add(const std::string & caption, const sf::Font& font, const sf::Texture & texture)
{
	slides.push_back(std::make_shared<Slide>(caption, font, texture));
}

void Slideshow::Draw(std::shared_ptr<sf::RenderWindow> renderWindow)
{
	if(currentSlide < slides.size())
		renderWindow->draw(*slides[currentSlide]);
}

void Slideshow::Next()
{
	if (!IsOver()) {
		currentSlide++;
	}
}

bool Slideshow::IsOver()
{
	return currentSlide >= slides.size() - 1;
}
