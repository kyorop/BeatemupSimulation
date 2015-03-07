#include "Map.h"

Map* Map::instance;

Map::Map()
{
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		m_numobjects[i] = 0;
	}
	SetTransColor(255, 255, 255); //白を透過するように
	m_h_square = LoadGraph("./img/square.png");
	m_h_hemisphere = LoadGraph("./img/hemisphere.png");
	m_h_hole = LoadGraph("./img/hole.png");
	m_h_spring = LoadGraph("./img/spring.png");
	m_h_triangle = LoadGraph("./img/triangle.png");
	nowchoose = -1;
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


void Map::CreateDraw()
{
	//各オブジェクトを描画する
	for (int i = 0; i < m_numobjects[SQUARE]; i++)
	{
		m_square[i].CreateDraw(m_h_square);
	}
	for (int i = 0; i < m_numobjects[HEMISPHERE]; i++)
	{
		m_hemisphere[i].CreateDraw(m_h_hemisphere);
	}
	for (int i = 0; i < m_numobjects[SPRING]; i++)
	{
		m_spring[i].CreateDraw(m_h_spring);
	}
	for (int i = 0; i < m_numobjects[HOLE]; i++)
	{
		m_hole[i].CreateDraw(m_h_hole);
	}
	for (int i = 0; i < m_numobjects[TRIANGLE]; i++)
	{
		m_triangle[i].CreateDraw(m_h_triangle);
	}
}


void Map::Draw()
{
	//各オブジェクトを描画する
	for (int i = 0; i < m_numobjects[SQUARE]; i++)
	{
		m_square[i].Draw(m_h_square);
	}
	for (int i = 0; i < m_numobjects[HEMISPHERE]; i++)
	{
		m_hemisphere[i].Draw(m_h_hemisphere);
	}
	for (int i = 0; i < m_numobjects[SPRING]; i++)
	{
		m_spring[i].Draw(m_h_spring);
	}
	for (int i = 0; i < m_numobjects[HOLE]; i++)
	{
		m_hole[i].Draw(m_h_hole);
	}
	for (int i = 0; i < m_numobjects[TRIANGLE]; i++)
	{
		m_triangle[i].Draw(m_h_triangle);
	}
}


int Map::CreateUpdate()
{
	int result = -1;
	static int mouse_x = 0, mouse_y = 0;
	static int last_mouse_x = 0, last_mouse_y = 0;
	if ((GetMouseInput() & MOUSE_INPUT_LEFT)) //マウスの左ボタンが押されているなら
	{
		if (!m_mouse_updown) //1回目の処理
		{
			//現在のマウスの位置を取得
			GetMousePoint(&mouse_x, &mouse_y);
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
			//どのオブジェクトが押されたか取得する
			for (int i = 0; i < m_numobjects[SQUARE]; i++)
			{
				if (m_square[i].CheckHitMouse(mouse_x, mouse_y))
				{
					nowchoose = i;
				}
			}
			for (int i = 0; i < m_numobjects[HEMISPHERE]; i++)
			{
				if (m_hemisphere[i].CheckHitMouse(mouse_x, mouse_y))
				{
					nowchoose = i + 10;
				}
			}
			for (int i = 0; i < m_numobjects[SPRING]; i++)
			{
				if(m_spring[i].CheckHitMouse(mouse_x, mouse_y))
				{
					nowchoose = i + 20;
				}
			}
			for (int i = 0; i < m_numobjects[HOLE]; i++)
			{
				if (m_hole[i].CheckHitMouse(mouse_x, mouse_y))
				{
					nowchoose = i + 30;
				}
			}
			for (int i = 0; i < m_numobjects[TRIANGLE]; i++)
			{
				if (m_triangle[i].CheckHitMouse(mouse_x, mouse_y))
				{
					nowchoose = i + 40;
				}
			}
			if (nowchoose != -1)
			{
				result = nowchoose;
			}
			m_mouse_updown = TRUE;
		}
		if (nowchoose != -1)
		{
			//現在のマウスの位置を取得
			GetMousePoint(&mouse_x, &mouse_y);
			switch (nowchoose / 10) //座標の更新
			{
			case SQUARE:
				m_square[nowchoose - (nowchoose / 10) * 10].SetDrawPosX(m_square[nowchoose - (nowchoose / 10) * 10].GetDrawPosX() + (mouse_x - last_mouse_x));
				m_square[nowchoose - (nowchoose / 10) * 10].SetDrawPosY(m_square[nowchoose - (nowchoose / 10) * 10].GetDrawPosY() + (mouse_y - last_mouse_y)); 
				break;
			case HEMISPHERE:
				m_hemisphere[nowchoose - (nowchoose / 10) * 10].SetDrawPosX(m_hemisphere[nowchoose - (nowchoose / 10) * 10].GetDrawPosX() + (mouse_x - last_mouse_x));
				m_hemisphere[nowchoose - (nowchoose / 10) * 10].SetDrawPosY(m_hemisphere[nowchoose - (nowchoose / 10) * 10].GetDrawPosY() + (mouse_y - last_mouse_y));
				break;
			case SPRING:
				m_spring[nowchoose - (nowchoose / 10) * 10].SetDrawPosX(m_spring[nowchoose - (nowchoose / 10) * 10].GetDrawPosX() + (mouse_x - last_mouse_x));
				m_spring[nowchoose - (nowchoose / 10) * 10].SetDrawPosY(m_spring[nowchoose - (nowchoose / 10) * 10].GetDrawPosY() + (mouse_y - last_mouse_y));
				break;
			case HOLE:
				m_hole[nowchoose - (nowchoose / 10) * 10].SetDrawPosX(m_hole[nowchoose - (nowchoose / 10) * 10].GetDrawPosX() + (mouse_x - last_mouse_x));
				m_hole[nowchoose - (nowchoose / 10) * 10].SetDrawPosY(m_hole[nowchoose - (nowchoose / 10) * 10].GetDrawPosY() + (mouse_y - last_mouse_y));
				break;
			case TRIANGLE:
				m_triangle[nowchoose - (nowchoose / 10) * 10].SetDrawPosX(m_triangle[nowchoose - (nowchoose / 10) * 10].GetDrawPosX() + (mouse_x - last_mouse_x));
				m_triangle[nowchoose - (nowchoose / 10) * 10].SetDrawPosY(m_triangle[nowchoose - (nowchoose / 10) * 10].GetDrawPosY() + (mouse_y - last_mouse_y));
				break;
			default:
				break;
			}
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
		}
	}
	else if (m_mouse_updown) //離された時の処理
	{
		SetDraggedObject(SQUARE, nowchoose - (nowchoose / 10) * 10);
		m_mouse_updown = FALSE;
		nowchoose = -1;
	}
	if (mouse_y < 308) //アイテムボックスの中でない
	{
		result = -1;
	}
	return result;
}


void Map::SetDraggedObject(KindObject type, int i)
{
	Object* object=nullptr;
	//	if (nanimonai)
	{
		switch (type)
		{
		case SQUARE:
			object = &m_square[i];
			break;
		case HEMISPHERE:
			object = &m_hemisphere[i];
			break;
		case SPRING: 
			object = &m_spring[i];
			break;
		case HOLE: 
			object = &m_hole[i];
			break;
		case TRIANGLE: 
			object = &m_triangle[i];
			break;
		default:
			break;
		}
		if (object != nullptr)
		{
			const int height = object->GetDrawSizeHigh();
			object->SetDrawPosY(small_stage_size_y - height);
		}
	}
	//	else
	{

	}

}