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
	{
		m_HasGFreddySpown = false;
	}
	/*
		�f�X�g���N�^
	*/
	~Player() override {}

	void Init()override;

	void Update()override;

	void Draw()override;

	bool HasMask() const override{
		return m_IsMask;
	}

	bool IsActive() override { return m_IsActive; };

	MonitorView CurrentViewMonitorID() const override{
		return m_MonitorViewID;
	}

	//���j�^�[�V�[���J�ڂ��Ǘ�����֐�
	void ControlMonitor() override;
	//�Q�[���V�[���J�ڂ��Ǘ�����֐�
	void ControlGameScene() override;

	//�S�[���f���t���f�B�̃t���O���擾
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };


private:
	void OnMask();

private:
	bool m_IsActive;		// �����Ă邩�ǂ���(�K�v�����邩�ȁH)
	bool m_IsMask;		// �}�X�N�����Ă邩�ǂ���
	float m_MaskAnimation; // �}�X�N�̃A�j���[�V�����^�C�}�[
	bool m_HasGFreddySpown; //�S�[���f���t���f�B�̃t���O�������Ă��邩�ǂ���

	MonitorView m_MonitorViewID; // ���j�^�[�̂ǂ������Ă��邩

};

#endif
