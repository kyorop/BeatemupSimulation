#include "PlayersValidation.h"
#include"PLAYER.h"
#include "DxLib.h"

void PlayersValidation::Validation(PLAYER *player)
{

	DrawString(0, 16, "PLAYERSVALIDATION　（キー）：（上昇初速度）", GetColor(0, 0, 0));
	DrawString(0, 0, "Wキーを押すと動作確認を終了", GetColor(0, 0, 0));

	DrawFormatString(0, 48, GetColor(0, 0, 0), "height：%d", player->GetHeight());
	DrawFormatString(100, 48, GetColor(0, 0, 0), "widht：%d", player->GetWidht());
	DrawFormatString(0, 64, GetColor(0, 0, 0), "posX：%.1f", player->GetPosX());
	DrawFormatString(100, 64, GetColor(0, 0, 0), "posY：%.1f", player->GetPosY());
	DrawFormatString(200, 64, GetColor(0, 0, 0), "MaxY：%.1f", player->GetMaxY());
	DrawFormatString(300, 64, GetColor(0, 0, 0), "最大上昇ピクセル数：%.2f", 352- player->GetMaxY());
	DrawFormatString(100, 80, GetColor(0, 0, 0), "AddY：%.1f", player->GetAddY());
	DrawString(0, 32, "2キー：4.2、3キー：4.4，4キー：4.6、5キー：4.8、6キー：5.0", GetColor(0, 0, 0));
	if (CheckHitKey(KEY_INPUT_W)){ ValidationEnd(); }


	player->DoJump();
	player->DoJump_a();
	player->CheckOnGround();
	player->PlayerMove();
	player->GraphNumChange();
	player->PlayerDraw();
}



