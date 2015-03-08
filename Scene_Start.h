#pragma once
#include "Scene_Base.h"
#include"Map.h"
class Scene_Start
	: public Scene_Base
{
	void UpdateScene() override;
public:
	void Update() override;
	void Draw() override;
	Scene_Start();
private:
	int h_background;
	int h_ground;
	int nowchoose; //0…Start、1…Exit
	int h_title;
	bool startflag; //startが押されたフラグ
	bool downmouse; //マウスが押されているフラグ
	Map* map;
};
