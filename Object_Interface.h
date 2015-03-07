//外部から参照する関数群
#pragma once
#include"DxLib.h"

enum KindObject {SQUARE, HEMISPHERE, SPRING, HOLE, TRIANGLE}; //オブジェクトの種類を示す
//左から順に四角、半円、ジャンプ台、落とし穴、三角

class Object_Interface
{
public:
	Object_Interface();
	~Object_Interface();
	virtual int GetSizeWidth() = 0; //オブジェクトの横のサイズを返す
	virtual int GetSizeHigh() = 0; //オブジェクトの縦のサイズを返す
	virtual int GetPosX() = 0; //オブジェクトの左上のX座標を返す
	virtual int GetPosY() = 0; //オブジェクトの左上のY座標を返す
	virtual KindObject GetObjectType() = 0; //オブジェクトのタイプを返す
};

