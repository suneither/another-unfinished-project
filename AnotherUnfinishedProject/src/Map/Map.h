#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Helpers/Loader.h"
#include "../Helpers/Math.h"

class Map
{
private:
	sf::Texture terrainTexturesTileset;
	sf::Vector2i mapSize = sf::Vector2i(70, 40);

	sf::VertexArray vertices;
	sf::RenderStates states;

public:
	Map()
	{
		terrainTexturesTileset = Loader::LoadTexture("Textures/Terrain/terrainTilesetBig.png");
		vertices = sf::VertexArray(sf::PrimitiveType::Triangles, 6 * mapSize.x * mapSize.y);
		states.texture = &terrainTexturesTileset;
		InitMap();
	}

	void InitMap();
	sf::VertexArray GetVertices();
	sf::RenderStates GetStates();
};