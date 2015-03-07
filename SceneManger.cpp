#include "SceneManger.h"
#include "Scene_Base.h"
#include "Scene_Start.h"
#include "Scene_Game.h"
#include "Scene_Mapcreate.h"

SceneManger::SceneManger(void)
	:nextScene(NOCHANGE),
	scene(new Scene_Start)
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
		scene->Finalize();		//���̃V�[���ɕς��O�ɍ��̃V�[���̏�����
		delete scene;

		switch(nextScene)
		{
		case ISceneChanger::SCENE_GAME:
			scene  = new Scene_Game;
			break;
		case ISceneChanger::SCENE_MAPCREATE:
			scene = new Scene_Mapcreate;
			break;
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


void SceneManger::ChangeScene(int next)
{
	nextScene = next;
}

void SceneManger::PlaySE(void)
{
	scene->PlaySE();
}