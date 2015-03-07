#pragma once
#include "Scene_Base.h"

class PLAYER;

class Scene_Game
	: public Scene_Base
{
	void UpdateScene() override;
	PLAYER* player;
public:
	void Initialize() override;
	void Update() override;
	void Draw() override;
public:
	
};
