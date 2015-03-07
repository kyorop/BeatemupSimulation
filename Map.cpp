#include "Map.h"

Map* Map::instance;

Map::Map()
{
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		m_numobjects[i] = 0;
	}
}


Map::~Map()
{
}