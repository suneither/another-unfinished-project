#include "HitBox.h"
#include <iostream>

HitBox::HitBox(HitBoxData hitBoxData, int scale, sf::Color color)
    : m_hitBoxData(hitBoxData)
{
    visual.setOutlineColor(color);
    visual.setOutlineThickness(1);
    visual.setFillColor(sf::Color::Transparent);

    visual.setSize(sf::Vector2f(m_hitBoxData.size.x * scale, m_hitBoxData.size.y * scale));
}

void HitBox::UpdatePosition(sf::Vector2f associatePosition, sf::Vector2f correctionOffset)
{
    visual.setPosition(associatePosition - m_hitBoxData.offset - correctionOffset);
}
