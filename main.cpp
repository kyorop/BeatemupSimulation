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

	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する	
	PLAYER player;//プレイヤークラスの宣言
	PlayersValidation validation;//動作確認のクラスの宣言
	validation.ValidationIni();


	Map* map = Map::GetInstance(); //マップオブジェクトの生成
	while (1)
	{

		ClearDrawScreen();
		DrawBox(0, 0, 640, 400,GetColor(255,255,255),TRUE);
		if (CheckHitKey(KEY_INPUT_Q))
		{
			validation.ValidationStart();
			player.PlayerIni();//プレイヤーの初期化
		}
		if (validation.ValidationPlay()){ validation.Validation(&player); }
		else
		{
			DrawString(0, 0, "Qキーを押すとPlayerの動作確認", GetColor(0, 0, 0));
		}

		

		ScreenFlip();

		if (ProcessMessage() == -1)
			break;
	}

	DxLib_End();
	return 0;
}
