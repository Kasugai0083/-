#ifndef PLAYER_H_
#define PLAYER_H_


#include "../Character.h"

class Player : public Character {
	 
public:

	//Player(){}

	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool GetIsLight() override{
		return m_IsLight;
	}

	bool GetIsMask()override{
		return m_IsMask;
	}

	bool GetIsMonitor()override{
		return m_IsMonitor;
	}
	bool GetIsDeath()override { return m_IsDeath; };
	void OnMask();


private:

// �t���O
	bool m_IsDeath;		// �����Ă邩�ǂ���(�K�v�����邩�ȁH)
	bool m_IsLight;		// ���C�g�����Ă邩�ǂ���
	bool m_IsMask;		// �}�X�N�����Ă邩�ǂ���
	bool m_IsMonitor;	// ���j�^�[�����Ă��邩�ǂ���
	float m_MaskAnimation; // �}�X�N�̃A�j���[�V�����^�C�}�[


};

#endif
