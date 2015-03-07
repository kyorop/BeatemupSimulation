//�O������Q�Ƃ���֐��Q
#pragma once
#include"DxLib.h"

enum KindObject {SQUARE, HEMISPHERE, SPRING, HOLE, TRIANGLE}; //�I�u�W�F�N�g�̎�ނ�����
//�����珇�Ɏl�p�A���~�A�W�����v��A���Ƃ����A�O�p

class Object_Interface
{
public:
	Object_Interface();
	~Object_Interface();
	virtual int GetSizeWidth() = 0; //�I�u�W�F�N�g�̉��̃T�C�Y��Ԃ�
	virtual int GetSizeHigh() = 0; //�I�u�W�F�N�g�̏c�̃T�C�Y��Ԃ�
	virtual int GetPosX() = 0; //�I�u�W�F�N�g�̍����X���W��Ԃ�
	virtual int GetPosY() = 0; //�I�u�W�F�N�g�̍����Y���W��Ԃ�
	virtual KindObject GetObjectType() = 0; //�I�u�W�F�N�g�̃^�C�v��Ԃ�
};

