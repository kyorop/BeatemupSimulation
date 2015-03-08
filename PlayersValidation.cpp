#include "PlayersValidation.h"
#include"PLAYER.h"
#include "DxLib.h"

void PlayersValidation::Validation(PLAYER *player)
{

	DrawString(0, 16, "PLAYERSVALIDATION�@�i�L�[�j�F�i�㏸�����x�j", GetColor(0, 0, 0));
	DrawString(0, 0, "W�L�[�������Ɠ���m�F���I��", GetColor(0, 0, 0));

	DrawFormatString(0, 48, GetColor(0, 0, 0), "height�F%d", player->GetHeight());
	DrawFormatString(100, 48, GetColor(0, 0, 0), "widht�F%d", player->GetWidht());
	DrawFormatString(0, 64, GetColor(0, 0, 0), "posX�F%.1f", player->GetPosX());
	DrawFormatString(100, 64, GetColor(0, 0, 0), "posY�F%.1f", player->GetPosY());
	DrawFormatString(200, 64, GetColor(0, 0, 0), "MaxY�F%.1f", player->GetMaxY());
	DrawFormatString(300, 64, GetColor(0, 0, 0), "�ő�㏸�s�N�Z�����F%.2f", 352- player->GetMaxY());
	DrawFormatString(100, 80, GetColor(0, 0, 0), "AddY�F%.1f", player->GetAddY());
	DrawString(0, 32, "2�L�[�F4.2�A3�L�[�F4.4�C4�L�[�F4.6�A5�L�[�F4.8�A6�L�[�F5.0", GetColor(0, 0, 0));
	if (CheckHitKey(KEY_INPUT_W)){ ValidationEnd(); }


	player->DoJump();
	player->DoJump_a();
	player->CheckOnGround();
	player->PlayerMove();
	player->GraphNumChange();
	player->PlayerDraw();
}



