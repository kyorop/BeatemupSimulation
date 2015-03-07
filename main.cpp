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

	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する
	
	
	bool mouse_flag = false;
	bool mouse_last_flag = false;


	SetMouseDispFlag(TRUE);//マウスポインタをゲームウィンドウに表示する	
	PLAYER player;//プレイヤークラスの宣言
	PlayersValidation validation;//動作確認のクラスの宣言
	validation.ValidationIni();

	SceneManger sceneManager;


	Map* map = Map::GetInstance(); //マップオブジェクトの生成
	map->MakeObject(SQUARE, 100, 400-50, 80, 50);
	map->MakeObject(SQUARE, 300, 400 - 100, 50, 100);
	/*int X1 = map->m_square[map->GetNumObject(SQUARE)].GetPosX();
	int Y1 = map->m_square[map->GetNumObject(SQUARE)].GetPosY();
	int SizeX = map->m_square[map->GetNumObject(SQUARE)].GetSizeWidth();
	int SizeY = map->m_square[map->GetNumObject(SQUARE)].GetSizeHigh();*/
	while (CheckHitKey(KEY_INPUT_ESCAPE)==0)
	{

		ClearDrawScreen();
		DrawBox(0, 0, 640, 400,GetColor(255,255,255),TRUE);
		DrawBox(100,350,180, 400, GetColor(0, 255, 0), TRUE);
		DrawBox(300, 300, 350, 400, GetColor(0, 255, 0), TRUE);
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
//		DrawFormatString(0, 64, GetColor(0, 128, 0), "test：%d", map->GetNumObject(SPRING)); //使い方の例
//		if (map->GetNumObject(SPRING) >= 2)
//		{
//			DrawFormatString(0, 80, GetColor(0, 128, 0), "test2：%d", map -> m_spring[1].GetPosX()); //使い方の例
//		}
		

		/*sceneManager.Update();
		sceneManager.Draw();*/


		ScreenFlip();

		if (ProcessMessage() == -1)
			break;
	}

	DxLib_End();
	return 0;
}
