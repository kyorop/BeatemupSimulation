
//半円を表すクラス
#pragma once
#include "Object.h"
class HemiSphere :
	public Object
{
public:
	int GetDrawSizeHigh() override;
public:
	HemiSphere();
	~HemiSphere();
};

