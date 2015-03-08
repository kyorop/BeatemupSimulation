#include <DxLib.h>
#include "Scene_Start.h"

void Scene_Start::UpdateScene()
{
}

void Scene_Start::Update()
{
	int mousex = 0, mousey = 0;
	GetMousePoint(&mousex, &mousey);
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
		if (nowchoose)
		{
			exit(0); //ほんとは-1を返したい
		}
		else
		{
			sceneMrg->ChangeScene(ISceneChanger::SCENE_MAPCREATE);
		}
	}
	UpdateScene();
}

void Scene_Start::Draw()
{
	DrawExtendGraph(0, 0, 640, 360,h_background, false);
	DrawExtendGraph(0, 360, 640, 480, h_ground, false);
	DrawFormatString(205 - (nowchoose ? 0 : 20), 278, GetColor(0, 0, 0), "Start");
	DrawFormatString(205 - (nowchoose ? 20 : 0), 302, GetColor(0, 0, 0), "Exit");
}


Scene_Start::Scene_Start()
{
	h_background = LoadGraph("img/background.png");
	h_ground = LoadGraph("img/ground.png");
	nowchoose = 0;
}