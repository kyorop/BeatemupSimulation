#pragma once
#include "Scene_Base.h"
#include"Map.h"

class Scene_Mapcreate
	:public Scene_Base
{
	const int itempos_y_lu = 300;

	Map* map;

	void UpdateScene() override;
public:
	Scene_Mapcreate();
	void Update() override;
	void Draw() override;
	void Initialize() override;
private:
	int numobjects[TRIANGLE + 1];
	int numobjects_now[TRIANGLE + 1]; //各オブジェクトの残り
	int object_size[TRIANGLE + 1]; //各オブジェクトの1辺の大きさ
	int h_banner;
	int h_itemBox;
	int h_startButton;
	int h_background;
	int h_ground;
	int h_reset;
	const int stage_size_x = 1000, stage_size_y = 480; //ステージのサイズ
	const int startButtonX = 320-176/2;
	const int startButtonY = 350-51/2;
	const int startButtonWidth = 176; 
	const int startButtonHeight = 51;
	bool finish_flag; //オブジェクトを置き終わったフラグ
	bool reset_flag; //リセットしたことを表すフラグ
	int temp_num[5];
};
