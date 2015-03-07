
//�e�I�u�W�F�N�g�Ɍp�����邽�߂̃N���X
#pragma once
#include "Object_Interface.h"
class Object :
	public Object_Interface
{
public:
	Object();
	~Object();
	int GetSizeWidth(){ return m_size_x; } //�I�u�W�F�N�g�̉��̃T�C�Y��Ԃ�
	int GetSizeHigh(){ return m_size_y; } //�I�u�W�F�N�g�̏c�̃T�C�Y��Ԃ�
	int GetPosX(){ return m_pos_x; } //�I�u�W�F�N�g�̍����X���W��Ԃ�
	int GetPosY(){ return m_pos_y; } //�I�u�W�F�N�g�̍����Y���W��Ԃ�
	KindObject GetObjectType(){ return m_kindobject; } //�I�u�W�F�N�g�̃^�C�v��Ԃ�
	void SetObject(int posx, int posy, int sizex, int sizey);

//	virtual void Draw()=0;
private:
	int m_pos_x; //�I�u�W�F�N�g�̍����x���W
	int m_pos_y;
	int m_size_x;
	int m_size_y; //�I�u�W�F�N�g�̉��̑傫��
	KindObject m_kindobject; //�I�u�W�F�N�g�̃^�C�v
protected:
	void SetKindObject(KindObject ko){ m_kindobject = ko; } //�I�u�W�F�N�g�̃^�C�v����
};

