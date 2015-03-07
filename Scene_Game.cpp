#include "Scene_Game.h"
#include"PLAYER.h"

void Scene_Game::UpdateScene()
{
}

void Scene_Game::Initialize()
{
	player = new PLAYER();
}
void Scene_Game::Update()
{
	player->DoJump();
	player->CheckOnGround();
	player->GraphNumChange();
	player->PlayerMove();
}

void Scene_Game::Draw()
{
	player->PlayerDraw();
}