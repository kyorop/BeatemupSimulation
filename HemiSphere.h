
//半円を表すクラス
#pragma once
#include "Object.h"
class HemiSphere :
	public Object
{
public:
	void Draw() override;
public:
	HemiSphere();
	~HemiSphere();
};

