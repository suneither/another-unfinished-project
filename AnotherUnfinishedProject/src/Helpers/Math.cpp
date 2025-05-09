#include "Math.h"

sf::Vector2f Math::NormalizeVector(sf::Vector2f vector)
{
	float magnitude = std::sqrt(vector.x * vector.x + vector.y * vector.y);
	if (magnitude == 0) {
		return sf::Vector2f(0.f, 0.f); // Avoid division by zero
	}
	return sf::Vector2f(vector.x / magnitude, vector.y / magnitude);
}

int Math::RandomNumber(int min, int max)
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(min, max); // define the range

	return distr(gen);
}

bool Math::IsColliding(HitBox first, HitBox second)
{
	return first.visual.getGlobalBounds().intersects(second.visual.getGlobalBounds());
}
