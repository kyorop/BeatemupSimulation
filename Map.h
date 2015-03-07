
//�e�I�u�W�F�N�g�̐��Ȃǂ̏������}�X�^�[�N���X
#pragma once
#include"Square.h"
#include"Triangle.h"
#include"HemiSphere.h"
#include"Spring.h"
#include"Hole.h"

class Map
{
public:
	static Map* instance;
	static Map* GetInstance()
	{
		if (instance == NULL)
		{
			instance = new Map;
		}
		return instance;
	}
	int GetNumObject(KindObject ko){ return m_numobjects[ko]; } //�w�肵����ނ̃I�u�W�F�N�g���������邩�Ԃ�
	Square* m_square; //Square�I�u�W�F�N�g�̔z��
	Triangle* m_triangle;
	HemiSphere* m_hemisphere;
	Spring* m_spring;
	Hole* m_hole;
	void MakeObject(KindObject ko, int posx, int posy, int sizex, int sizey); //ko�^�̃I�u�W�F�N�g��ǉ�����
	void CreateDraw(); //MapCreate���ł�Draw
	void Draw(); //���s����Draw
	int CreateUpdate(); //MapCreate���ł�Upadate
private:
	int m_numobjects[TRIANGLE + 1]; //�e�I�u�W�F�N�g���������邩�B�K��TRIANGLE���Ō��
	const int stage_size_x = 1000 , stage_size_y = 480; //�X�e�[�W�̃T�C�Y
	template<typename tn, typename real_tn>void ReNew(tn &target, int num, int renum, real_tn type); //target���w���z���renum�Ɋg������

	int m_h_square;
	int m_h_triangle;
	int m_h_hemisphere;
	int m_h_hole;
	int m_h_spring;
	bool m_mouse_updown; //�}�E�X�������n�߂����ǂ����BTRUE�Ȃ炷�łɉ����n�߂Ă���
	char nowchoose; //���݃}�E�X�ɑI�΂�Ă���I�u�W�F�N�g���L���B��̓I�ɂ�16�Ȃ�2��ޖڂ�7�ԖځA31�Ȃ�3��ޖڂ�2�Ԗ�
	// ������R�s�[���֎~����
	Map();
	~Map();
	Map(const Map& rhs);
	Map& operator=(const Map& rhs);
};