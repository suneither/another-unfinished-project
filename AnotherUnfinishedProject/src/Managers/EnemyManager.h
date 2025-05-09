#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Orc;
class Player;

inline std::list<Orc*> enemies;

class EnemyManager
{
private:
	float defaultSpawnTime = 3.0f;
	float timeTillNextSpawn = 3.0f;
	Player* m_Player;

	sf::Vector2f GetRandomPosition(sf::Vector2f playerPos);

public:
	EnemyManager(Player* player) : m_Player(player) {};
	bool CanSpawn(float dt);
	void Spawn();
};
