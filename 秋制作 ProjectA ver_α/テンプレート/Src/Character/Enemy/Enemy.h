#ifndef ENEMY_H_
#define ENEMY_H_

#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "../../Scene/Scene.h"
#include <random>
#include "../Character.h"
#include "../../Engine/Graphics.h"


class Enemy : public Character
{
public:
	/*
		�R���X�g���N�^
	*/
	Enemy(RoomID roomId_, EnemyID enemyId_) :
		Character(false)
	{
		m_EnemyData.m_MovementSpeed = GameData::GetInstance()->GetEnemyData(enemyId_).m_MovementSpeed;
		m_EnemyData.m_SpownJudge = GameData::GetInstance()->GetEnemyData(enemyId_).m_SpownJudge;
		m_RoomId	  = roomId_;
		m_iFrameCount = 0;
		m_HasKill	  = false;
		m_CanKill	  = false;

		m_Color.r = 0.5f;
		m_Color.g = 0.f;
		m_Color.b = 0.f;
		m_Color.a = 0.f;

	}

	/*
		�f�X�g���N�^
	*/
	virtual ~Enemy() override{}

	/*
		������
	*/
	virtual void Init() override{}

	/*
		�X�V
	*/
	virtual void Update() override{}

	/*
		�G�l�~�[���v���C���[���E�������ǂ���
		m_HasKill��Ԃ�
	*/
	virtual bool HasKill()const override { return m_HasKill; }

	/*
		�����Ɏw�肵���V�[���̃e�N�X�`�������[�h����
	*/
	virtual void LoadTex()override {}

	virtual RoomID GetRoomID() const override{ return m_RoomId; }

	/*
		�G�l�~�[���v���C���[���E���邩�ǂ���
	*/
	virtual bool CanKill() const override { return m_CanKill; }

	protected:
	// �G�l�~�[�̈ړ��p�^�C�}�[�N���X(������)
	class EnemyTimer
	{
	public:
		/*
			�R���X�g���N�^
		*/
		EnemyTimer(int moveSpeed_) {

			m_Time = 0;
			m_MoveSpeed = moveSpeed_;
		}
		/*
			�f�X�g���N�^
		*/
		~EnemyTimer() {}

		/*
			�ړ��p�̃^�C�}�[�֐�
			����̎��ԂɂȂ��True���Ԃ�
		*/
		bool MoveTimer();

	private:
		int m_Time;
		int m_MoveSpeed;
	};

protected:
	RoomID     m_RoomId;			  // �ǂ��̕����ɂ��邩�ϐ�
	int	       m_iFrameCount;		  // �t���C���J�E���g�p�ϐ�
	bool       m_CanKill;			  // �E���邩�ǂ���	True:�E����@ False:�E���Ȃ�
	bool       m_HasKill;			  // �E�������ǂ��� True:�E����   False:�E���ĂȂ�
	AnimationTexture m_AnimationTex;  // �A�j���[�V�����p�e�N�X�`���ۑ��ϐ�
	EnemyData  m_EnemyData;			  // �G�̈ړ����x�ƃX�|�[���m�����ۑ�����Ă���ϐ�

	Character* m_pPlayer;			  // �v���C���[�̎Q�Ɨp�ϐ�

	D3DXCOLOR m_Color;				  // 1/20 �t�F�[�h�C�������̂��߂ɒǉ�
};

#endif