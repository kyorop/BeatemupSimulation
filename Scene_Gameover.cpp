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
	h_title = LoadGraph("./img/go_title.png");
	mouse_down = FALSE;
	map = Map::GetInstance();
	map -> DeleteObject();
}

void Scene_Gameover::Update()
{
	int mousex = 0, mousey = 0;
	if (GetMouseInput() & MOUSE_INPUT_LEFT)
	{
		mouse_down = TRUE;
	}
	else if (mouse_down)
	{
		GetMousePoint(&mousex, &mousey);
		if ((230 <= mousex && 410 >= mousex) && (260 <= mousey && 312 >= mousey))
		{
			sceneMrg->ChangeScene(ISceneChanger::SCENE_START); //タイトル画面へ 
		}
	}
}

void Scene_Gameover::Draw()
{
	DrawExtendGraph(0, 0, 640, 360, h_background, false);
	DrawExtendGraph(0, 360, 640, 480, h_ground, false);
	DrawGraph(gameoverX, gameoverY, h_gameover, true);
	DrawGraph(230, 260, h_title, FALSE);
}