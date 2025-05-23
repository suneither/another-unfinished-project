#include <iostream>
#include <SFML/Graphics.hpp>
#include "Entities/Player/Player.h"
#include "Entities/Mobs/Orc.h"
#include "Managers/EnemyManager.h"
#include "Helpers/Math.h"
#include "Helpers/Loader.h"
#include "Map/Map.h"
#include <vector>

int main()
{
    Map map;

    sf::Texture shrine = Loader::LoadTexture("Textures/Shrine.png");
    sf::Sprite shrineSprite(shrine);
    shrineSprite.setPosition(sf::Vector2f(900, 200));
    shrineSprite.setScale(sf::Vector2f(3,3));

    // INIT FAZE -----------------------------------------------------------------------

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(1920, 1080), 32U), "Unfinished project");
    sf::Clock clock;

    Player player;
    player.Initialize();
    player.Load();

    EnemyManager enemyManger(&player);

    Orc orc2(&player);
    orc2.Initialize();
    orc2.Load();

    Orc orc1(&player);
    orc1.Initialize();
    orc1.Load();


    enemies.push_back(&orc2);
    enemies.push_back(&orc1);

  
    // INIT FAZE -----------------------------------------------------------------------
    int count = 0;
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        // UPDATE FAZE -----------------------------------------------------------------------

        while (const std::optional event = window.pollEvent())
        {
            // "close requested" event: we close the window
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (enemyManger.CanSpawn(dt))
            enemyManger.Spawn();

        player.Update(dt);
        for (Orc* orc : enemies)
        {
            orc->Update(dt);
        }


        // UPDATE FAZE -----------------------------------------------------------------------
        
        // DRAW FAZE -----------------------------------------------------------------------
        
        window.clear(sf::Color::Black);

        window.draw(map.GetVertices(), map.GetStates());

        window.draw(shrineSprite);

        player.Draw(window);
        for (Orc* orc : enemies)
        {
            orc->Draw(window);
        }




        window.display();
        // DRAW FAZE -----------------------------------------------------------------------
    }
    
    return 0;
}