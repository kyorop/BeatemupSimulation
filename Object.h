
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

<<<<<<< HEAD
	//�ȉ���MapCreate�Ŏg�p
	int GetDrawSizeWidth(){ return m_draw_size_x; } //�I�u�W�F�N�g�̉��̃T�C�Y��Ԃ�
	int GetDrawSizeHigh(){ return m_draw_size_y; } //�I�u�W�F�N�g�̏c�̃T�C�Y��Ԃ�
	int GetDrawPosX(){ return m_draw_pos_x; } //�I�u�W�F�N�g�̍����X���W��Ԃ�
	int GetDrawPosY(){ return m_draw_pos_y; } //�I�u�W�F�N�g�̍����Y���W��Ԃ�
	void SetDrawSizeWidth(int x){ m_draw_size_x = x; }
	void SetDrawSizeHigh(int y){ m_draw_size_y = y; }
	void SetDrawPosX(int x){ m_draw_pos_x = x; }
	void SetDrawPosY(int y){ m_draw_pos_y = y; }
	bool m_click_flag; //TRUE�Ȃ猻�݃h���b�O���h���b�v����Ă�
	void CreateDraw(int h_object);
	void Draw(int h_object);
	bool CheckHitMouse(int mouse_x, int mouse_y); //�}�E�X�Ƃ��̃I�u�W�F�N�g�̈ʒu������Ă��邩�ǂ�����Ԃ��B����Ă���Ȃ�TRUE
//	virtual void Draw()=0;
private:
	int m_pos_x; //�I�u�W�F�N�g�̍����x���W
	int m_pos_y;
	int m_size_x;
	int m_size_y; //�I�u�W�F�N�g�̉��̑傫��
	int m_draw_pos_x;
	int m_draw_pos_y;
	int m_draw_size_x; //�}�b�v�쐻�ŕ`�悷��ۂ̉��̑傫��
	int m_draw_size_y; //�}�b�v�쐻�ŕ`�悷��ۂ̉��̑傫��
	KindObject m_kindobject; //�I�u�W�F�N�g�̃^�C�v
protected:
	void SetKindObject(KindObject ko){ m_kindobject = ko; } //�I�u�W�F�N�g�̃^�C�v����
};

