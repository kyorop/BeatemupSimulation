#pragma once
#include"DxLib.h"
#include"PLAYER.h"
#include"Map.h"

#define GRAVITY 1
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
		return -1;
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する
	bool PlayMode=false;
	PLAYER Pl;
	Pl.PlayerIni(50.0,50.0);

	/*Pl.Vx = 3.0;*/
	Map* map = Map::GetInstance(); //マップオブジェクトの生成
	Pl.Vx = 2.0;
	
	int Time = 60;
	while (1)
	{

		ClearDrawScreen();
		DrawBox(0, 0, 640, 400,GetColor(255,255,255),TRUE);
		Pl.Frt();
		Pl.RenewGraphNum();
		Pl.PlayerDraw();
		Pl.AddForce(0.0, GRAVITY*Pl.Mass);
		if (Pl.Y >= 400-Pl.YSize/2)
		{
			Pl.OnGround = true;
		}
		else
		{
			Pl.OnGround = false;
		}
		if (Pl.OnGround)
		{
			Pl.AddForce(0.0, -GRAVITY* Pl.Mass);
			if (Time > 0)
			{
				Time--;
		}
			else
			{
				Time = 60;
				Pl.AddForce(0.0, -1000 * Pl.Mass);
			}
		}
		Pl.RenewPlayersAccel();
		Pl.RenewPlayersSpeed();
		Pl.RenewPlayersPoint();

		
		DrawFormatString(0, 0, GetColor(0,0,0), "速度(Y軸)：%lf", Pl.Vy);
		DrawFormatString(0, 16, GetColor(0,0,0), "加速度(Y軸)：%lf", Pl.Ay);
		DrawFormatString(0, 32, GetColor(0,0,0), "力(Y軸)：%lf", Pl.Fy);
		DrawFormatString(0, 48, GetColor(0, 0, 0), "Y座標：%lf", Pl.Y);
		DrawFormatString(0, 64, GetColor(0, 128, 0), "test：%d", map->GetNumObject(SPRING)); //使い方の例
		ScreenFlip();

		if (ProcessMessage() == -1)
			break;
	}

	DxLib_End();
	return 0;
}
