#include "PLAYER.h"
#include"DxLib.h"
#include"Map.h"
#include<math.h>

//double PLAYER::GetPosX(){	return X;}
//double PLAYER::GetPosY(){	return Y;}
//int PLAYER::GetHeight(){	return HEIGHT;}
//int PLAYER::GetWidht(){	return WIDHT;}


void PLAYER::PlayerIni()
{
	X = 0;	Y = 352;
	AddX = 1; AddY = 0; dropAddY=0.1;
	MaxY = Y;
	GraphNum = 1;
	GraphChangeTime_Max = 80;
	TimeMax = 20;
	Time = TimeMax;
	OnGround = false;
	GraphChangeTime_Now = GraphChangeTime_Max;
	LoadDivGraph("img/charchip.png", 3, 3, 1, 32, 48, Graph);
	GetGraphSize(Graph[0], &WIDHT, &HEIGHT);
	map = Map::GetInstance();

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
	if (Y < MaxY)MaxY = Y;

	if (OnGround==false)
	{
		AddY += dropAddY;
	}
	
	/*if (Y >= 400 - HEIGHT)
	{
		OnGround = true;
		if (AddY >= 0)
		{
			AddY = 0;
		}
		Y = 400 - HEIGHT;
	}
	else
	{
		OnGround = false;
	}*/
}

void PLAYER::DoJump()
{
	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		int height = map->m_square[r].GetSizeHigh();
		int widht = map->m_square[r].GetPosX() - (int)GetPosX();
		if (widht <= AddX*sqrt(2 * (height) / dropAddY)+GetWidht() && OnGround&&widht>GetWidht())
		{
			AddY = 0;
			AddY -= sqrt(2 * dropAddY*(height));
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
			AddY -= 2;
		}
		if (CheckHitKey(KEY_INPUT_3))
		{
			AddY = 0;
			AddY -= 3;
		}
		if (CheckHitKey(KEY_INPUT_4))
		{
			AddY = 0;
			AddY -= 4;
		}
		if (CheckHitKey(KEY_INPUT_5))
		{
			AddY = 0;
			AddY -= 5;
		}
		if (CheckHitKey(KEY_INPUT_6))
		{
			AddY = 0;
			AddY -= 6;
		}
	}
}

bool PLAYER::GetOnGround()
{

	for (int r = 0; r < map->GetNumObject(SQUARE); r++)
	{
		int height = map->m_square[r].GetPosY()-(Y+HEIGHT);
		//�I�u�W�F�N�g�̏��̍����ƃL�����N�^�[�摜�̒�ӂ̍����̍�
		//���ł���΃L�����N�^�[�摜�̒�ӂ̓I�u�W�F�N�g�̏��������ɕ\������Ă���
		int widht1 = map->m_square[r].GetPosX() - (X+WIDHT);
		//�I�u�W�F�N�g�̍��[�ƃL�����N�^�[�摜�̉E�[��X���W�̍�
		//���ł���΃L�����N�^�[�摜�̉E�[�̓I�u�W�F�N�g�̍��[�����E�ɕ\������Ă���
		int widht2 = map->m_square[r].GetPosX() + map->m_square[r].GetSizeWidth()-X;
		//�I�u�W�F�N�g�̉E�[�ƃL�����N�^�[�摜�̍��[��X���W�̍�
		//���ł���΃L�����N�^�[�摜�̍��[�̓I�u�W�F�N�g�̉E�[�������ɕ\������Ă���
		if (widht1 <0 &&widht2>0&&height<=0)
		{
			DrawString(400, 50, "TRUE", GetColor(0, 0, 0));
			if (AddY>0)
			AddY = 0;
			OnGround = true;
			return OnGround;
		}
		else
		{
			OnGround = false;
		}
	}
	if (Y >= 400 - HEIGHT)
	{
		OnGround = true;
		if (AddY >= 0)
		{
			AddY = 0;
		}
		Y = 400 - HEIGHT;
	}
	else
	{
		OnGround = false;
	}
	return OnGround;
}