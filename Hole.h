
//落とし穴を表すクラス
#pragma once
#include "Object.h"
class Hole :
	public Object
{
public:
	void Draw() override;
public:
	Hole();
	~Hole();
};

