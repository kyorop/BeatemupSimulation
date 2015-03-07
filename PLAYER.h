#ifndef PLAYER_H
#define PLAYER_H

class PLAYER
{
public:
	int Graph[6];//プレイヤーキャラクターの画像を収納
	int GraphChangeTime＿Max, GraphChangeTime＿Now, GraphNum;//画像が切り替わる
	int Type,XSize, YSize;//プレイヤーキャラクターのタイプ、横幅、縦幅を収納
	double X, Y;//プレイヤーキャラクターのX座標とY座標
	double Vx, Vy;//プレイヤーキャラクターのX軸とY軸に対応するスピード
	double Ax, Ay;//プレイヤーキャラクターのX軸とY軸に対応する加速度
	double Fx, Fy;//プレイヤーキャラクターに働くX軸とY軸に対応する力
	double Mass;//プレイヤーキャラクターの質量
	bool OnGround;//プレイヤーキャラクターが接地しているかどうか
	void PlayerIni(double PointX,double PointY);//プレイヤーキャラクターの初期設定
	void RenewPlayersPoint();//プレイヤーキャラクターの位置座標を更新する
	void RenewPlayersSpeed();//プレイヤーキャラクターのスピードを更新する
	void RenewPlayersAccel();//プレイヤーキャラクターの加速度を更新する
	void AddForce(double AddFx,double AddFy);//プレイヤーキャラクターに加わっている力を更新する
	void Frt();
	void LoadCharGraph();//画像を読み込んでGraph[]に収納。その後画像の横幅と縦幅をそれぞれXSizeとYSizeに取得
	void RenewGraphNum();//表示する画像の番号を更新する
	void PlayerDraw();//プレイヤーキャラクターの画像を表示する
};

#endif