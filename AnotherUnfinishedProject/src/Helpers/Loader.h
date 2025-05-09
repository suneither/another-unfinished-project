#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"

class Loader
{
public:
	static sf::Texture LoadTexture(const char* path);
};
