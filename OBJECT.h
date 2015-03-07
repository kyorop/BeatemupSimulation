#pragma once
class OBJECT
{
public:
	int Graph[4];//オブジェクトの画像を収納
	int Type,XSize,YSize;//オブジェクトのタイプ、横幅、縦幅を収納
	double X, Y;//オブジェクトのX座標とY座標
	double PreX, PreY;//オブジェクトが選択されたときに動かす前の座標を収納する
	double Vx, Vy;//オブジェクトのX軸とY軸に対応するスピード
	double Ax, Ay;//オブジェクトのX軸とY軸に対応する加速度
	double Fx, Fy;//オブジェクトに働くX軸とY軸に対応する力
	double Mass;//オブジェクトの質量
	bool OnGround;//オブジェクトが接地しているかどうか
	bool Selected;//オブジェクトが選択されているかどうか
	void RenewObjectsPoint();//オブジェクトの位置座標を更新する
	void RenewObjectsSpeed();//オブジェクトのスピードを更新する
	void RenewObjectsAccel();//オブジェクトの加速度を更新する
	void AddForce(double AddFx, double AddFy);//オブジェクトに加わっている力を更新する
	void LoadObjectGraph();//画像を読み込んでGraph[]に収納。その後画像の横幅と縦幅をそれぞれXSizeとYSizeに取得
};

