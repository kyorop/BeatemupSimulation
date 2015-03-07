#pragma once
#include"DxLib.h"

#include"PLAYER.h"
#include"PlayersValidation.h"

#include"Map.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
		return -1;
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);
	SetMouseDispFlag(TRUE);//�}�E�X�|�C���^���Q�[���E�B���h�E�ɕ\������

	
	int Time = 60;

	
	PlayersValidation validation;


	bool PlayMode=false;
	
	Map* map = Map::GetInstance(); //�}�b�v�I�u�W�F�N�g�̐���
	while (1)
	{

		ClearDrawScreen();
		DrawBox(0, 0, 640, 400,GetColor(255,255,255),TRUE);
		DrawString(0, 0, "Q�L�[��������Player�̓���m�F", GetColor(0, 0, 0));
		if (CheckHitKey(KEY_INPUT_Q))
		{
			validation.Validation();
		}

		

		ScreenFlip();

		if (ProcessMessage() == -1)
			break;
	}

	DxLib_End();
	return 0;
}
