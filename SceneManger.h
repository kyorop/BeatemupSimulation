#pragma once
#include "ISceneChanger.h"

class Scene_Base;
class SceneManger
	:public ISceneChanger
{

private:
	SceneType nextScene;
	Scene_Base *scene;
public:
	SceneManger(void);
	~SceneManger(void);

	void Update(void);
	void Draw(void);
	void ChangeScene(SceneType nextScene) override;
	void PlaySE(void);
};

