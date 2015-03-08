#include "PLAYER.h"
#include"DxLib.h"
#include"Map.h"
#include<math.h>

#define UNDERDRAWLINE 320
#define MAXJUMP 5
#define MAXJUMP2 6
#define PI 3.141592


void PLAYER::PlayerIni()
{
	
	AddX = 1; AddY = 0; dropAddY=0.12;
	touchHemisphere = false;
	GraphNum = 1;
	GraphChangeTime_Max = 80;
	TimeMax = 20;
	Time = TimeMax;
	OnGround = false;
	GraphChangeTime_Now = GraphChangeTime_Max;
	LoadDivGraph("img/charchip.png", 3, 3, 1, 32, 48, Graph);
	GetGraphSize(Graph[0], &WIDHT, &HEIGHT);
	map = Map::GetInstance();
	X = 0;	Y = UNDERDRAWLINE - HEIGHT;
	MaxY = Y;
}

void PLAYER::PlayerDraw(int leftX)
{
	for (int r = 0; r < map->GetNumObject(HOLE); r++)
	{
		
		int widht1 = map->m_hole[r].GetPosX() - (int)GetPosX();
		//落とし穴の左端のX座標とキャラクター画像の左端のX座標の差
		//負であればキャラクター画像の左端のX座標は落とし穴の左端のX座標よりも右側にある
		int widht2 = map->m_hole[r].GetPosX()+map->m_hole[r].GetSizeWidth() - ((int)GetPosX()+GetWidht());
		//落とし穴の右端のX座標とキャラクター画像の右端のX座標の差
		//負であればキャラクター画像の右端のX座標は落とし穴の右端のX座標よりも右側にある
		if (widht1<0&&widht2>0)
		{
			SetDrawArea(map->m_hole[r].GetPosX(), 0,
				map->m_hole[r].GetPosX() + map->m_hole[r].GetSizeWidth(),
				map->m_hole[r].GetPosY() + map->m_hole[r].GetSizeHigh()/3*2);
			
		}
	}
	if (Y >= UNDERDRAWLINE + 10 - HEIGHT)
	{
		SetDrawArea(0, 0, 640, UNDERDRAWLINE);
	}

	DrawGraph((int)X-leftX, (int)Y, Graph[GraphNum], TRUE);
	SetDrawAreaFull();
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
	for (int r = 0; r < map->GetNumObject(HEMISPHERE); r++)
	{
		double differenceX = (GetPosX() + GetWidht() / 2) - (map->m_hemisphere[r].GetPosX() + map->m_hemisphere[r].GetSizeWidth() / 2);
		double differenceY = (GetPosY() + GetHeight()) - (map->m_hemisphere[r].GetPosY() + map->m_hemisphere[r].GetSizeHigh());
		if (sqrt(differenceX*differenceX + differenceY*differenceY)<map->m_hemisphere[r].GetSizeHigh())
		{
			if (differenceX>0)
			{
				AddY = -2;
			}
			else
			{
				AddY = -2;
				AddX = -AddX;
				touchHemisphere = true;
			}
		}
	}
	X += AddX;
	Y += AddY;
	if (Y < MaxY)MaxY = Y;
	if (AddY>MAXJUMP2)AddY = MAXJUMP2;
	if (AddY < -MAXJUMP2)AddY = -MAXJUMP2;
	if (touchHemisphere&&OnGround)
	{
		AddX = 1.0;
	}
	if (OnGround == false)
	{
		AddY += dropAddY;
	}
}

bool PLAYER::CheckGameover()
{
	for (int r = 0; r < map->GetNumObject(TRIANGLE); r++)
	{
		if (GetPosX() > map->m_triangle[r].GetPosX() + map->m_triangle[r].GetSizeWidth() / 2 - map->m_triangle[r].GetSizeWidth() / 4
			&& GetPosX() < map->m_triangle[r].GetPosX() + map->m_triangle[r].GetSizeWidth() / 2 + map->m_triangle[r].GetSizeWidth() / 4
			&& GetPosY() + GetHeight() > map->m_triangle[r].GetPosY()
			&& GetPosY() < map->m_triangle[r].GetPosY())
		{
			return true;
		}
	}
	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		if (GetPosX() + GetWidht() - 3> map->m_square[r].GetPosX()
			&& GetPosX() + 3 < map->m_square[r].GetPosX() + map->m_square[r].GetSizeWidth()
			&& GetPosY() + GetHeight() - 3> map->m_square[r].GetPosY()
			&& GetPosY() + 3 < map->m_square[r].GetPosY() + map->m_square[r].GetSizeHigh())
		{
			return true;
		}
	}
