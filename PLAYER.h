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
	Map* map;

public:
	double GetPosX(){ return X; }
	double GetPosY(){ return Y; }
	int GetHeight(){ return HEIGHT; }
	int GetWidht(){ return WIDHT; }
	bool GetOnGround(){ return OnGround; }
	void PlayerIni();
	void PlayerDraw();
	void GraphNumChange();
	void PlayerMove();
	void DoJump();//キャラクターがオブジェクト近づいたらジャンプ

	void DoJump_a();//2～6の押したキーの数字分だけ上昇速度が足される

	double GetAddY(){ return AddY; }
};

#endif