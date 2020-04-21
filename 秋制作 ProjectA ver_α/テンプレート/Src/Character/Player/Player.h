#ifndef PLAYER_H_
#define PLAYER_H_

/**
*	@file Player.h
*	@author �t����
*	@brief �v���C���[���Ǘ�����N���X���`
*/

#include "../Character.h"
#include "../..//Data/GameData.h"

/**
* @class Player
* @brief �v���C���[�̏��𐧌�E�Ǘ�
*/
class Player : public Character 
{
	 
public:
	/** @brief �R���X�g���N�^ */
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
	
	~Player() override {}	/** @brief �f�X�g���N�^ */

	void Init()override;	/** @brief ������ */

	void Update()override;	/** @brief �X�V */

	void Draw()override;	/** @brief �`�� */

	/**
	* @fn HasMask
	* @brief �v���C���[���}�X�N�����Ă��邩�ǂ���
	*/
	bool HasMask() const override
	{
		return m_IsMask;
	}


	/**
	* @fn HasMonitor
	* @brief �v���C���[�����j�^�[�����Ă��邩�ǂ���
	*/
	bool HasMonitor() const override
	{
		return m_HasMonitor;
	}

	/**
	* @fn IsActive
	* @brief �v���C���[�������Ă��邩�ǂ���
	*/
	bool IsActive() override { return m_IsActive; };

	/**
	* @fn CurrentViewID
	* @brief �ǂ��̕��������Ă��邩
	*/
	SubGameScene CurrentViewID() const override
	{
		return m_ViewID;
	}

	/**
	* @fn ControlMonitor
	* @brief ���j�^�[�V�[���J�ڂ��Ǘ�����֐�
	*/
	bool ControlMonitor() override;
	/**
	* @fn ControlGameScene
	* @brief �Q�[���V�[���J�ڂ��Ǘ�����֐�
	*/
	bool ControlGameScene() override;
	/**
	* @fn HasGFreddySpown
	* @brief �S�[���f���t���f�B�̃t���O���擾
	*/
	bool HasGFreddySpown() override { return m_HasGFreddySpown; };

	/**
	* @fn CurrentViewID
	* @brief ���݂̃v���C���[���E���ƈ����̎��E�����r
	*/ 
	const bool CurrentViewID(const SubGameScene sceneId_) const override;

private:
	/**
	* �N���X���Ŏg�p����֐�
	*/

	/**
	* @fn OnMask
	* @brief �}�X�N�̃A�j���[�V����
	*/
	void OnMask();

	/**
	* @fn KeyPush
	* @param[in] button_ �ǂ̃{�^����G�ꂽ��
	* @param[out] view_ �ǂ� ViewScene �Ɉړ����邩
	* @brief button_ �Ŏw�肵���{�^������͂��� view_ �Ŏw�肵�� ViewScene �ɑJ��
	*/
	template <class T1, class T2>
	void KeyPush(T1 button_, T2 view_);

	/**
	* @fn ButtonPush
	* @param[in] button_ �ǂ̃{�^����G�ꂽ��
	* @param[out] view_ �ǂ� MonitorView �Ɉړ����邩
	* @brief button_ �Ŏw�肵���{�^������͂��� view_ �Ŏw�肵�� MonitorView �ɑJ��
	*/
	template <class T1, class T2>
	void ButtonPush(T1 button_, T2 view_);

private:
	bool m_IsMask;			/** @brief �}�X�N�����Ă邩�ǂ��� */
	float m_MaskAnimation;	/** @brief �}�X�N�̃A�j���[�V�����^�C�}�[ */
	bool m_HasGFreddySpown;	/** @brief �S�[���f���t���f�B�̃t���O�������Ă��邩�ǂ��� */
	bool m_HasMonitor;		/** @brief ���j�^�[�����Ă��邩�ǂ��� */

	/** @brief ���E���̐��� */
	SubGameScene m_ViewID, TmpRoom, TmpMonitor;
};

#endif
