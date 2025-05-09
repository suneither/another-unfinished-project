#pragma once
#include <SFML/Graphics.hpp>
#include "../../AnimationState.cpp"
#include "../HitBox.h"
#include "../../Helpers/Math.h"
#include <iostream>
#include "../../Managers/EnemyManager.h"

enum Dir
{
	RIGHT = 0,
	LEFT = 1
};

class Player
{
private:
	float damage = 50;

	sf::Texture idleTextures[6];
	sf::Texture walkTextures[8];
	sf::Texture normalAttackTextures[6];

	sf::Vector2f textureSize = sf::Vector2f(100, 100);

	sf::Vector2f hitBoxSize = sf::Vector2f(7, 14);
	sf::Vector2f hitBoxOffset = sf::Vector2f(9, 20);
	HitBoxData HITBOX_DATA = { {hitBoxSize}, {hitBoxOffset} };

	sf::Vector2f weaponHitBoxSize = sf::Vector2f(20, 16);
	sf::Vector2f weaponHitBoxOffset = sf::Vector2f(5, 20);
	HitBoxData WEAPON_HITBOX_DATA = { {weaponHitBoxSize}, {weaponHitBoxOffset} };
	
	int SCALE = 3;

	AnimationState animationState = idle;
	float timeSinceLastTextureChange = 0;

	float movementSpeed = 200.0f;
	float movementAnimationSpeed = 100 / (movementSpeed * 6);
	int movementTextureIndex = 0;
	Dir movementDir = Dir::RIGHT;

	float attackSpeed = 2.0f; // 2/s
	float normalAttackAnimationSpeed = 1 / (attackSpeed * 6);
	int normalAttackTextureIndex = 0;

	float idleAnimationSpeed = 0.2f;
	int idleTextureIndex = 0;

public:
	sf::Sprite sprite;
	HitBox hitbox = HitBox(HITBOX_DATA, SCALE, sf::Color::Green);
	HitBox weaponHitbox = HitBox(WEAPON_HITBOX_DATA, SCALE, sf::Color::Red);
public:
	void Initialize();
	void Load();

	void Update(float dt);
	
	void UpdateMovement(float dt);
	void UpdateHitBoxes(float dt);
	void UpdateAttack(float dt);
	void UpdateNormalAttack(float dt);

	void UpdateMovementAnimation(float dt);
	void UpdateIdleAnimation(float dt);
	void UpdateNormalAttackAnimation(float dt);
	
	void Attack();
	void Draw(sf::RenderWindow& window);
};