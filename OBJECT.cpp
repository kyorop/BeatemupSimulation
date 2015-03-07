#include "OBJECT.h"
#include"DxLib.h"

void OBJECT::RenewObjectsPoint()
{
	X += Vx;
	Y += Vy;
}


void OBJECT::RenewObjectsSpeed()
{
	Vx += Ax;
	Vy += Ay;
}

void OBJECT::RenewObjectsAccel()
{
	Ax = Fx / Mass;
	Ay = Fy / Mass;
}

void OBJECT::AddForce(double AddFx, double AddFy)
{
	Fx += AddFx;
	Fy += AddFy;
}

void OBJECT::LoadObjectGraph()
{
	LoadDivGraph("img/objectchip.png", 4, 4, 2, 32, 32, Graph);
	GetGraphSize(Graph[0], &XSize, &YSize);
}
