#ifndef PLAYER_H_
#define PLAYER_H_


#include "../Character.h"

class Player : public Character {
	 
public:
	/*
		�R���X�g���N�^
	*/
	Player():
		Character(false)
	{}
	/*
		�f�X�g���N�^
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasLight() override{
		return m_IsLight;
	}

	bool HasMask()override{
		return m_IsMask;
	}

	bool HasMonitor()override{
		return m_IsMonitor;
	}
	bool IsDeath()override { return m_IsActive; };
	void OnMask();


private:
// �t���O
	bool m_IsActive;		// �����Ă邩�ǂ���(�K�v�����邩�ȁH)
	bool m_IsLight;		// ���C�g�����Ă邩�ǂ���
	bool m_IsMask;		// �}�X�N�����Ă邩�ǂ���
	bool m_IsMonitor;	// ���j�^�[�����Ă��邩�ǂ���
	float m_MaskAnimation; // �}�X�N�̃A�j���[�V�����^�C�}�[

};

#endif
