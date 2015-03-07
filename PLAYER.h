#ifndef PLAYER_H
#define PLAYER_H

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
	
public:
	double GetPosX();
	double GetPosY();
	int GetHeight();
	int GetWidht();
	void PlayerMove();
	void PlayerIni();
	void PlayerDraw();
	void GraphNumChange();
	void DoJump();
};

#endif