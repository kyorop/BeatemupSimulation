#include <DxLib.h>
#include "Scene_Start.h"

void Scene_Start::UpdateScene()
{
	/*if (CheckHitKey(KEY_INPUT_RETURN))
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_MAPCREATE);
	}*/
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
	DrawGraph(0, 0, h_title, FALSE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Push enter");


	DrawFormatString(205 - (nowchoose ? 0 : 20), 278, GetColor(0, 0, 0), "Start");
	DrawFormatString(205 - (nowchoose ? 20 : 0), 302, GetColor(0, 0, 0), "Exit");
}


Scene_Start::Scene_Start()
{
	h_title = LoadGraph("./img/title.png");
	nowchoose = 0;
}