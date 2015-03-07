
//三角を表すクラス
#pragma once
#include "Object.h"
class Triangle :
	public Object
{
public:
	void Draw() override;
public:
	Triangle();
	~Triangle();
};