/*
	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		if (GetPosX() > map->m_square[r].GetPosX() - GetWidht()
			&& GetPosX() < map->m_square[r].GetPosX() - map->m_square[r].GetSizeWidth()
			&& GetPosY() > map->m_square[r].GetPosY() - GetHeight()
			&& GetPosY() < map->m_square[r].GetPosY() - map->m_square[r].GetSizeHigh())
		{
			return true;
		}
	}*/
	
	for (int r = 0; r < map->GetNumObject(TRIANGLE); r++)
	{
		if (GetPosX() + GetWidht() / 2> map->m_triangle[r].GetPosX() + map->m_triangle[r].GetDrawSizeWidth() / 7 * 3
			&& GetPosX() + GetWidht() / 2 < map->m_triangle[r].GetPosX() + map->m_triangle[r].GetSizeWidth() / 7 * 4
			&& GetPosY() + GetHeight() > map->m_triangle[r].GetPosY() + map->m_triangle[r].GetSizeHigh() / 5 * 2
			&& GetPosY() + GetHeight() < map->m_triangle[r].GetPosY() + map->m_triangle[r].GetSizeHigh())
		{
			return true;
		}
	}
	
	if (Y>368)//画面より下に下がったらゲームオーバー
	{
		return true;
	}
	return false;
}
bool PLAYER::CheckGameClear(int ClearLineX)
{
	if (X > ClearLineX&&OnGround)
	{
		return true;
	}
	return false;
}

void PLAYER::DoJump()
{
	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		int height = map->m_square[r].GetSizeHigh();
		int widht = map->m_square[r].GetPosX() - (int)GetPosX();
		if (widht <= AddX*sqrt(2 * (height) / dropAddY) + GetWidht() && OnGround&&widht>GetWidht())
		{
			AddY = 0;
			AddY -= sqrt(2 * dropAddY*(height));
			if (AddY <= -MAXJUMP)AddY = -MAXJUMP;
		}
	}
	for (int r = 0; r < map->GetNumObject(TRIANGLE); r++)
	{
		int height = map->m_triangle[r].GetSizeHigh() + GetHeight();
		int widht = map->m_triangle[r].GetPosX() + map->m_triangle[r].GetDrawSizeWidth() / 2 - (int)GetPosX();
		if (widht <= AddX*sqrt(2 * (height) / dropAddY) && OnGround&&widht>GetWidht())
		{
			AddY = 0;
			AddY -= sqrt(2 * dropAddY*(height));
			if (AddY <= -MAXJUMP)AddY = -MAXJUMP;
		}
	}
	
	for (int r = 0; r < map->GetNumObject(HEMISPHERE); r++)
	{
		int height = map->m_hemisphere[r].GetSizeHigh() + GetHeight() / 2;
		int widht = map->m_hemisphere[r].GetPosX() + map->m_hemisphere[r].GetDrawSizeWidth() / 2 - (int)GetPosX();
		if (widht <= AddX*sqrt(2 * (height) / dropAddY) + GetWidht() / 2 && OnGround&&widht>GetWidht())
		{
			AddY = 0;
			AddY -= sqrt(2 * dropAddY*(height));
			if (AddY <= -MAXJUMP)AddY = -MAXJUMP;
		}
	}
	
	for (int r = 0; r < map->GetNumObject(SPRING); r++)
	{
		int height = map->m_spring[r].GetSizeHigh();
		int widht = map->m_spring[r].GetPosX() - (int)GetPosX();
		if (widht <= AddX*sqrt(2 * (height) / dropAddY) + GetWidht() && OnGround&&widht>GetWidht())
		{
			AddY = 0;
			AddY -= sqrt(2 * dropAddY*(height));
			if (AddY <= -MAXJUMP)AddY = -MAXJUMP;
		}
	}
	for (int r = 0; r < map->GetNumObject(SPRING); r++)
	{
		int height = map->m_spring[r].GetPosY() - ((int)Y + HEIGHT);
		//オブジェクトの上底の高さとキャラクター画像の底辺の高さの差
		//負であればキャラクター画像の底辺はオブジェクトの上底よりも下に表示されている
		int widht1 = map->m_spring[r].GetPosX() - ((int)X + WIDHT);
		//オブジェクトの左端とキャラクター画像の右端のX座標の差
		//負であればキャラクター画像の右端はオブジェクトの左端よりも右に表示されている
		int widht2 = map->m_spring[r].GetPosX() + map->m_spring[r].GetSizeWidth() - (int)X;
		//オブジェクトの右端とキャラクター画像の左端のX座標の差
		//負であればキャラクター画像の左端はオブジェクトの右端よりも左に表示されている
		if (widht1 <0 && widht2>0 && height <= 0)
		{
			AddY = AddY*(-1.35);
			if (AddY < MAXJUMP2)AddY = -MAXJUMP2;
		}
	}
	
}


