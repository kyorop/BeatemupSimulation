#include "Scene_Mapcreate.h"
#include <DxLib.h>
#include "Map.h"

void Scene_Mapcreate::UpdateScene()
{

	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_GAME);
	}

}

Scene_Mapcreate::Scene_Mapcreate()
{

	map = Map::GetInstance();
	//ここでswitch文で難易度設定
	//とりあえずNORMAL?
	numobjects_now[SQUARE] = numobjects[SQUARE] = 3;
	numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE] = 2;
	numobjects_now[SPRING] = numobjects[SPRING] = 0;
	numobjects_now[HOLE] = numobjects[HOLE] = 1;
	numobjects_now[TRIANGLE] = numobjects[TRIANGLE] = 3;
	object_size[SQUARE] = 64;
	object_size[HEMISPHERE] = 64;
	object_size[SPRING] = 64;
	object_size[HOLE] = 64;
	object_size[TRIANGLE] = 64;

	//まず初期設定
	for (int i = 0; i < numobjects[SQUARE]; i++)
	{
		map->MakeObject(SQUARE, 10, itempos_y_lu + 18, object_size[SQUARE], object_size[SQUARE]);
	}
	for (int i = 0; i < numobjects[HEMISPHERE]; i++)
	{
		map->MakeObject(HEMISPHERE, 10 + 640 / 5, itempos_y_lu + 18, object_size[HEMISPHERE], object_size[HEMISPHERE]);
	}
	for (int i = 0; i < numobjects[SPRING]; i++)
	{
		map->MakeObject(SPRING, 10 + (640 * 2) / 5, itempos_y_lu + 18, object_size[SPRING], object_size[SPRING]);
	}
	for (int i = 0; i < numobjects[HOLE]; i++)
	{
		map->MakeObject(HOLE, 10 + (640 * 3) / 5, itempos_y_lu + 18, object_size[HOLE], object_size[HOLE]);
	}
	for (int i = 0; i < numobjects[TRIANGLE]; i++)
	{
		map->MakeObject(TRIANGLE, 10 + (640 * 4) / 5, itempos_y_lu + 18, object_size[TRIANGLE], object_size[TRIANGLE]);
	}
	h_banner = LoadGraph("./img/cppbanner.png");
}

void Scene_Mapcreate::Update()
{
	UpdateScene();
	int result = 0;
	if ((result = map->CreateUpdate()) != -1)
	{
		if (result >= 0)
		{
			switch (result / 10)
			{
			case SQUARE:
				numobjects_now[SQUARE]--;
				map->m_square[result - (result / 10) * 10].ReminSize(stage_size_x, stage_size_y);
				break;
			case HEMISPHERE:
				numobjects_now[HEMISPHERE]--;
				map->m_hemisphere[result - (result / 10) * 10].ReminSize(stage_size_x, stage_size_y);
				break;
			case SPRING:
				numobjects_now[SPRING]--;
				map->m_spring[result - (result / 10) * 10].ReminSize(stage_size_x, stage_size_y);
				break;
			case HOLE:
				numobjects_now[HOLE]--;
				map->m_hole[result - (result / 10) * 10].ReminSize(stage_size_x, stage_size_y);
				break;
			case TRIANGLE:
				numobjects_now[TRIANGLE]--;
				map->m_triangle[result - (result / 10) * 10].ReminSize(stage_size_x, stage_size_y);
				break;
			}
		}
		else //アイテムボックスから出てない
		{
			switch ((result + 10) / (-100))
			{
			case SQUARE:
				numobjects_now[SQUARE]++;
				break;
			case HEMISPHERE:
				numobjects_now[HEMISPHERE]++;
				break;
			case SPRING:
				numobjects_now[SPRING]++;
				break;
			case HOLE:
				numobjects_now[HOLE]++;
				break;
			case TRIANGLE:
				numobjects_now[TRIANGLE]++;
				break;
			}
		}
	}
	
}

void Scene_Mapcreate::Draw()
{
	DrawBox(0, 0, 640, 480, GetColor(153, 76, 0),TRUE); //背景黒だと分かりにくいのでとりあえず
	DrawFormatString(0, 0, GetColor(255, 255, 255), "This scene is Mapcreate");
	DrawLine(0, itempos_y_lu, 640, itempos_y_lu + 2, GetColor(255, 0, 0), 4);
	map->CreateDraw();
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		if (numobjects_now[i])
		{
			DrawFormatString(90 + i * (640 / 5), itempos_y_lu + 50 - 6, GetColor(128, 0, 128), "×%d", numobjects_now[i]);
		}
	}
	DrawGraph(0, 480 - 80, h_banner, FALSE);
}


