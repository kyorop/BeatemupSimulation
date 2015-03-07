#include "PlayersValidation.h"
#include "DxLib.h"
#include"Map.h"

Map* map = Map::GetInstance();

void PlayersValidation::Validation(PLAYER *player)
{

	DrawString(0, 16, "PLAYERSVALIDATION", GetColor(0, 0, 0));
	DrawString(0, 0, "Wキーを押すと動作確認を終了", GetColor(0, 0, 0));

	DrawFormatString(0, 48, GetColor(0, 0, 0), "height：%d", player->GetHeight());
	DrawFormatString(200, 48, GetColor(0, 0, 0), "widht：%d", player->GetWidht());
	DrawFormatString(0, 64, GetColor(0, 0, 0), "posX：%.2f", player->GetPosX());
	DrawFormatString(200, 64, GetColor(0, 0, 0), "posY：%.2f", player->GetPosY());
	DrawFormatString(400, 64, GetColor(0, 0, 0), "MaxY：%.2f", player->GetMaxY());
	DrawFormatString(0, 80, GetColor(0, 0, 0), "OnGround：%d", player->GetOnGround());
	DrawFormatString(200, 80, GetColor(0, 0, 0), "AddY：%.1f", player->GetAddY());
	DrawString(0, 32, "2～6キーに応じてジャンプします", GetColor(0, 0, 0));
	if (CheckHitKey(KEY_INPUT_W)){ ValidationEnd(); }


	player->DoJump();
	player->DoJump_a();
	player->GetOnGround();
	player->PlayerMove();
	player->GraphNumChange();
	player->PlayerDraw();
}



