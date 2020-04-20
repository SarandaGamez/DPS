#include "..\..\include\Cinematics\Slide.h"

Slide::Slide(const std::string& caption, const sf::Font& font,const sf::Texture& texture)
{
	SetCaption(caption);
	SetPictureTexture(texture);
	SetFont(font);
	CenterCaption(80, 90);
}

void Slide::SetCaption(const std::string& caption)
{
	this->caption.setString(caption);
}

void Slide::SetFont(const sf::Font& font)
{
	this->caption.setFont(font);
}

void Slide::CenterCaptionHorizontal(float picturesWidthPercentage)
{
	float captionLenght = picture.getLocalBounds().getSize().x / 100 * picturesWidthPercentage;
	size_t characterSize = captionLenght / caption.getString().getSize();
	this->caption.setCharacterSize(characterSize);
	float x = picture.getPosition().x + picture.getLocalBounds().getSize().x - captionLenght - captionLenght / 100 * (100 - picturesWidthPercentage) / 2;
	this->caption.setPosition(x, this->caption.getPosition().y);
}

void Slide::CenterCaptionVertical(float picturesHeightPercentage)
{
	float y = picture.getPosition().y + picture.getLocalBounds().getSize().y / 100 * picturesHeightPercentage;
	this->caption.setPosition(this->caption.getPosition().x, y);
}

void Slide::SetPictureTexture(const sf::Texture& texture)
{
	this->picture.setTexture(texture);
}

void Slide::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(picture, states);
	target.draw(caption, states);

}

void Slide::CenterCaption(float picturesWidthPercentage, float picturesHeightPercentage)
{
	CenterCaptionHorizontal(picturesWidthPercentage);
	CenterCaptionVertical(picturesHeightPercentage);
}
