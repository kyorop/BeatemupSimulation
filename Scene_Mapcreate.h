#pragma once
#include "Scene_Base.h"
#include"Map.h"

class Scene_Mapcreate
	:public Scene_Base
{
	const int itempos_y_lu = 308;

	Map* map;

	void UpdateScene() override;
public:
	Scene_Mapcreate();
	void Update() override;
	void Draw() override;
private:
	int numobjects[TRIANGLE + 1];
	int numobjects_now[TRIANGLE + 1]; //各オブジェクトの残り
	int object_size[TRIANGLE + 1]; //各オブジェクトの1辺の大きさ

	void SetDraggedObject(KindObject type, int index, int x, int y);
};
