#include "Scene_Gameover.h"
#include <DxLib.h>

void Scene_Gameover::UpdateScene()
{
}

void Scene_Gameover::Initialize()
{
	h_background = LoadGraph("img/background.png");
	h_ground = LoadGraph("img/ground.png");
	h_gameover = LoadGraph("img/gameover.png");
}

void Scene_Gameover::Update()
{
}

void Scene_Gameover::Draw()
{
	DrawExtendGraph(0, 0, 640, 360, h_background, false);
	DrawExtendGraph(0, 360, 640, 480, h_ground, false);
	DrawGraph(gameoverX, gameoverY, h_gameover, true);
}