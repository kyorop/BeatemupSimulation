#pragma once
#include "Scene_Base.h"
#include"Map.h"

class Scene_Gameover
	:public Scene_Base
{
	int h_background;
	int h_ground;
	int h_gameover;

	const int gameoverX = 640 / 2 - 544 / 2;
	const int gameoverY = 480 / 2 - 416 / 2-60;

	void UpdateScene() override;
	bool mouse_down;
	int h_title;
	Map* map;
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
};
