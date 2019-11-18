#ifndef ENEMY_H_
#define ENEMY_H_
#include "../Character.h"
#include "../CharacterID.h"
#include "../../Utility/RoomID.h"
#include "..//..//Scene/Scene.h"
#include <random>


class Enemy : public Character {
public:
	virtual ~Enemy() override{}

	virtual bool HasKill()const override { return m_HasKill; }

	virtual void LoadTex(SceneId id_)override {}

protected:
	// �G�l�~�[�̈ړ��p�^�C�}�[�N���X
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
		~EnemyTimer();

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

private:
	CharacterID m_Id;
	
	RoomID m_RoomId;
	int	   m_iFrameCount;
	bool   m_IsDeath;
	bool   m_HasKill;
};

#endif