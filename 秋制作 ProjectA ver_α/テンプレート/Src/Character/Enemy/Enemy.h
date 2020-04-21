#ifndef ENEMY_H_
#define ENEMY_H_

/**
*	@file	Enemy.h
*	@author ���{
*	@brief	�G�l�~�[���Ǘ�����N���X������
*/


#include <random>
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "../../Scene/Scene.h"
#include "../Character.h"
#include "../../Engine/Graphics.h"


/**
* @brief	�L�����N�^�[�̎q�N���X
* @details	���̃N���X���炻�ꂼ��̃G�l�~�[�ɔh��������
*/
class Enemy : public Character
{
public:
	/**
	* @fn			Enemy(RoomID roomId_, EnemyID enemyId_)
	* @brief		�G�l�~�[�̏��������s���R���X�g���N�^
	* @param[in]	RoomID(roomId_)	�G�l�~�[�̏o�����镔��
	* @param[in]	EnemyID(enemyId_)	�G�l�~�[��ID
	*/
	Enemy(RoomID roomId_, EnemyID enemyId_) :
		Character(false)
	{
		m_EnemyData.m_MovementSpeed = GameData::GetInstance()->GetEnemyData(enemyId_).m_MovementSpeed;
		m_EnemyData.m_SpownJudge	= GameData::GetInstance()->GetEnemyData(enemyId_).m_SpownJudge;
		m_RoomId	  = roomId_;
		m_iFrameCount = 0;
		m_HasKill	  = false;
		m_CanKill	  = false;

		m_Color.r = 0.5f;
		m_Color.g = 0.f;
		m_Color.b = 0.f;
		m_Color.a = 0.f;
	}

	/**
	* @fn		~Enemy()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Enemy() override{}

	/**
	* @fn		void Init()
	* @brief	�������֐�
	*/
	virtual void Init() override{}

	/**
	* @fn		void Init()
	* @brief	�X�V�֐�
	*/
	virtual void Update() override{}

	/**
	* @fn		RoomID GetRoomID()
	* @brief	�G�l�~�[���镔����Ԃ��֐�
	* @return	RoomID �G�l�~�[���镔�����Ԃ�
	*/
	RoomID GetRoomID() const override{ return m_RoomId; }

	/**
	* @fn		bool HasKill()
	* @brief	�v���C���[���E�������ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���ĂȂ�
	*/
	bool HasKill()const override { return m_HasKill; }

	/**
	* @fn		bool CanKill()
	* @brief	�G�l�~�[���v���C���[���E�����Ԃ��ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���Ȃ�
	*/
	bool CanKill() const override { return m_CanKill; }



protected:
	RoomID     m_RoomId;			  //! �ǂ̕����ɂ��邩��ۑ�����ϐ�
	int	       m_iFrameCount;		  //! �t���C���J�E���g�p�ϐ�
	bool       m_CanKill;			  //! �v���C���[���E���邩�ǂ���
	bool       m_HasKill;			  //! �E�������ǂ���
	EnemyData  m_EnemyData;			  //! �G�̈ړ����x�ƃX�|�[���m�����ۑ�����Ă���ϐ�
	AnimationTexture m_AnimationTex;  //! �A�j���[�V�����p�e�N�X�`���ۑ��ϐ�

	Character* m_pPlayer;			  //! �v���C���[�̎Q�Ɨp�ϐ�

	D3DXCOLOR m_Color;				  //! �t�F�[�h�C�������̂��߂̕ϐ�
};

#endif