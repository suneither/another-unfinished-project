#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Helpers/Math.h"

class Player;

class Orc
{
private:

	float health = 100;
	sf::Texture idleTextures[6];
	sf::Texture walkTextures[8];

	sf::Vector2f hitBoxSize = sf::Vector2f(7, 14);
	sf::Vector2f hitBoxOffset = sf::Vector2f(8, 20);
	sf::Vector2f textureSize = sf::Vector2f(100, 100);

	HitBoxData HITBOX_DATA = { {hitBoxSize}, {hitBoxOffset} };
	int SCALE = 3;

	float timeSinceLastTextureChange = 0;
	int currentTextureIndex = 0;
	bool isIdle = true;

	Player* m_Player;

	float speed = 30;

public:
	sf::Sprite sprite;
	HitBox hitbox = HitBox(HITBOX_DATA, SCALE, sf::Color::Green);
	int hp = 100;

public:
	Orc(Player* player) : m_Player(player) {};
	void Initialize();
	void Load();
	void SetPosition(sf::Vector2f pos);
	void LoadTexture(const char* path, sf::Texture* idleTextures, int textureCount);
	void Update(float dt);
	void UpdateAnimations();
	void UpdateMovement(float dt);
	void Draw(sf::RenderWindow& window);
	bool Hurt(float damage);
};
