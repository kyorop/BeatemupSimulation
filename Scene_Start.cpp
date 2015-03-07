#include <DxLib.h>
#include "Scene_Start.h"

void Scene_Start::UpdateScene()
{
	if (CheckHitKey(KEY_INPUT_RETURN))
	{
		sceneMrg->ChangeScene(ISceneChanger::SCENE_MAPCREATE);
	}
}

void Scene_Start::Update()
{
	UpdateScene();
}

void Scene_Start::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "PUsh enter");
}