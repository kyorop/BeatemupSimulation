﻿#pragma once
#include "Scene_Base.h"

class Scene_Game
	: public Scene_Base
{
	void UpdateScene() override;
public:
	void Update() override;
	void Draw() override;
public:
	
};