#include "PlayersValidation.h"
#include "DxLib.h"

void PlayersValidation::Validation(PLAYER *player)
{
	/*double* playerY = player->GetPosY();*/
	DrawString(0, 16, "PLAYERSVALIDATION", GetColor(0, 0, 0));
	DrawString(0, 0, "W�L�[�������Ɠ���m�F���I��", GetColor(0, 0, 0));
	/*DrawFormatString(0, 16, GetColor(0, 0, 0), "Y���W�F%lf", &playerY);
*/
	if (CheckHitKey(KEY_INPUT_W)){ ValidationEnd(); }
	player->PlayerMove();
	player->GraphNumChange();
	player->PlayerDraw();
}



