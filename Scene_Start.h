#pragma once
#include "Scene_Base.h"

class Scene_Start
	: public Scene_Base
{
	void UpdateScene() override;
public:
	void Update() override;
	void Draw() override;
	Scene_Start();
private:
	int h_title; //タイトル画像のハンドル
	int nowchoose; //0…Start、1…Exit
};
