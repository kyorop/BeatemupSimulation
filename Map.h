
//各オブジェクトの数などの情報を持つマスタークラス
#pragma once
#include"Square.h"
#include"Triangle.h"
#include"HemiSphere.h"
#include"Spring.h"
#include"Hole.h"

class Map
{
public:
	static Map* instance;
	static Map* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Map;
		}
		return instance;
	}
	int GetNumObject(KindObject ko){ return m_numobjects[ko]; } //指定した種類のオブジェクトがいくつあるか返す
	Square* m_square; //Squareオブジェクトの配列
	Triangle* m_triangle;
	HemiSphere* m_hemisphere;
	Spring* m_spring;
	Hole* m_hole;
	void MakeObject(KindObject ko, int posx, int posy, int sizex, int sizey); //ko型のオブジェクトを追加する
	void CreateDraw(); //MapCreate内でのDraw
	void Draw(); //実行時のDraw
	int CreateUpdate(); //MapCreate内でのUpadate
private:
	int m_numobjects[TRIANGLE + 1]; //各オブジェクトがいくつあるか。必ずTRIANGLEを最後に
	const int stage_size_x = 1000 , stage_size_y = 480; //ステージのサイズ
	template<typename tn, typename real_tn>void ReNew(tn &target, int num, int renum, real_tn type); //targetが指す配列をrenum個に拡張する

	int m_h_square;
	int m_h_triangle;
	int m_h_hemisphere;
	int m_h_hole;
	int m_h_spring;
	bool m_mouse_updown; //マウスを押し始めたかどうか。TRUEならすでに押し始めている
	char nowchoose; //現在マウスに選ばれているオブジェクトを記憶。具体的には16なら2種類目の7番目、31なら3種類目の2番目
	// 生成やコピーを禁止する
	Map();
	~Map();
	Map(const Map& rhs);
	Map& operator=(const Map& rhs);
};