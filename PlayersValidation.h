#ifndef PlayerValidation_H
#define PlayerValidation_H

class PLAYER;
class PlayersValidation
{
private:
	bool PlayTF;
	int Stagetime;
	PLAYER* player;
public:
	void Validation();
	void ValidationStart(){ PlayTF = true; }//動作確認を始める
	void ValidationEnd(){ PlayTF = false; }//動作確認を終了する
	bool ValidationPlay(){ return PlayTF; }//動作確認が行われているかどうかを返す
	void ValidationIni(){ PlayTF = false; }
};

#endif