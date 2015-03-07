#include "PLAYER.h"
#include"DxLib.h"

void PLAYER::RenewPlayersPoint()
{
	X += Vx;
	Y += Vy;
	if (Y > 400 - YSize / 2)Y = 400 - YSize / 2;
}


void PLAYER::RenewPlayersSpeed()
{
	Vx += Ax;
	Vy += Ay;

	if (Vy >= 8)
	{
		Vy = 8;
	}
	if (Y >= 400-YSize/2)
	{
		Vy = 0;
	}
}

void PLAYER::RenewPlayersAccel()
{
	Ax = Fx / Mass;
	Ay = Fy / Mass;
}

void PLAYER::AddForce(double AddFx, double AddFy)
{
	Fx += AddFx;
	Fy += AddFy;
}

void PLAYER::Frt()
{
	Fx = 0; Fy = 0;
}

void PLAYER::PlayerIni(double PointX, double PointY)
{
	X = PointX; Y = PointY;
	Vx = 0.0;	Vy = 0.0;
	Ax = 0.0;	Ay = 0.0;
	Fx = 0.0;	Fy = 0.0;
	Mass = 1.0; 
	GraphChangeTimeQMax = 80;
	GraphChangeTimeQNow = 41;
	GraphNum = 1;
	LoadCharGraph();
}

void PLAYER::LoadCharGraph()
{
	LoadDivGraph("img/charchip.png", 6, 3, 2, 32, 48, Graph);
	GetGraphSize(Graph[0], &XSize, &YSize);
}

void PLAYER::PlayerDraw()
{
	DrawRotaGraph((int)X, (int)Y, 1.0, 0.0, Graph[GraphNum], TRUE);
}

void PLAYER::RenewGraphNum()
{
	GraphChangeTimeQNow--;
	if (GraphChangeTimeQNow == 0)
	{
		GraphChangeTimeQNow = GraphChangeTimeQMax;
	}
	if (GraphChangeTimeQNow > 80)GraphNum = 2;
	else if (GraphChangeTimeQNow > 40)GraphNum = 0;
	else GraphNum = 2;
}