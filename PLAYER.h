#ifndef PLAYER_H
#define PLAYER_H

class Map;
class PLAYER
{
private:
    double X, Y;
	int HEIGHT, WIDHT;
	double AddX, AddY,dropAddY;
	int Time,TimeMax;
	int Graph[3];
	int GraphNum;
	int GraphChangeTime_Max;
	int GraphChangeTime_Now;
	bool OnGround;
	double MaxY;
	Map* map;

public:
	double GetMaxY(){ return MaxY; }
	double GetPosX(){ return X; }
	double GetPosY(){ return Y; }
	int GetHeight(){ return HEIGHT; }
	int GetWidht(){ return WIDHT; }
	void CheckOnGround();
	void PlayerIni();
	void PlayerDraw();
	void GraphNumChange();
	void PlayerMove();
	void DoJump();//�L�����N�^�[���I�u�W�F�N�g�߂Â�����W�����v
	void PlyersUpdate();//�v���C���[�L�����N�^�[�̓���̂܂Ƃ�
	void DoJump_a();//�W�����v�͂ɂ��ō����x�̊m�F

	double GetAddY(){ return AddY; }
};

#endif