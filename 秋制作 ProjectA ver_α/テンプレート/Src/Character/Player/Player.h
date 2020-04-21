#ifndef PLAYER_H_
#define PLAYER_H_

/**
*	@file Player.h
*	@author �t����
*	@brief �v���C���[���Ǘ�����N���X������
*/


#include "../Character.h"
#include "../..//Data/GameData.h"

class Player : public Character {
	 
public:
	// �R���X�g���N�^
	Player():
		Character(true)
	{
		m_HasGFreddySpown = false;
		m_HasMonitor = false;
		m_ViewID = SubGameScene::CENTER_VIEW;
		TmpRoom = SubGameScene::CENTER_VIEW;
		TmpMonitor = SubGameScene::WORKSHOP_VIEW;

		m_IsMask = false;
		m_MaskAnimation = -540.f;
	}
	
	// �f�X�g���N�^
	~Player() override {}

	void Init()override;	// ������

	void Update()override;	// �X�V

	void Draw()override;	// �`��

	// �v���C���[���}�X�N�����Ă��邩�ǂ���
	bool HasMask() const override
	{
		return m_IsMask;
	}

	// �v���C���[�����j�^�[�����Ă��邩�ǂ���
	bool HasMonitor() const override
	{
		return m_HasMonitor;
	}

	// �v���C���[�������Ă��邩�ǂ���
	bool IsActive() override { return m_IsActive; };

	// �ǂ��̕��������Ă��邩
	SubGameScene CurrentViewID() const override
	{
		return m_ViewID;
	}
	// ���j�^�[�V�[���J�ڂ��Ǘ�����֐�
	bool ControlMonitor() override;
	// �Q�[���V�[���J�ڂ��Ǘ�����֐�
	bool ControlGameScene() override;

	//�S�[���f���t���f�B�̃t���O���擾
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };

	// ���݂̃v���C���[���E���ƈ����̎��E�����r
	const bool CurrentViewID(const SubGameScene sceneId_) const override;

private:

	void OnMask();	// �}�X�N�̃A�j���[�V����

	template <class T1, class T2>
	void KeyPush(T1 button_, T2 view_);

	template <class T1, class T2>
	void ButtonPush(T1 button_, T2 view_);

private:
	bool m_IsMask;			// �}�X�N�����Ă邩�ǂ���
	float m_MaskAnimation;	// �}�X�N�̃A�j���[�V�����^�C�}�[
	bool m_HasGFreddySpown; // �S�[���f���t���f�B�̃t���O�������Ă��邩�ǂ���
	bool m_HasMonitor;		// ���j�^�[�����Ă��邩�ǂ���

	// ���E���̐���
	SubGameScene m_ViewID, TmpRoom, TmpMonitor;
};

#endif
