#include "Scene_Game.h"
#include"PLAYER.h"

void Scene_Game::UpdateScene()
{
	if (player->CheckGameover())
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_GAMEOVER);
	}
}

void Scene_Game::Initialize()
{
	player = new PLAYER();
	player->PlayerIni();
}
void Scene_Game::Update()
{
	UpdateScene();
	player->CheckOnGround();
	player->DoJump();
	player->GraphNumChange();
	player->PlayerMove();
}

void Scene_Game::Draw()
{
	player->PlayerDraw();
}