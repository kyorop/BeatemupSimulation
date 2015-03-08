#include <DxLib.h>
#include "Scene_Start.h"

void Scene_Start::UpdateScene()
{
}

void Scene_Start::Update()
{
	int mousex = 0, mousey = 0;
	GetMousePoint(&mousex, &mousey);
	if (!startflag)
	{
		if (mousey >= 302)
		{
			nowchoose = 1;
		}
		else
		{
			nowchoose = 0;
		}
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			downmouse = TRUE;
		}
		else if (downmouse)
		{
			if (nowchoose)
			{
				exit(0); //ほんとは-1を返したい
			}
			else
			{
				startflag = TRUE;
				downmouse = FALSE;
			}
		}
	}
	else
	{
		if (mousey <= 278)
		{
			nowchoose = 0;
		}
		else if (mousey <= 302)
		{
			nowchoose = 1;
		}
		else if (mousey <= 326)
		{
			nowchoose = 2;
		}
		else if (mousey <= 350)
		{
			nowchoose = 3;
		}
		if (GetMouseInput() & MOUSE_INPUT_LEFT)
		{
			downmouse = TRUE;
		}
		else if (downmouse)
		{
			map->SetDifficulty(nowchoose); //難易度を記憶
			sceneMrg->ChangeScene(ISceneChanger::SCENE_MAPCREATE); //マップ作成を始める
		}
		
		if (GetMouseInput() & MOUSE_INPUT_RIGHT)
		{
			startflag = FALSE; //難易度選択をキャンセル
		}
	}
	UpdateScene();
}

void Scene_Start::Draw()
{
	DrawExtendGraph(0, 0, 640, 360, h_background, false);
	DrawExtendGraph(0, 360, 640, 480, h_ground, false);
	if (!startflag)
	{
		DrawFormatString(205 - (nowchoose ? 0 : 20), 278, GetColor(0, 0, 0), "Start");
		DrawFormatString(205 - (nowchoose ? 20 : 0), 302, GetColor(0, 0, 0), "Exit");
	}
	else
	{
		DrawFormatString(305 - (nowchoose == 0? 20 : 0), 254, GetColor(0, 0, 0), "Easy");
		DrawFormatString(305 - (nowchoose == 1? 20 : 0), 278, GetColor(0, 0, 0), "Normal");
		DrawFormatString(305 - (nowchoose == 2? 20 : 0), 302, GetColor(0, 0, 0), "Difficult");
		DrawFormatString(305 - (nowchoose == 3? 20 : 0), 326, GetColor(0, 0, 0), "Extra");
	}
}


Scene_Start::Scene_Start()
{
	h_background = LoadGraph("img/background.png");
	h_ground = LoadGraph("img/ground.png");
	nowchoose = 0;
	startflag = FALSE;
	map = Map::GetInstance();
	downmouse = FALSE;
}