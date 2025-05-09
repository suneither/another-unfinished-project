#include "Player.h"
#include "../Mobs/Orc.h"


void Player::Initialize()
{
    sprite.setScale(SCALE, SCALE);
    sprite.setOrigin(sf::Vector2f(textureSize.x / 2, textureSize.y / 2));
    sprite.setPosition(660, 540);
}

void loadTextures(const char* path, sf::Texture* textures, int textureWidth, int textureHeight, int textureCount)
{
    sf::Texture tempTexture;
    for (int i = 0; i < textureCount; i++) {
        if (!tempTexture.loadFromFile(path, sf::IntRect(textureWidth * i, 0, textureWidth, textureHeight)))
        {
            std::cout << "Failed to load texture with path: " << path << std::endl;
        }

        textures[i] = tempTexture;
    }
}

void Player::Load()
{
    loadTextures("Textures/Soldier-Idle.png", idleTextures, textureSize.x, textureSize.y, 6);
    loadTextures("Textures/Soldier-Walk.png", walkTextures, textureSize.x, textureSize.y, 8);
    loadTextures("Textures/Soldier-Attack01.png", normalAttackTextures, textureSize.x, textureSize.y, 6);
    sprite.setTexture(idleTextures[0]);
}

void Player::UpdateMovement(float dt)
{
    if (animationState == attacking)
        return;

    animationState = idle;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        animationState = walking;
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(0, -dt * movementSpeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        animationState = walking;
        sprite.setScale(-SCALE, SCALE);
        movementDir = Dir::LEFT;
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(-dt * movementSpeed, 0));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        animationState = walking;
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(0, dt * movementSpeed));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        animationState = walking;
        sprite.setScale(SCALE, SCALE);
        movementDir = Dir::RIGHT;
        sprite.setPosition(sprite.getPosition() + sf::Vector2f(dt * movementSpeed, 0));
    }
}

void Player::UpdateHitBoxes(float dt)
{
    switch (movementDir)
    {
        case RIGHT:
        {
            weaponHitbox.UpdatePosition(sprite.getPosition(), sf::Vector2f(0, 0));
            hitbox.UpdatePosition(sprite.getPosition(), sf::Vector2f(0, 0));
            break;
        }
        case LEFT:
        {
            weaponHitbox.UpdatePosition(sprite.getPosition(), sf::Vector2f(50, 0));
            hitbox.UpdatePosition(sprite.getPosition(), sf::Vector2f(0, 0));
            break;
        }
    }
        


}

void Player::UpdateAttack(float dt)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        animationState = attacking;
    }
}

void Player::UpdateMovementAnimation(float dt)
{
    timeSinceLastTextureChange += dt;

    if (timeSinceLastTextureChange >= movementAnimationSpeed) {

        timeSinceLastTextureChange = 0;
        if (movementTextureIndex >= 7)
        {
            movementTextureIndex = 0;
        }
        else
        {
            movementTextureIndex++;
        }

        sprite.setTexture(walkTextures[movementTextureIndex]);
    }
}

void Player::UpdateIdleAnimation(float dt)
{
    timeSinceLastTextureChange += dt;

    if (timeSinceLastTextureChange >= idleAnimationSpeed)
    {
        timeSinceLastTextureChange = 0;
        if (idleTextureIndex >= 5)
        {
            idleTextureIndex = 0;
        }
        else
        {
            idleTextureIndex++;
        }
        sprite.setTexture(idleTextures[idleTextureIndex]);
    }

    
}

void Player::UpdateNormalAttackAnimation(float dt)
{
    timeSinceLastTextureChange += dt;

    if (timeSinceLastTextureChange >= normalAttackAnimationSpeed)
    {
        timeSinceLastTextureChange = 0;
        if (normalAttackTextureIndex >= 5)
        {
            normalAttackTextureIndex = 0;
            animationState = idle;
        }
        else
        {
            normalAttackTextureIndex++;
        }
        sprite.setTexture(normalAttackTextures[normalAttackTextureIndex]);


        if (normalAttackTextureIndex == 3)
        {
            Attack();
        }
    }
}

void Player::Attack()
{

    std::list<Orc*> to_remove;
    for (Orc* orc : enemies)
    {
        if (Math::IsColliding(weaponHitbox, orc->hitbox))
        {
            if (orc->Hurt(damage))
            {
                to_remove.push_back(orc);
            }
        }
    }

    for (Orc* orc : to_remove)
        enemies.remove(orc);
   
}

void Player::Update(float dt)
{
    UpdateMovement(dt);
    UpdateHitBoxes(dt);
    UpdateAttack(dt);

    if (animationState == attacking)
        // update animation will call animation attack
        // it will determine damage and or hit target
        UpdateNormalAttackAnimation(dt);
    else if (animationState == walking)
        UpdateMovementAnimation(dt);
    else if (animationState == idle)
        UpdateIdleAnimation(dt);

}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(hitbox.visual);
    window.draw(weaponHitbox.visual);
}