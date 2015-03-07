#pragma once

class Scene_Base;
class ISceneChanger
{
public:
	enum
	{
		NOCHANGE,
		SCENE_START,
		SCENE_MAPCREATE,
		SCENE_GAME,
		SCENE_GOAL,
		SCENE_GAMEOVER,
	};

public:
	virtual ~ISceneChanger(void){};
	virtual void ChangeScene(int nextScene) = 0;
};

