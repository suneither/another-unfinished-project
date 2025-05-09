#include "Loader.h"

sf::Texture Loader::LoadTexture(const char* path)
{
    sf::Texture tempTexture;
    if (!tempTexture.loadFromFile(path))
    {
        std::cout << "Failed to load texture with path: " << path << std::endl;
    }
    return tempTexture;
}