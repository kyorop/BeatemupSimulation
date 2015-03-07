#include "Object.h"


Object::Object()
{
	m_click_flag = FALSE;
	isSet = false;
	initialized = false;
}


Object::~Object()
{
}


void Object::SetObject(int posx, int posy, int sizex, int sizey)
{
	if (!initialized)
	{
		initDrawX1 = posx;
		initDrawY1 = posy;
		initDrawWidth = sizex;
		initDrawHeight = sizey;

		initialized = true;
	}
	m_draw_pos_x = m_pos_x = posx;
	m_draw_pos_y = m_pos_y = posy;
	m_draw_size_x = m_size_x = sizex;
	m_draw_size_y = m_size_y = sizey;
}


void Object::CreateDraw(int h_object)
{
	DrawExtendGraph(m_draw_pos_x, m_draw_pos_y,
		m_draw_pos_x + m_draw_size_x, m_draw_pos_y + m_draw_size_y, h_object, true);
}


void Object::Draw(int h_object)
{
	DrawExtendGraph(m_pos_x, m_pos_y,
		m_pos_x + m_size_x, m_pos_y + m_size_y, h_object, true);
}


bool Object::CheckHitMouse(int mouse_x, int mouse_y)
{
	if ((m_draw_pos_x <= mouse_x && m_draw_pos_x + m_draw_size_x >= mouse_x) &&
		(m_draw_pos_y <= mouse_y && m_draw_pos_y + m_draw_size_y >= mouse_y))
	{
		return TRUE;
	}
	return FALSE;
}

void Object::ResetDrawPos()
{
	if (initialized)
	{
		m_draw_pos_x = initDrawX1;
		m_draw_pos_y = initDrawY1;
		m_draw_size_x = m_size_x = initDrawWidth;
		m_draw_size_y = m_size_y = initDrawHeight;
	}
}


void Object::ReminSize(int size_x, int size_y)
{
	//ÇøÇ¢Ç≥Ç≠Ç»ÇÈ
	SetDrawSizeWidth(m_draw_size_x * 640 / size_x);
	SetDrawSizeHigh(m_draw_size_y * 300 / size_y);
}


void Object::RemaxSize()
{
	//å≥ÇÃç¿ïWÇ…ñﬂÇ∑
	SetDrawPosX(m_pos_x);
	SetDrawPosY(m_pos_y);
	//å≥ÇÃëÂÇ´Ç≥Ç…ñﬂÇ∑
	SetDrawSizeWidth(m_size_x);
	SetDrawSizeHigh(m_size_y);
}
