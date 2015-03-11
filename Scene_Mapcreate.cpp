#include "Scene_Mapcreate.h"
#include <DxLib.h>
#include "Map.h"

void Scene_Mapcreate::UpdateScene()
{
	int mousex = 0, mousey = 0;
	if (finish_flag)
	{
		if (GetMouseInput()&MOUSE_INPUT_LEFT)
		{
			GetMousePoint(&mousex, &mousey);
		}
		if ((startButtonX <= mousex && startButtonX + startButtonWidth >= mousex) && 
			(startButtonY <= mousey && startButtonY + startButtonHeight >= mousey))
		{
			map->SetPosAll(); //位置を調整する
			sceneMrg->ChangeScene(ISceneChanger::SCENE_GAME); //ゲーム画面へ 
		}
		
	}
	
}


void Scene_Mapcreate::Initialize()
{

	map = Map::GetInstance();
	//ここでswitch文で難易度設定
	switch (map->GetDifficulty())
	{
	case 0:
		numobjects_now[SQUARE] = numobjects[SQUARE] = 1 + GetRand(1);
		numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE] = 1 + GetRand(1);
		numobjects_now[SPRING] = numobjects[SPRING] = 1 + GetRand(1);
		numobjects_now[HOLE] = numobjects[HOLE] = 0;
		numobjects_now[TRIANGLE] = numobjects[TRIANGLE] = 0;
		break;
	case 1:
		numobjects_now[SQUARE] = numobjects[SQUARE] = 1 + GetRand(2);
		numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE] = 1 + GetRand(2);
		numobjects_now[SPRING] = numobjects[SPRING] = 1 + GetRand(2);
		numobjects_now[HOLE] = numobjects[HOLE] = 1 + GetRand(1);
		numobjects_now[TRIANGLE] = numobjects[TRIANGLE] = 1 + GetRand(1);
		break;
	case 2:
		numobjects_now[SQUARE] = numobjects[SQUARE] = 2 + GetRand(3);
		numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE] = 2 + GetRand(1);
		numobjects_now[SPRING] = numobjects[SPRING] = GetRand(3);
		numobjects_now[HOLE] = numobjects[HOLE] = 2 + GetRand(2);
		numobjects_now[TRIANGLE] = numobjects[TRIANGLE] = 2 + GetRand(2);
		break;
	case 3:
		numobjects_now[SQUARE] = numobjects[SQUARE] = 2 + GetRand(2);
		numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE] = 2 + GetRand(2);
		numobjects_now[SPRING] = numobjects[SPRING] = 1;
		numobjects_now[HOLE] = numobjects[HOLE] = 4 + GetRand(1);
		numobjects_now[TRIANGLE] = numobjects[TRIANGLE] = 4 + GetRand(1);
		break;
	default:
		break;
	}
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
		map->MakeObject(HEMISPHERE, 10 + 640 / 5, itempos_y_lu + 18, object_size[HEMISPHERE], object_size[HEMISPHERE] / 2);
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
	finish_flag = FALSE;
	reset_flag = FALSE;
}

Scene_Mapcreate::Scene_Mapcreate()
{
	h_banner = LoadGraph("./img/cppbanner.png");
	h_itemBox = LoadGraph("img/itembox.png");
	h_startButton = LoadGraph("img/startbutton.png");
	h_background = LoadGraph("img/background.png");
	h_ground = LoadGraph("img/ground.png");
	h_reset = LoadGraph("./img/resetbutton.png");
}

void Scene_Mapcreate::Update()
{
	UpdateScene();
	int result = 0;
	int mousex = 0, mousey = 0;
	if (numobjects_now[SQUARE] || numobjects_now[HEMISPHERE] || numobjects_now[SPRING] || numobjects_now[HOLE] || numobjects_now[TRIANGLE] || finish_flag ||map->m_mouse_updown)
	{
	}
	else //全部のオブジェクトの残りが0になって、マウスが押されていない(つまり処理が終わった)時
	{
		finish_flag = TRUE;
	}

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

	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		GetMousePoint(&mousex, &mousey);
	}
	if ((574 <= mousex && 638 >= mousex) &&
		(240 <= mousey && 263 >= mousey) && !reset_flag)
	{
		//各オブジェクトを元に戻す
		for (int i = 0; i < numobjects[SQUARE]; i++)
		{
			map->m_square[i].RemaxSize();
			map->m_square[i].ButOnGround();
		}
		numobjects_now[SQUARE] = numobjects[SQUARE];
		for (int i = 0; i < numobjects[HEMISPHERE]; i++)
		{
			map->m_hemisphere[i].RemaxSize(); 
			map->m_hemisphere[i].ButOnGround();
		}
		numobjects_now[HEMISPHERE] = numobjects[HEMISPHERE];
		for (int i = 0; i < numobjects[SPRING]; i++)
		{
			map->m_spring[i].RemaxSize();
			map->m_spring[i].ButOnGround();
		}
		numobjects_now[SPRING] = numobjects[SPRING];
		for (int i = 0; i < numobjects[HOLE]; i++)
		{
			map->m_hole[i].RemaxSize();
			map->m_hole[i].ButOnGround();
		}
		numobjects_now[HOLE] = numobjects[HOLE];
		for (int i = 0; i < numobjects[TRIANGLE]; i++)
		{
			map->m_triangle[i].RemaxSize();
			map->m_triangle[i].ButOnGround();
		}
		numobjects_now[TRIANGLE] = numobjects[TRIANGLE];
		reset_flag = TRUE;
	}
	else if (reset_flag && !(GetMouseInput()&MOUSE_INPUT_LEFT))
	{
		reset_flag = FALSE;
	}
	
}

void Scene_Mapcreate::Draw()
{
//	DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), TRUE); //背景黒だと分かりにくいのでとりあえず
	DrawExtendGraph(0, 0, 640, Map::small_stage_size_y, h_background, false);
//	DrawBox(0, Map::small_stage_size_y, 640, itempos_y_lu, GetColor(153, 76, 0), true);
	DrawExtendGraph(0, Map::small_stage_size_y, 640, itempos_y_lu, h_ground, false);
	DrawGraph(0, itempos_y_lu, h_itemBox, true);

	map->CreateDraw();
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		if (numobjects_now[i])
		{
			DrawFormatString(90 + i * (640 / 5), itempos_y_lu + 50 - 6, GetColor(128, 0, 128), "×%d", numobjects_now[i]);
		}
	}
	DrawGraph(0, 480 - 80, h_banner, FALSE);
	if (finish_flag)
	{
//		DrawFormatString(40, 320, GetColor(128, 0, 128), "Please, Enter!");
		DrawGraph(startButtonX, startButtonY, h_startButton, false);
	}
	DrawExtendGraph(574, 240, 636, 263, h_reset, false); //リセットボタンの表示
}


