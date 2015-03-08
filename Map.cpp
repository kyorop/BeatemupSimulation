#include "Map.h"
#include "CollisionHelper.h"
#include <cmath>
Map* Map::instance;

Map::Map()
{
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		m_numobjects[i] = 0;
	}
	SetTransColor(255, 255, 255); //白を透過するように
	m_h_square = LoadGraph("./img/square.png");
	m_h_hemisphere = LoadGraph("./img/hemisphere2.png");
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

		//既に設置されたオブジェクトはもう動かないようにする
		if (GetObj(static_cast<KindObject>(nowchoose / 10), nowchoose % 10) != nullptr && GetObj(static_cast<KindObject>(nowchoose / 10), nowchoose % 10)->IsSet())
		{
			nowchoose = -1;
			result = -1;
		}
		
		if (nowchoose != -1)
		{
			Object* object = GetObj(static_cast<KindObject>(nowchoose / 10), nowchoose - (nowchoose / 10) * 10);
			if (object == nullptr)
				return result;
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
		m_mouse_updown = FALSE;
		if (nowchoose != -1) //オブジェクトが選択されてた場合だけ処理する
		{
			const KindObject droppedType = static_cast<KindObject>(nowchoose / 10);
			const int droppedI = nowchoose - (nowchoose / 10) * 10;
			Object* object = GetObj(droppedType, droppedI);
			if (mouse_y < small_stage_size_y && SetDraggedObject(droppedType, droppedI)) //アイテムボックスの中でないかつ何かと被さってない
			{
				result = -1;
			}
			else
			{
				switch (nowchoose / 10) //座標を戻す
				{
				case SQUARE:
					m_square[nowchoose - (nowchoose / 10) * 10].RemaxSize();
					break;
				case HEMISPHERE:
					m_hemisphere[nowchoose - (nowchoose / 10) * 10].RemaxSize();
					break;
				case SPRING:
					m_spring[nowchoose - (nowchoose / 10) * 10].RemaxSize();
					break;
				case HOLE:
					m_hole[nowchoose - (nowchoose / 10) * 10].RemaxSize();
					break;
				case TRIANGLE:
					m_triangle[nowchoose - (nowchoose / 10) * 10].RemaxSize();
					break;
				default:
					break;
				}

				result = nowchoose * (-10) - 10; //特殊な処理
			}
			nowchoose = -1;
		}
	}
	return result;
}


bool Map::SetDraggedObject(KindObject type, int i)
{
	const int x1 = GetObj(type, i)->GetDrawPosX();
	const int x2 = x1 + GetObj(type, i)->GetDrawSizeWidth();
	const int lowerY = GetObj(type, i)->GetDrawPosY() + GetObj(type, i)->GetDrawSizeHigh();
	int highestY;
	Object* highestObj = nullptr;
	GetHighestY(x1, x2, &highestY, &highestObj);
	Object* object = GetObj(type, i);
	if (object == nullptr)
		return FALSE;

	if (lowerY > small_stage_size_y)
	{
		return FALSE;
	}

	if(highestY == small_stage_size_y)//下に何もオブジェクトが無い時
	{
		const int height = object->GetDrawSizeHigh();
		object->SetDrawPosY(small_stage_size_y - height);
		object->PutOnGround();
	}
	else if (lowerY <= highestY)//下にオブジェクトがあるとき
	{
		//落とし穴は重なってたら無条件で、リセット
		if (type == HOLE)
		{
			object->ResetDrawPos();
			return FALSE;
		}

		//落とし穴の上に置こうとしたらリセット
		if (highestObj->GetObjectType() == HOLE || highestObj->GetObjectType() == SPRING)
		{
			object->ResetDrawPos();
			return false;
		}

		if (highestObj->GetObjectType() == TRIANGLE)
		{
			const double hh = highestObj->GetDrawSizeHigh();
			const double hw = highestObj->GetDrawSizeWidth();
			const double hx = highestObj->GetDrawPosX();
			const double hy = highestObj->GetDrawPosY();
			const double hcx = hx + hw / 2;
			const double dx = x1;
			const double dx2 = x2;
			double a;
			const double b = hw/2;
			int hDash;
			if (dx2 < hcx)
			{
				a = dx2 - hx;
				hDash = hh*(a / b);
				highestY = hy + (hh - hDash);
			}
			else if (hcx < dx)
			{
				a = (hx + hw) - dx;
				hDash = hh*(a / b);
				highestY = hy + (hh - hDash);
			}
		}
		else if (highestObj->GetObjectType() == HEMISPHERE)
		{
			const double hh = highestObj->GetDrawSizeHigh();
			const double hw = highestObj->GetDrawSizeWidth();
			const double hx = highestObj->GetDrawPosX();
			const double hy = highestObj->GetDrawPosY();
			const double hcx = hx + hw / 2;
			const double dx = x1;
			const double dx2 = x2;
			double theta;
			double a;
			const double b = hw / 2;
			int hDash;
			if (dx2 < hcx)
			{
				a = hcx - dx2;
				theta = acos(a / b);
				hDash = b*cos(theta);
				highestY = hy + (hh - hDash);
			}
			else if (hcx < dx)
			{
				a = dx - hcx;
				theta = acos(a / b);
				hDash = b*cos(theta);
				highestY = hy + (hh - hDash);
			}
		}

		const int height = object->GetDrawSizeHigh();
		object->SetDrawPosY(highestY - height);
		object->PutOnGround();
	}
	else//すでにあるオブジェクトより下にドロップした時
	{
		object->ResetDrawPos();
		return FALSE;
	}
	return TRUE;
}

