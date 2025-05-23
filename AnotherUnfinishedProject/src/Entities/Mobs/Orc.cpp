#include "Orc.h"
#include "../Player/Player.h"
#include <algorithm> 

void Orc::Initialize()
{
	sprite->setOrigin(sf::Vector2f(textureSize.x / 2, textureSize.y / 2));
	sprite->setScale(sf::Vector2f(SCALE, SCALE));
	sprite->setPosition(sf::Vector2f(1160, 540));
}

void Orc::SetPosition(sf::Vector2f pos)
{
	sprite->setPosition(pos);
}


void Orc::LoadTexture(const char* path, sf::Texture* textures, int textureCount)
{
	sf::Texture tempTexture;
	for (int i = 0; i < textureCount; i++)
	{
		if (!tempTexture.loadFromFile(path, false, sf::IntRect({ textureSize.x * i, 0 }, { textureSize.x, textureSize.y })))
		{
			std::cout << "Failed to load texture with path:" << path << std::endl;
		}
		textures[i] = tempTexture;
	}
}

void Orc::Load()
{
	LoadTexture("Textures/Orc-Idle.png", idleTextures, 6);
	LoadTexture("Textures/Orc-Walk.png", walkTextures, 8);
	sprite->setTexture(idleTextures[0]);
}

void Orc::UpdateAnimations()
{
	if (timeSinceLastTextureChange >= 0.2f && isIdle)
	{
		timeSinceLastTextureChange = 0;
		if (currentTextureIndex >= 5)
		{
			currentTextureIndex = 0;
		}
		else
		{
			currentTextureIndex++;
		}

		sprite->setTexture(idleTextures[currentTextureIndex]);
	}

	if (timeSinceLastTextureChange >= 0.2f && !isIdle)
	{
		timeSinceLastTextureChange = 0;
		if (currentTextureIndex >= 7)
		{
			currentTextureIndex = 0;
		}
		else
		{
			currentTextureIndex++;
		}

		sprite->setTexture(walkTextures[currentTextureIndex]);
	}
}

void Orc::UpdateMovement(float dt)
{
	sf::Vector2f direction = m_Player->sprite->getPosition() - sprite->getPosition();
	sf::Vector2f normalizedVector = Math::NormalizeVector(direction);

	isIdle = false;
	if (normalizedVector.x >= 0)
		sprite->setScale(sf::Vector2f(SCALE, SCALE));
	else
		sprite->setScale(sf::Vector2f(-SCALE, SCALE));

	sprite->setPosition(sprite->getPosition() + (normalizedVector * dt * speed));
	hitbox.UpdatePosition(sprite->getPosition(), sf::Vector2f(0,0));
}

void Orc::Update(float dt)
{
	timeSinceLastTextureChange += dt;
	isIdle = true;
	UpdateMovement(dt);
	UpdateAnimations();
}

void Orc::Draw(sf::RenderWindow& window)
{
	window.draw(*sprite);
	window.draw(hitbox.visual);
}

bool Orc::Hurt(float damage)
{
	health -= damage;
	if (health <= 0)
	{
		std::cout << "dead" << std::endl;
		return true;
	}
	else
	{
		std::cout << "Orc hurt " << health << std::endl;
		return false;
	}

}