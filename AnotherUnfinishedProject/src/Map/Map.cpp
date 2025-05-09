#include "Map.h"

void Map::InitMap()
{
    sf::Vector2i tileSize(32, 32);

    for (int i = 0; i < mapSize.x; i++)
    {
        for (int j = 0; j < mapSize.y; j++)
        {
            sf::Vertex* vertex = &vertices[(i + j * mapSize.x) * 6]; // get first index of next 6 vertices forming 2 triangles

            vertex[0].position = sf::Vector2f(tileSize.x * i, tileSize.y * j);
            vertex[1].position = sf::Vector2f(tileSize.x * (i + 1), tileSize.y * j);
            vertex[2].position = sf::Vector2f(tileSize.x * i, tileSize.y * (j + 1));
            vertex[3].position = sf::Vector2f(tileSize.x * i, tileSize.y * (j + 1));
            vertex[4].position = sf::Vector2f(tileSize.x * (i + 1), tileSize.y * j);
            vertex[5].position = sf::Vector2f(tileSize.x * (i + 1), tileSize.y * (j + 1));

            int tileIndex = Math::RandomNumber(0, 17);

            vertex[0].texCoords = sf::Vector2f(tileIndex * 16, 0);
            vertex[1].texCoords = sf::Vector2f((tileIndex + 1) * 16, 0);
            vertex[2].texCoords = sf::Vector2f(tileIndex * 16, 16);
            vertex[3].texCoords = sf::Vector2f(tileIndex * 16, 16);
            vertex[4].texCoords = sf::Vector2f((tileIndex + 1) * 16, 0);
            vertex[5].texCoords = sf::Vector2f((tileIndex + 1) * 16, 16);
        }

    }
}

sf::VertexArray Map::GetVertices()
{
    return vertices;
}

sf::RenderStates Map::GetStates()
{
    return states;
}