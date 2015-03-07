
//四角形を表すクラス
#pragma once
#include "Object.h"

class Square :
	public Object
{
public:
	void Draw() override;
public:
	Square();
	~Square();
};

