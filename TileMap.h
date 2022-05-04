#pragma once

#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile*>> m_tileMap;

public:
	TileMap();
	~TileMap();

	void update(sf::Vector2u& mouseGridPosition);

	void render(sf::RenderTarget* target);

	void placeTile(sf::Vector2u& mouseGridPosition);

	

	//Accesros
	int size();
	int size(int x);
	Tile* getTile(int indexI, int indexK);


};

