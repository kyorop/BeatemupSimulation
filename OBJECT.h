#pragma once
class OBJECT
{
public:
	int Graph[4];//�I�u�W�F�N�g�̉摜�����[
	int Type,XSize,YSize;//�I�u�W�F�N�g�̃^�C�v�A�����A�c�������[
	double X, Y;//�I�u�W�F�N�g��X���W��Y���W
	double PreX, PreY;//�I�u�W�F�N�g���I�����ꂽ�Ƃ��ɓ������O�̍��W�����[����
	double Vx, Vy;//�I�u�W�F�N�g��X����Y���ɑΉ�����X�s�[�h
	double Ax, Ay;//�I�u�W�F�N�g��X����Y���ɑΉ���������x
	double Fx, Fy;//�I�u�W�F�N�g�ɓ���X����Y���ɑΉ������
	double Mass;//�I�u�W�F�N�g�̎���
	bool OnGround;//�I�u�W�F�N�g���ڒn���Ă��邩�ǂ���
	bool Selected;//�I�u�W�F�N�g���I������Ă��邩�ǂ���
	void RenewObjectsPoint();//�I�u�W�F�N�g�̈ʒu���W���X�V����
	void RenewObjectsSpeed();//�I�u�W�F�N�g�̃X�s�[�h���X�V����
	void RenewObjectsAccel();//�I�u�W�F�N�g�̉����x���X�V����
	void AddForce(double AddFx, double AddFy);//�I�u�W�F�N�g�ɉ�����Ă���͂��X�V����
	void LoadObjectGraph();//�摜��ǂݍ����Graph[]�Ɏ��[�B���̌�摜�̉����Əc�������ꂼ��XSize��YSize�Ɏ擾
};

