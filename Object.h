
//各オブジェクトに継承するためのクラス
#pragma once
#include "Object_Interface.h"
class Object :
	public Object_Interface
{
public:
	Object();
	~Object();
	int GetSizeWidth(){ return m_size_x; } //オブジェクトの横のサイズを返す
	int GetSizeHigh(){ return m_size_y; } //オブジェクトの縦のサイズを返す
	int GetPosX(){ return m_pos_x; } //オブジェクトの左上のX座標を返す
	int GetPosY(){ return m_pos_y; } //オブジェクトの左上のY座標を返す
	KindObject GetObjectType(){ return m_kindobject; } //オブジェクトのタイプを返す
	void SetObject(int posx, int posy, int sizex, int sizey);

//	virtual void Draw()=0;
private:
	int m_pos_x; //オブジェクトの左上のx座標
	int m_pos_y;
	int m_size_x;
	int m_size_y; //オブジェクトの横の大きさ
	KindObject m_kindobject; //オブジェクトのタイプ
protected:
	void SetKindObject(KindObject ko){ m_kindobject = ko; } //オブジェクトのタイプを代入
};

