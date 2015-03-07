﻿#include "Scene_Mapcreate.h"
#include <DxLib.h>

void Scene_Mapcreate::UpdateScene()
{

}

Scene_Mapcreate::Scene_Mapcreate()
	:objWindowX1(10),
	objWindowY1(360 + 10),
	objWindowX2(objWindowX1 + 640 - 20),
	objWindowY2(objWindowY1 + 100),
	groundX1(0),
	groundY1(280),
	groundX2(640),
	groundY2(groundY1)
{
}

void Scene_Mapcreate::Update()
{
}

void Scene_Mapcreate::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "This scene is Mapcreate");
	DrawLine(groundX1, groundY1, groundX2, groundY2, GetColor(255, 0, 0), 4);
	DrawBox(objWindowX1, objWindowY1, objWindowX2, objWindowY2, GetColor(255, 0, 0), false);
}