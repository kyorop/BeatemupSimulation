
//ジャンプ台用のクラス
#pragma once
#include "Object.h"
class Spring :
	public Object
{
public:
	void Draw() override;
public:
	Spring();
	~Spring();
};

