#include "PlayersValidation.h"
#include "DxLib.h"

void PlayersValidation::Validation()
{
	PLAYER player;
	player.PlayerIni();

	
	while (true)
	{
		double playerY = player.GetPosY();


		ClearDrawScreen();
		DrawBox(0, 0, 640, 400, GetColor(255, 255, 255), TRUE);
		DrawString(0, 0, "PLAYERSVALIDATION", GetColor(0, 0, 0));
		DrawFormatString(0, 16, GetColor(0, 0, 0), "Yç¿ïWÅF%lf",&playerY);
		player.PlayerMove();
		player.GraphNumChange();
		player.PlayerDraw();


		ScreenFlip();

		if (ProcessMessage() == -1)
			break;
	}

}



