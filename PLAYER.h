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
	bool touchHemisphere;
	Map* map;

public:
	double GetMaxY(){ return MaxY; }
	double GetPosX(){ return X; }
	double GetPosY(){ return Y; }
	int GetHeight(){ return HEIGHT; }
	int GetWidht(){ return WIDHT; }
	double GetAddX(){ return AddX; }
	void CheckOnGround();
	void PlayerIni();
	void PlayerDraw(int leftX);
	void GraphNumChange();
	void PlayerMove();
	void DoJump();//キャラクターがオブジェクト近づいたらジャンプ
	void DoJump_a();//ジャンプ力による最高高度の確認
	bool CheckGameover();//ゲームオーバーの条件を満たしているかどうかを返す
	double GetAddY(){ return AddY; }
};

#endif