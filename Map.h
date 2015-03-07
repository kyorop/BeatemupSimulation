
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

	void Draw();
private:
	int m_numobjects[TRIANGLE + 1]; //�e�I�u�W�F�N�g���������邩�B�K��TRIANGLE���Ō��
	template<typename tn, typename real_tn>void ReNew(tn &target, int num, int renum, real_tn type); //target���w���z���renum�Ɋg������
	// ������R�s�[���֎~����
	Map();
	~Map();
	Map(const Map& rhs);
	Map& operator=(const Map& rhs);
};

