#include "TexturesHolder.h"
#include <stdexcept>

const sf::Texture& TexturesHolder::GetTexture(const std::string& name)
{
    if(textures.count(name) > 0)
        return *textures[name];
    else   
        throw std::runtime_error("There is no texture with this name " + name);
}

const sf::Texture& TexturesHolder::Load(const std::string& name, const std::string& src)
{
    std::unique_ptr<sf::Texture> tex(new sf::Texture());
    tex->loadFromFile("resources/textures/"+src+".png");
    textures.insert(std::make_pair(name,std::move(tex)));

    return *textures[name];

}