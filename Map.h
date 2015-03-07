
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
private:
	int m_numobjects[TRIANGLE + 1]; //各オブジェクトがいくつあるか。必ずTRIANGLEを最後に
	// 生成やコピーを禁止する
	Map();
	~Map();
	Map(const Map& rhs);
	Map& operator=(const Map& rhs);
};

