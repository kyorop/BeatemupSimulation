#include "CollisionHelper.h"


bool CheckHitLine(int obj1x1, int obj1x2, int obj2x1, int obj2x2)
{
	if (obj1x2 > obj2x1 && obj2x2 > obj1x1)
		return true;
	else
		return false;
}