#pragma once
#include "Scene_Base.h"

class PLAYER;
class Map;
class Scene_Game
	: public Scene_Base
{
	void UpdateScene() override;
	PLAYER* player;
	Map* map;
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
public:
	void backGroundDraw();
	int leftX;
private:
	int background;
	
};