void PLAYER::DoJump_a()
{
	if (OnGround)
	{
		if (CheckHitKey(KEY_INPUT_2))
		{
			AddY = 0;
			AddY -= 4.2;
		}
		if (CheckHitKey(KEY_INPUT_3))
		{
			AddY = 0;
			AddY -= 4.4;
		}
		if (CheckHitKey(KEY_INPUT_4))
		{
			AddY = 0;
			AddY -= 4.6;
		}
		if (CheckHitKey(KEY_INPUT_5))
		{
			AddY = 0;
			AddY -= 4.8;
		}
		if (CheckHitKey(KEY_INPUT_6))
		{
			AddY = 0;
			AddY -= 5.0;
		}
	}
}

void PLAYER::CheckOnGround()
{

	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		int height = map->m_square[r].GetPosY()-((int)Y+HEIGHT);
		//オブジェクトの上底の高さとキャラクター画像の底辺の高さの差
		//負であればキャラクター画像の底辺はオブジェクトの上底よりも下に表示されている
		int widht1 = map->m_square[r].GetPosX() - ((int)X + WIDHT);
		//オブジェクトの左端とキャラクター画像の右端のX座標の差
		//負であればキャラクター画像の右端はオブジェクトの左端よりも右に表示されている
		int widht2 = map->m_square[r].GetPosX() + map->m_square[r].GetSizeWidth() - (int)X;
		//オブジェクトの右端とキャラクター画像の左端のX座標の差
		//負であればキャラクター画像の左端はオブジェクトの右端よりも左に表示されている
		if (widht1 <0 &&widht2>0&&height<=0)
		{
			DrawString(UNDERDRAWLINE, 50, "TRUE", GetColor(0, 0, 0));
			if (AddY>0)
			AddY = 0;
			OnGround = true;
		}
		else
		{
			OnGround = false;
		}
	}
	for (int r = 0; r < map->GetNumObject(HOLE); r++)
	{

		int widht1 = map->m_hole[r].GetPosX() - (int)GetPosX();
		//落とし穴の左端のX座標とキャラクター画像の左端のX座標の差
		//負であればキャラクター画像の左端のX座標は落とし穴の左端のX座標よりも右側にある
		int widht2 = map->m_hole[r].GetPosX() + map->m_hole[r].GetSizeWidth() - ((int)GetPosX() + GetWidht());
		//落とし穴の右端のX座標とキャラクター画像の右端のX座標の差
		//負であればキャラクター画像の右端のX座標は落とし穴の右端のX座標よりも右側にある
		int height = map->m_hole[r].GetPosY() + map->m_hole[r].GetSizeHigh() / 2 - (int)GetPosY();
		if (GetPosX() > map->m_hole[r].GetPosX() 
			&& GetPosX() < map->m_hole[r].GetPosX() + map->m_hole[r].GetSizeWidth()
			/*&& GetPosY() > map->m_hole[r].GetPosY() - GetHeight()
			&& GetPosY() < map->m_hole[r].GetPosY() - map->m_hole[r].GetSizeHigh()*/)
		{
			OnGround = false;
		}
	}
	
	if (Y >= UNDERDRAWLINE+10 - HEIGHT)
	{
		OnGround = false;
	}
	else if (Y >= UNDERDRAWLINE - HEIGHT)
	{
		OnGround = true;
		if (AddY >= 0)
		{
			AddY = 0;
		}
		Y = UNDERDRAWLINE - HEIGHT;
	}
	else
	{
		OnGround = false;
	}	
}

