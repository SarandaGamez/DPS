#ifndef TEXTURES_HOLDER_H
#define TEXTURES_HOLDER_H

#include <SFML/Graphics/Texture.hpp>
#include <map>
#include <string>
#include <memory>

class TexturesHolder
{
    std::map<std::string,std::unique_ptr<sf::Texture>> textures;

public:

    const sf::Texture& GetTexture(const std::string& id);
    const sf::Texture& Load(const std::string& id, const std::string& src);
};

#endif // TEXTURES_HOLDER_H