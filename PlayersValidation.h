#ifndef PlayerValidation_H
#define PlayerValidation_H

class PLAYER;
class PlayersValidation
{
private:
	bool PlayTF;
	int Stagetime;
	
public:
	void Validation(PLAYER *player);
	void ValidationStart(){ PlayTF = true; }//����m�F���n�߂�
	void ValidationEnd(){ PlayTF = false; }//����m�F���I������
	bool ValidationPlay(){ return PlayTF; }//����m�F���s���Ă��邩�ǂ�����Ԃ�
	void ValidationIni(){ PlayTF = false; }
};

#endif