#pragma once
#include <SFML/Graphics.hpp>
#include "HitBoxData.h"

class HitBox
{
private:
	HitBoxData m_hitBoxData;

public:
	sf::RectangleShape visual;

public:
	HitBox(HitBoxData hitBoxData, int SCALE, sf::Color color);
	void UpdatePosition(sf::Vector2f associatePosition, sf::Vector2f correctionOffset);
};