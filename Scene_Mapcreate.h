#pragma once
#include "Scene_Base.h"

class Scene_Mapcreate
	:public Scene_Base
{
	const int objWindowX1;
	const int objWindowY1;
	const int objWindowX2;
	const int objWindowY2;

	const int groundX1;
	const int groundY1;
	const int groundX2;
	const int groundY2;

	int handle_square;
	int handle_triangle;
	int handle_hemisphere;
	int handle_hole;
	int handle_spring;

	void UpdateScene() override;
public:
	Scene_Mapcreate();
	void Update() override;
	void Draw() override;
public:
	
};