void Map::GetHighestY(int x1, int x2, int* highest, Object** highestObject)
{
	int highestY=small_stage_size_y;

	for (int type = SQUARE; type <= TRIANGLE; type++)
	{
		for (int i = 0; i < m_numobjects[type]; i++)
		{
			if (GetObj(static_cast<KindObject>(type), i)->IsSet())
			{
				Object* object = GetObj(static_cast<KindObject>(type), i);
				const int doneX1 = object->GetDrawPosX();
				const int doneX2 = doneX1 + object->GetDrawSizeWidth();
				const int doneUpperY = object->GetDrawPosY();
				if (CheckHitLine(x1, x2, doneX1, doneX2))
				{
					if (highestY > doneUpperY)
					{
						highestY = doneUpperY;
						*highestObject = object;
					}
				}
			}
		}
	}

	*highest = highestY;
}

Object* Map::GetObj(KindObject type, const int i)
{
	switch (type)
	{
	case SQUARE: 
		return &m_square[i];
	case HEMISPHERE: 
		return &m_hemisphere[i];
	case SPRING: 
		return &m_spring[i];
	case HOLE:
		return &m_hole[i];
	case TRIANGLE: 
		return &m_triangle[i];
	default: 
		return nullptr;
	}
}


void Map::SetPosAll()
{
	//全てのオブジェクトの位置調整
	for (int i = 0; i < m_numobjects[SQUARE]; i++)
	{
		m_square[i].SetObject(m_square[i].GetDrawPosX() * stage_size_x / 640, m_square[i].GetDrawPosY() *stage_size_y / 300);
	}
	for (int i = 0; i < m_numobjects[HEMISPHERE]; i++)
	{
		m_hemisphere[i].SetObject(m_hemisphere[i].GetDrawPosX() * stage_size_x / 640, m_hemisphere[i].GetDrawPosY() *stage_size_y / 300);
	}
	for (int i = 0; i < m_numobjects[SPRING]; i++)
	{
		m_spring[i].SetObject(m_spring[i].GetDrawPosX() * stage_size_x / 640, m_spring[i].GetDrawPosY() *stage_size_y / 300);
	}
	for (int i = 0; i < m_numobjects[HOLE]; i++)
	{
		m_hole[i].SetObject(m_hole[i].GetDrawPosX() * stage_size_x / 640, m_hole[i].GetDrawPosY() *stage_size_y / 300);
	}
	for (int i = 0; i < m_numobjects[TRIANGLE]; i++)
	{
		m_triangle[i].SetObject(m_triangle[i].GetDrawPosX() * stage_size_x / 640, m_triangle[i].GetDrawPosY() *stage_size_y / 300);
	}
}