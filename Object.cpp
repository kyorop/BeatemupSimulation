#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}


void Object::SetObject(int posx, int posy, int sizex, int sizey)
{
	m_pos_x = posx;
	m_pos_y = posy;
	m_size_x = sizex;
	m_size_y = sizey;
}