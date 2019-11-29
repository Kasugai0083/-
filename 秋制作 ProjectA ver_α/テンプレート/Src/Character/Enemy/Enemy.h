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
	Enemy(RoomID roomid_, int framecount_):
		Character(false)
	{
		m_RoomId	  = roomid_; 
		m_iFrameCount = framecount_;
		m_HasKill	  = false;
		m_CanKill	  = false;
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
	virtual void LoadTex(SceneId id_)override {}


protected:
	// �G�l�~�[�̈ړ��p�^�C�}�[�N���X(������)
	class EnemyTimer
	{
	public:
		/*
			�R���X�g���N�^
		*/
		EnemyTimer(int time_, int min_time_, int max_time) {

			m_Time = time_;
			m_RandTime = GetRand(min_time_, max_time);
		}
		/*
			�f�X�g���N�^
		*/
		~EnemyTimer(){}

		unsigned int GetRand(unsigned int min_val_, unsigned int max_val_);

		/*
			�X�|�[���p�̃^�C�}�[�֐�
			����̎��ԂɂȂ��True���Ԃ�
		*/
		bool SpawnTimer(Enemy& enemy_);

		/*
			�ړ��p�̃^�C�}�[�֐�
			����̎��ԂɂȂ��True���Ԃ�
		*/
		bool MoveTimer(Enemy& enemy_);

	protected:
		int m_Time;
		int m_RandTime;
	};

protected:
	RoomID     m_RoomId;				// �ǂ��̕����ɂ��邩�ϐ�
	int	       m_iFrameCount;			// �t���C���J�E���g�p�ϐ�
	bool       m_CanKill;				// �E���邩�ǂ���	True:�E����		False:�E���Ȃ�
	bool       m_HasKill;				// �E�������ǂ���   True:�E����     False:�E���ĂȂ�
	AnimationTexture m_AnimationTex;

	Character* m_pPlayer;			// �v���C���[�̎Q�Ɨp�ϐ�
};

#endif