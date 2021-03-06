
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
	void SetObject(int posx, int posy, int sizex = -1, int sizey = -1);

	//以下はMapCreateで使用
	virtual int GetDrawSizeWidth(){ return m_draw_size_x; } //オブジェクトの横のサイズを返す
	virtual int GetDrawSizeHigh(){ return m_draw_size_y; } //オブジェクトの縦のサイズを返す
	int GetDrawPosX(){ return m_draw_pos_x; } //オブジェクトの左上のX座標を返す
	int GetDrawPosY(){ return m_draw_pos_y; } //オブジェクトの左上のY座標を返す
	void SetDrawSizeWidth(int x){ m_draw_size_x = x; }
	void SetDrawSizeHigh(int y){ m_draw_size_y = y; }
	void SetDrawPosX(int x){ m_draw_pos_x = x; }
	void SetDrawPosY(int y){ m_draw_pos_y = y; }
	bool m_click_flag; //TRUEなら現在ドラッグ＆ドロップされてる
	void CreateDraw(int h_object);
	void Draw(int h_object);
	bool CheckHitMouse(int mouse_x, int mouse_y); //マウスとこのオブジェクトの位置が被っているかどうかを返す。被っているならTRUE
	bool IsSet(){ return isSet; };
	void PutOnGround(){ isSet = true; }
	void ButOnGround(){ isSet = FALSE; }
	void ResetDrawPos();
	void ReminSize(int size_x, int size_y); //DrawSizeの縮小。size_yは実際の全画面のxのサイズ
	void RemaxSize(); //DrawSizeの大きさと座標を元に戻す
//	virtual void Draw()=0;
protected:
	int m_pos_x; //オブジェクトの左上のx座標
	int m_pos_y;
	int m_size_x;
	int m_size_y; //オブジェクトの横の大きさ
	int m_draw_pos_x;
	int m_draw_pos_y;
	int m_draw_size_x; //マップ作製で描画する際の横の大きさ
	int m_draw_size_y; //マップ作製で描画する際の横の大きさ
	KindObject m_kindobject; //オブジェクトのタイプ
	bool isSet = false;

	//以下初期値を保存しておくための変数
	bool initialized;
	int initDrawX1;
	int initDrawY1;
	int initDrawWidth;
	int initDrawHeight;
protected:
	void SetKindObject(KindObject ko){ m_kindobject = ko; } //オブジェクトのタイプを代入
};

