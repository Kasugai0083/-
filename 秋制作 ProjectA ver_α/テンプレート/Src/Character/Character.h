#ifndef CHARACTER_H_
#define CHARACTER_H_

/**
*	@file	Character.h
*	@author ���{
*	@brief	�L�����N�^�[�̊��N���X
*/

#include "..//Scene/Scene.h"
#include "../Data/GameData.h"
#include "../Utility/RoomID.h"

/**
* @brief �L�����N�^�[�̊��N���X
* @details ���̃N���X����v���C���[��G�l�~�[�ɔh�����Ă���
*/
class Character {
public:
	/**
	* @fn		�@	Character(bool is_active_
	* @brief		�R���X�g���N�^
	* @param[in]	is_active_(������) �L�����N�^�[���A�N�e�B�u��Ԃ�
	*/
	Character(bool is_active_)
	{
		m_IsActive = is_active_;
	}

	/**
	* @fn		�@	~Character()
	* @brief		�f�X�g���N�^
	*/
	virtual ~Character(){}

	/**
	* @fn			bool IsActive()
	* @brief		�L�����N�^�[���A�N�e�B�u���ǂ����𒲂ׂ�֐�
	* @return		bool true : �A�N�e�B�u	false : ��A�N�e�B�u
	*/
	virtual bool IsActive() { return m_IsActive; }

	/**
	* @fn void Init()
	* @brief �L�����N�^�[�̏������֐�
	*/
	virtual void Init() = 0;

	/**
	* @fn void Update()
	* @brief �L�����N�^�[�̍X�V�֐�
	*/
	virtual void Update() = 0;

	/**
	* @fn		void Draw()
	* @brief	�L�����N�^�[�̕`��֐�
	*/
	virtual void Draw() = 0;

	/**
	* @fn HasMask
	* @brief �v���C���[���}�X�N�����Ă��邩�ǂ���
	*/
	virtual bool HasMask() const {
		return m_HasMask;
	}

	/**
	* @fn HasMonitor
	* @brief �v���C���[�����j�^�[�����Ă��邩�ǂ���
	*/
	virtual bool HasMonitor() const {
		return m_HasMonitor;
	}

	/**
	* @fn CurrentViewID
	* @brief �ǂ��̕��������Ă��邩
	*/
	virtual SubGameScene CurrentViewID() const {
		return m_ViewID;
	}

	/**
	* @fn		bool HasKill()
	* @brief	�v���C���[���E�������ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���ĂȂ�
	*/
	virtual bool HasKill() const{
		return m_HasKill;
	}

	/**
	* @fn		bool CanKill()
	* @brief	�G�l�~�[���v���C���[���E�����Ԃ��ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���Ȃ�
	*/
	virtual bool CanKill() const { 
		return false; 
	}

	/**
	* @fn		RoomID GetRoomID()
	* @brief	�G�l�~�[���镔����Ԃ��֐�
	* @return	RoomID �G�l�~�[���镔�����Ԃ�
	*/
	virtual RoomID GetRoomID() const { 
		return RoomID::ROOM_VOID; 
	}

	/**
	* @fn		void KillAnimation()
	* @brief	�L���A�j���[�V�����̕`��֐�
	*/
	virtual void KillAnimation() {}

	// 2019/12/05�ǉ�
	virtual bool ControlMonitor()	{ return 0; }
	virtual bool ControlGameScene() { return 0; }
	virtual bool HasGFreddySpown()	{ return 0; }

	/**
	* @fn CurrentViewID
	* @brief ���݂̃v���C���[���E���ƈ����̎��E�����r
	*/
	virtual const bool CurrentViewID(const SubGameScene sceneId_) const { return 0; }

	/**
	* @fn		bool SpawnJudgement() const
	* @brief	m_SpawnJudgement��Ԃ�
	* @return	bool
	*/
	virtual bool SpawnJudgement() const { return 0; }


protected:
	bool m_IsActive;		//! �L�����N�^�[���A�N�e�B�u���ǂ�����ۑ�����ϐ�

private:
	//! �v���C���[�̏��
	bool m_HasMask;			/** @brief �}�X�N�����Ă邩�ǂ��� */
	bool m_HasMonitor;		/** @brief ���j�^�[�����Ă��邩�ǂ��� */
	SubGameScene m_ViewID;	/** @brief ���E���̐��� */

	bool m_HasKill;			//! �E�������ǂ���
};

#endif