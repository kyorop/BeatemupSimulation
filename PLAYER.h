#ifndef PLAYER_H
#define PLAYER_H

class PLAYER
{
public:
	int Graph[6];//�v���C���[�L�����N�^�[�̉摜�����[
	int GraphChangeTime�QMax, GraphChangeTime�QNow, GraphNum;//�摜���؂�ւ��
	int Type,XSize, YSize;//�v���C���[�L�����N�^�[�̃^�C�v�A�����A�c�������[
	double X, Y;//�v���C���[�L�����N�^�[��X���W��Y���W
	double Vx, Vy;//�v���C���[�L�����N�^�[��X����Y���ɑΉ�����X�s�[�h
	double Ax, Ay;//�v���C���[�L�����N�^�[��X����Y���ɑΉ���������x
	double Fx, Fy;//�v���C���[�L�����N�^�[�ɓ���X����Y���ɑΉ������
	double Mass;//�v���C���[�L�����N�^�[�̎���
	bool OnGround;//�v���C���[�L�����N�^�[���ڒn���Ă��邩�ǂ���
	void PlayerIni(double PointX,double PointY);//�v���C���[�L�����N�^�[�̏����ݒ�
	void RenewPlayersPoint();//�v���C���[�L�����N�^�[�̈ʒu���W���X�V����
	void RenewPlayersSpeed();//�v���C���[�L�����N�^�[�̃X�s�[�h���X�V����
	void RenewPlayersAccel();//�v���C���[�L�����N�^�[�̉����x���X�V����
	void AddForce(double AddFx,double AddFy);//�v���C���[�L�����N�^�[�ɉ�����Ă���͂��X�V����
	void Frt();
	void LoadCharGraph();//�摜��ǂݍ����Graph[]�Ɏ��[�B���̌�摜�̉����Əc�������ꂼ��XSize��YSize�Ɏ擾
	void RenewGraphNum();//�\������摜�̔ԍ����X�V����
	void PlayerDraw();//�v���C���[�L�����N�^�[�̉摜��\������
};

#endif