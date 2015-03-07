#include "Object.h"


Object::Object()
{
	m_click_flag = FALSE;
}


Object::~Object()
{
}


void Object::SetObject(int posx, int posy, int sizex, int sizey)
{
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