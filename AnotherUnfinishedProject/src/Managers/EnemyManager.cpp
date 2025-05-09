#pragma once
#include "EnemyManager.h"
#include "../Entities/Mobs/Orc.h"
#include "../Entities/Player/Player.h"

void EnemyManager::Spawn() {
	Orc orc(m_Player);
	orc.Initialize();
	orc.Load();
	orc.SetPosition(GetRandomPosition(m_Player->sprite.getPosition()));
	enemies.push_back(&orc);
}

sf::Vector2f EnemyManager::GetRandomPosition(sf::Vector2f playerPos)
{
	// implement random position afar 300 from pixels from player
    const float minDistance = 300.0f;
    const float maxDistance = 600.0f;

    // Random angle (0 to 360 degrees)
    float angle = static_cast<float>(rand() % 360) * 3.14159f / 180.0f; // Convert to radians

    // Random distance (between minDistance and maxDistance)
    float distance = minDistance + static_cast<float>(rand()) / RAND_MAX * (maxDistance - minDistance);

    // Convert polar to Cartesian
    float offsetX = std::cos(angle) * distance;
    float offsetY = std::sin(angle) * distance;

    return sf::Vector2f(playerPos.x + offsetX, playerPos.y + offsetY);
}

bool EnemyManager::CanSpawn(float dt) 
{
    timeTillNextSpawn -= dt;
    if (timeTillNextSpawn <= 0.0f) {
        timeTillNextSpawn = defaultSpawnTime;
        return true;
    }
    return false;
}