#ifndef PLAYER_H_
#define PLAYER_H_

#include "../Character.h"
#include "../../Scene/GameScene/GameData.h"

class Player : public Character {
	 
public:
	/*
		�R���X�g���N�^
	*/
	Player():
		Character(true)
	{}
	/*
		�f�X�g���N�^
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasLight() const override{
		return m_IsLight;
	}

	bool HasMask() const override{
		return m_IsMask;
	}

	bool HasMonitor() const override{
		return m_IsMonitor;
	}
	bool IsDeath() override { return m_IsActive; };

	MonitorView CurrentViewMonitorID() const override{
		return m_MonitorViewID;
	}

	void OnMask();


private:
// �t���O
	bool m_IsActive;		// �����Ă邩�ǂ���(�K�v�����邩�ȁH)
	bool m_IsLight;		// ���C�g�����Ă邩�ǂ���
	bool m_IsMask;		// �}�X�N�����Ă邩�ǂ���
	bool m_IsMonitor;	// ���j�^�[�����Ă��邩�ǂ���
	float m_MaskAnimation; // �}�X�N�̃A�j���[�V�����^�C�}�[

	MonitorView m_MonitorViewID; // ���j�^�[�̂ǂ������Ă��邩

};

#endif
