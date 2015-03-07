#pragma once
#include"DxLib.h"

#include"PLAYER.h"
#include"PlayersValidation.h"

#include"Map.h"
#include "SceneManger.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
		return -1;
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	SetMouseDispFlag(TRUE);//�}�E�X�|�C���^���Q�[���E�B���h�E�ɕ\������
	
	
	bool mouse_flag = false;
	bool mouse_last_flag = false;


	SetMouseDispFlag(TRUE);//�}�E�X�|�C���^���Q�[���E�B���h�E�ɕ\������	
	PLAYER player;//�v���C���[�N���X�̐錾
	PlayersValidation validation;//����m�F�̃N���X�̐錾
	validation.ValidationIni();

	SceneManger sceneManager;


	Map* map = Map::GetInstance(); //�}�b�v�I�u�W�F�N�g�̐���
	
	while (CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{

		ClearDrawScreen();
		sceneManager.Update();
		sceneManager.Draw();
		ScreenFlip();

		if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}
