#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include "../Entities/HitBox.h"

class Math
{
public:
	static sf::Vector2f NormalizeVector(sf::Vector2f vector);
	static int RandomNumber(int min, int max);
	static bool IsColliding(HitBox first, HitBox second);
};