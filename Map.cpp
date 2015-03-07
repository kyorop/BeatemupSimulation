#include "Map.h"
#include "CollisionHelper.h"

Map* Map::instance;

Map::Map()
{
	for (int i = 0; i < TRIANGLE + 1; i++)
	{
		m_numobjects[i] = 0;
	}
	SetTransColor(255, 255, 255); //���𓧉߂���悤��
	m_h_square = LoadGraph("./img/square.png");
	m_h_hemisphere = LoadGraph("./img/hemisphere.png");
	m_h_hole = LoadGraph("./img/hole.png");
	m_h_spring = LoadGraph("./img/spring.png");
	m_h_triangle = LoadGraph("./img/triangle.png");
	nowchoose = -1;
}


Map::~Map()
{
	//�������̊J��
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
	//ReNew�ɓn�����߂̈ꎞ�I�ȕϐ�
	Square temp_square;
	HemiSphere temp_hemisphere;
	Spring temp_spring;
	Hole temp_hole;
	Triangle temp_triangle;
	switch (ko)
	{
	case SQUARE:
		temp_num = m_numobjects[SQUARE]; //���������邩�擾��
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
	tn temp = new real_tn[renum]; //�܂��V�������������m��
	for (int i = 0; i < num; i++)
	{
		temp[i] = target[i]; //�L������
	}
	if (target != nullptr)
	{
		delete[] target; //�J��
	}
	target = temp; //����Ȃ���
}


void Map::CreateDraw()
{
	//�e�I�u�W�F�N�g��`�悷��
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
	//�e�I�u�W�F�N�g��`�悷��
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
	if ((GetMouseInput() & MOUSE_INPUT_LEFT)) //�}�E�X�̍��{�^����������Ă���Ȃ�
	{
		if (!m_mouse_updown) //1��ڂ̏���
		{
			//���݂̃}�E�X�̈ʒu���擾
			GetMousePoint(&mouse_x, &mouse_y);
			last_mouse_x = mouse_x;
			last_mouse_y = mouse_y;
			//�ǂ̃I�u�W�F�N�g�������ꂽ���擾����
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
			//���݂̃}�E�X�̈ʒu���擾
			GetMousePoint(&mouse_x, &mouse_y);
			switch (nowchoose / 10) //���W�̍X�V
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
	else if (m_mouse_updown) //�����ꂽ���̏���
	{
		const KindObject droppedType = static_cast<KindObject>(nowchoose / 10);
		const int droppedI = nowchoose - (nowchoose / 10) * 10;
		SetDraggedObject(droppedType, droppedI);
		GetObj(droppedType, droppedI)->PutOnGround();
		m_mouse_updown = FALSE;
		nowchoose = -1;
	}
	if (mouse_y < small_stage_size_y) //�A�C�e���{�b�N�X�̒��łȂ�
	{
		result = -1;
	}
	return result;
}


void Map::SetDraggedObject(KindObject type, int i)
{
	const int x1 = GetObj(type, i)->GetDrawPosX();
	const int x2 = x1 + GetObj(type, i)->GetDrawSizeWidth();
	const int lowerY = GetObj(type, i)->GetDrawPosY() + GetObj(type, i)->GetDrawSizeHigh();
	const int highestY = GetHighestY(x1, x2, lowerY);
	Object* object = nullptr;

	if (highestY == small_stage_size_y)
	{
		object = GetObj(type, i); 
		if (object != nullptr)
		{
			const int height = object->GetDrawSizeHigh();
			object->SetDrawPosY(small_stage_size_y - height);
		}
	}
	else if (lowerY <= highestY)
	{
		object = GetObj(type, i);
		if (object != nullptr)
		{
			const int height = object->GetDrawSizeHigh();
			object->SetDrawPosY(highestY - height);
			object->PutOnGround();
		}
	}
	else
	{
		object = GetObj(type, i);
		if (object != nullptr)
		{
			object->ResetDrawPos();
		}
	}
}

int Map::GetHighestY(int x1, int x2, int lowerY)
{
	int highestY=small_stage_size_y;

	for (int i = 0; i < m_numobjects[SQUARE]; i++)
	{
		if (m_square[i].IsSet())
		{
			const int doneX1 = m_square[i].GetDrawPosX();
			const int doneX2 = doneX1 + m_square[i].GetDrawSizeWidth();
			const int doneUpperY = m_square[i].GetDrawPosY();
			if (CheckHitLine(x1, x2, doneX1, doneX2))
			{
				if (highestY > doneUpperY)
					highestY = doneUpperY;
			}
		}
	}
	for (int i = 0; i < m_numobjects[HEMISPHERE]; i++)
	{
	}
	for (int i = 0; i < m_numobjects[SPRING]; i++)
	{
	}
	for (int i = 0; i < m_numobjects[HOLE]; i++)
	{
	}
	for (int i = 0; i < m_numobjects[TRIANGLE]; i++)
	{
	}

	return highestY;
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