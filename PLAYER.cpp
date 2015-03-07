#include "PLAYER.h"
#include"DxLib.h"

double PLAYER::GetPosX()
{
	return X;
}

double PLAYER::GetPosY()
{
	return Y;
}

int PLAYER::GetHeight()
{
	return HEIGHT;
}
int PLAYER::GetWidht()
{
	return WIDHT;
}

void PLAYER::PlayerIni()
{
	X = 50;	Y = 50;
	AddX = 2; AddY = 0; dropAddY=0.1;
	GraphNum = 1;
	GraphChangeTime_Max = 80;
	TimeMax = 20;
	Time = TimeMax;
	OnGround = false;
	GraphChangeTime_Now = GraphChangeTime_Max;
	LoadDivGraph("img/charchip.png", 3, 3, 1, 32, 48, Graph);
	GetGraphSize(Graph[0], &WIDHT, &HEIGHT);

}

void PLAYER::PlayerDraw()
{
	DrawGraph((int)X, (int)Y, Graph[GraphNum], TRUE);
}

void PLAYER::GraphNumChange()
{
	if (OnGround)
	{
		GraphChangeTime_Now--;
	}
	if (GraphChangeTime_Now > 40)
	{
		GraphNum = 0;
	}
	else
	{
		GraphNum = 2;
		if (GraphChangeTime_Now <= 0)
		{
			GraphChangeTime_Now = GraphChangeTime_Max;
		}
	}
}

void PLAYER::PlayerMove()
{
	X += AddX; Y += AddY;
	if (OnGround)
	{
		AddY -= 3;
	}
	else
	{
		AddY += dropAddY;
	}
	if (Y > 400 - HEIGHT)
	{
		OnGround = true;
		if (AddY <= 0)
		{
			AddY = 0;
		}
		Y = 400 - HEIGHT;
	}
	else
	{
		OnGround = false;
	}
}

