#include "HemiSphere.h"

int HemiSphere::GetDrawSizeHigh()
{
	return m_draw_size_y / 2;
}

HemiSphere::HemiSphere()
{
	SetKindObject(HEMISPHERE);
}


HemiSphere::~HemiSphere()
{
}
