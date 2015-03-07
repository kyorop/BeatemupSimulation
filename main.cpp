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

	/*map->MakeObject(SQUARE, 100, 400-50, 80, 50);*/
	/*map->MakeObject(HOLE, 300, 400 - 5, 50, 10);*/
	map->MakeObject(TRIANGLE, 100, 400 - 30, 30, 30);
	map->MakeObject(TRIANGLE, 250, 400 - 40, 40, 40);
	map->MakeObject(TRIANGLE, 500, 400 - 50, 50, 50);

	while (CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{

		ClearDrawScreen();

		DrawBox(0, 0, 640, 400,GetColor(255,255,255),TRUE);
		/*DrawBox(100, 400 - 50, 180, 400,GetColor(0,255,0),TRUE);*/
		/*DrawOval(325, 400, 25, 5, GetColor(190, 220, 200),TRUE);*/		
		DrawTriangle(100, 400, 130, 400, 115, 370, GetColor(255, 0, 0), TRUE);
		DrawTriangle(250, 400, 290, 400, 270, 360, GetColor(255, 0, 0), TRUE);
		DrawTriangle(500, 400, 550, 400, 525, 350, GetColor(255, 0, 0), TRUE);
		if (CheckHitKey(KEY_INPUT_Q))
		{
			validation.ValidationStart();
			player.PlayerIni();//�v���C���[�̏�����
		}
		if (validation.ValidationPlay()){ validation.Validation(&player); }
		else
		{
			DrawString(0, 0, "Q�L�[��������Player�̓���m�F", GetColor(0, 0, 0));
		}
//
//			
//		
//		mouse_flag = GetMouseInput() & MOUSE_INPUT_LEFT;
//		if (mouse_flag && !mouse_last_flag)
//		{
//			map->MakeObject(SPRING, 10, 10, 10, 10);
//			mouse_last_flag = TRUE;
//		}
//		if (!mouse_flag && mouse_last_flag)
//		{
//			mouse_last_flag = FALSE;
//		}
//
//		
//		
//		
//		DrawFormatString(0, 64, GetColor(0, 128, 0), "test�F%d", map->GetNumObject(SPRING)); //�g�����̗�
//		if (map->GetNumObject(SPRING) >= 2)
//		{
//			DrawFormatString(0, 80, GetColor(0, 128, 0), "test2�F%d", map -> m_spring[1].GetPosX()); //�g�����̗�
//		}
		

		/*sceneManager.Update();
		sceneManager.Draw();*/



		/*sceneManager.Update();
		sceneManager.Draw();*/

		ScreenFlip();

		if (ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
			break;
	}

	DxLib_End();
	return 0;
}
