#ifndef SLIDE_H
#define SLIDE_H

#include <string>
#include <sfml/Graphics.hpp>

class Slide : public sf::Drawable{

	sf::Sprite picture;
	sf::Text caption;

public:
	Slide(const std::string& caption, const sf::Font& font,const sf::Texture& texture);

	void SetCaption(const std::string& caption);
	void SetFont(const sf::Font& font);
	void CenterCaptionHorizontal(float picturesWidthPercentage);
	void CenterCaptionVertical(float picturesHeightPercentage);
	void CenterCaption(float picturesWidthPercentage, float picturesHeightPercentage);
	void SetPictureTexture(const sf::Texture& texture);


	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif // SLIDE_H