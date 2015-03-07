#include "SceneManger.h"
#include "Scene_Base.h"
#include "Scene_Start.h"
#include "Scene_Game.h"
#include "Scene_Mapcreate.h"
#include "Scene_Gameover.h"

SceneManger::SceneManger(void)
	:nextScene(NOCHANGE),
	scene(new Scene_Mapcreate)
{
	scene->SetManager(this);
	scene->Initialize();
}


SceneManger::~SceneManger(void)
{
	scene->Finalize();
	delete scene;
}


void SceneManger::Update(void)
{
	if(nextScene != NOCHANGE)
	{	
		scene->Finalize();		//次のシーンに変わる前に今のシーンの初期化
		delete scene;

		switch(nextScene)
		{
		case NOCHANGE: break;
		case SCENE_START:
			scene = new Scene_Start;
			break;
		case SCENE_MAPCREATE:
			scene = new Scene_Mapcreate;
			break;
		case SCENE_GAME: 
			scene = new Scene_Game;
			break;
		case SCENE_GOAL:
			break;
		case SCENE_GAMEOVER:
			scene = new Scene_Gameover;
			break;
		default: break;
		}

		nextScene = ISceneChanger::NOCHANGE;
		scene->Initialize();
		scene->SetManager(this);
	}

	scene->Update();
}


void SceneManger::Draw(void)
{
	scene->Draw();
}


void SceneManger::ChangeScene(SceneType next)
{
	nextScene = next;
}

void SceneManger::PlaySE(void)
{
	scene->PlaySE();
}
