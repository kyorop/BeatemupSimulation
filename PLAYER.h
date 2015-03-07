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
	void DoJump();//キャラクターがオブジェクト近づいたらジャンプ
	void PlyersUpdate();//プレイヤーキャラクターの動作のまとめ
	void DoJump_a();//ジャンプ力による最高高度の確認

	double GetAddY(){ return AddY; }
};

#endif