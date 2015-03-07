#include "Map.h"

Map* Map::instance;

Map::Map()
{
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		m_numobjects[i] = 0;
	}
}


Map::~Map()
{
	//メモリの開放
	if (m_square != nullptr)
	{
		delete[] m_square;
	}
	if (m_hemisphere != nullptr)
	{
		delete[] m_hemisphere;
	}
	if (m_spring != nullptr)
	{
		delete[] m_spring;
	}
	if (m_hole != nullptr)
	{
		delete[] m_hole;
	}
	if (m_triangle != nullptr)
	{
		delete[] m_triangle;
	}
}


void Map::MakeObject(KindObject ko, int posx, int posy, int sizex, int sizey)
{
	int temp_num;
	//ReNewに渡すための一時的な変数
	Square temp_square;
	HemiSphere temp_hemisphere;
	Spring temp_spring;
	Hole temp_hole;
	Triangle temp_triangle;
	switch (ko)
	{
	case SQUARE:
		temp_num = m_numobjects[SQUARE]; //今いくつあるか取得し
		ReNew(m_square, temp_num, temp_num + 1, temp_square);
		m_square[temp_num].SetObject(posx, posy, sizex, sizey);
		m_numobjects[SQUARE]++;
		break;
	case HEMISPHERE:
		temp_num = m_numobjects[HEMISPHERE];
		ReNew(m_hemisphere, temp_num, temp_num + 1, temp_hemisphere);
		m_hemisphere[temp_num].SetObject(posx, posy, sizex, sizey);
		m_numobjects[HEMISPHERE]++;
		break;
	case SPRING:
		temp_num = m_numobjects[SPRING];
		ReNew(m_spring, temp_num, temp_num + 1, temp_spring);
		m_spring[temp_num].SetObject(posx, posy, sizex, sizey);
		m_numobjects[SPRING]++;
		break;
	case HOLE:
		temp_num = m_numobjects[HOLE];
		ReNew(m_hole, temp_num, temp_num + 1, temp_hole);
		m_hole[temp_num].SetObject(posx, posy, sizex, sizey);
		m_numobjects[HOLE]++;
		break;
	case TRIANGLE:
		temp_num = m_numobjects[TRIANGLE];
		ReNew(m_triangle, temp_num, temp_num + 1, temp_triangle);
		m_triangle[temp_num].SetObject(posx, posy, sizex, sizey);
		m_numobjects[TRIANGLE]++;
		break;
	}

}

void Map::Draw()
{
	for (int i = SQUARE; i <= TRIANGLE; i++)
	{
		for (int j = 0; j < m_numobjects[i]; j++)
		{
			switch (i)
			{
			case SQUARE:
				m_square[j].Draw();
				break;
			case HEMISPHERE:
				m_triangle[j].Draw();
				break;
			case SPRING:
				m_spring[j].Draw();
				break;
			case HOLE:
				m_hole[j].Draw();
				break;
			case TRIANGLE:
				m_triangle[j].Draw();
				break;
			}
		}
	}
}

template<typename tn, typename real_tn>void Map::ReNew(tn &target, int num, int renum, real_tn type)
{
	tn temp = new real_tn[renum]; //まず新しいメモリを確保
	for (int i = 0; i < num; i++)
	{
		temp[i] = target[i]; //記憶して
	}
	if (target != nullptr)
	{
		delete[] target; //開放
	}
	target = temp; //入れなおす
}