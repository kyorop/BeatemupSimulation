#include "Scene_Game.h"
#include"PLAYER.h"
#include "Map.h"
#include"DxLib.h"

void Scene_Game::UpdateScene()
{
	if (player->CheckGameover())
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_GAMEOVER);
	}
	if (player->CheckGameClear(950))
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_GAMEOVER);
	}
}

void Scene_Game::Initialize()
{
	player = new PLAYER();
	player->PlayerIni();
	map = Map::GetInstance();
	background = LoadGraph("img/background.png");
	h_ground = LoadGraph("img/ground.png");
	FlagGraph = LoadGraph("img/Flag.png");
	leftX = 0;
}
void Scene_Game::Update()
{
	UpdateScene();
	player->CheckOnGround();
	player->DoJump();
	player->GraphNumChange();
	player->PlayerMove();
	if (player->GetPosX() >= 324&&player->GetPosX()<=676)leftX += (int)player->GetAddX();
}
void Scene_Game::Draw()
{
	backGroundDraw();
	DrawGraph(950-leftX, 30, FlagGraph, TRUE);
	player->PlayerDraw(leftX);
	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		DrawExtendGraph(map->m_square[r].GetPosX() - leftX,
			map->m_square[r].GetPosY(),
			map->m_square[r].GetPosX() + map->m_square[r].GetSizeWidth() - leftX,
			map->m_square[r].GetPosY() + map->m_square[r].GetSizeHigh(),
			map->m_h_square, TRUE);
	}
	for (int r = 0; r < map->GetNumObject(HEMISPHERE); r++)
	{
		DrawExtendGraph(map->m_hemisphere[r].GetPosX() - leftX,
			map->m_hemisphere[r].GetPosY(),
			map->m_hemisphere[r].GetPosX() + map->m_hemisphere[r].GetSizeWidth() - leftX,
			map->m_hemisphere[r].GetPosY() + map->m_hemisphere[r].GetSizeHigh(),
			map->m_h_hemisphere, TRUE);
	}
	for (int r = 0; r < map->GetNumObject(SPRING); r++)
	{
		DrawExtendGraph(map->m_spring[r].GetPosX() - leftX,
			map->m_spring[r].GetPosY(),
			map->m_spring[r].GetPosX() + map->m_spring[r].GetSizeWidth() - leftX,
			map->m_spring[r].GetPosY() + map->m_spring[r].GetSizeHigh(),
			map->m_h_spring, TRUE);
	}
	for (int r = 0; r < map->GetNumObject(HOLE); r++)
	{
		DrawExtendGraph(map->m_hole[r].GetPosX() - leftX,
			map->m_hole[r].GetPosY(),
			map->m_hole[r].GetPosX() + map->m_hole[r].GetSizeWidth() - leftX,
			map->m_hole[r].GetPosY() + map->m_hole[r].GetSizeHigh(),
			map->m_h_hole, TRUE);
	}	
	for (int r = 0; r < map->GetNumObject(TRIANGLE); r++)
	{
		DrawExtendGraph(map->m_triangle[r].GetPosX() - leftX,
			map->m_triangle[r].GetPosY(),
			map->m_triangle[r].GetPosX() + map->m_triangle[r].GetSizeWidth() - leftX,
			map->m_triangle[r].GetPosY() + map->m_triangle[r].GetSizeHigh(),
			map->m_h_triangle, TRUE);
	}

}

void Scene_Game::backGroundDraw()
{
	DrawGraph(0-leftX, 0, background, FALSE);
	DrawGraph(500 - leftX, 0, background, FALSE);
	DrawGraph(0-leftX, 320, h_ground, false);
	DrawGraph(500 - leftX, 320, h_ground, false);
}