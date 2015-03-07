#pragma once
#include"DxLib.h"

#include"PLAYER.h"
#include"PlayersValidation.h"

#include"Map.h"
#include "SceneManger.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	SetMainWindowText("");
	ChangeWindowMode(TRUE);

	if (DxLib_Init() == -1)
		return -1;
	SetGraphMode(640, 480, 16);
	SetDrawScreen(DX_SCREEN_BACK);

	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する
	
	
	bool mouse_flag = false;
	bool mouse_last_flag = false;


	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する	
	PLAYER player;//プレイヤークラスの宣言
	PlayersValidation validation;//動作確認のクラスの宣言
	validation.ValidationIni();

	SceneManger sceneManager;


	Map* map = Map::GetInstance(); //マップオブジェクトの生成

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
