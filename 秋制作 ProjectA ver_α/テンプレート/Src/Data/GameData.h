#ifndef GAMEDATA_H_
#define GAMEDATA_H_

/**
*	@file GameData.h
*	@author �t����
*	@brief �O���t�@�C������ǂݍ���ł����l���Ǘ�����N���X������
*/

#include "Days/DayController.h"
#include "../Utility/SingletonTemplate.h"
#include "../Character/CharacterID.h"

class CSV;

enum class SubGameScene
{
	CENTER_VIEW,			//�v���C���[���[������
	LEFT_VIEW,				//�v���C���[���[����
	RIGHT_VIEW,				//�v���C���[���[���E
	WORKSHOP_VIEW,			//�H�[
	STORE_ROOM_VIEW,		//���u
	RECEPTION_ROOM_VIEW,	//�q��
	CHILD_ROOM_VIEW,		//�q������
	RIGHT_CORRIDOR_VIEW,	//�E�L��
	LEFT_CORRIDOR_VIEW,		//���L��
};

struct EnemyData
{
	int m_SpownJudge;		// �G�l�~�[�̏o���p�x
	int m_MovementSpeed;	// �G�l�~�[�̈ړ�����
};

struct GameParam 
{
	float m_MeltRatio;		// �X�C�̗Z�𑬓x
	int m_TimeMagnification;// �X�e�[�W�N���A�̎���
};

class GameData : public Singleton<GameData> 
{

public:

	EnemyData GetEnemyData(EnemyID enemyId_) const { return m_EData[static_cast<int>(enemyId_)]; }
	GameParam GetGameParam() const { return m_GameParam; }
	Days GetDays() const { return m_Days; }

	// �w���CSV����l�̔����o��
	void LoadGameData();

private:
	EnemyData m_EData[6];
	GameParam m_GameParam;
	Days m_Days;
private:
	friend Singleton<GameData>;

	GameData() {};
	virtual ~GameData() {};

	//�R�s�[�R���X�g���N�^�̋֎~
	GameData(const GameData&) = delete;
	GameData& operator=(const GameData&) = delete;
	//���[�u�R���X�g���N�^�̋֎~
	GameData(const GameData&&) = delete;
	GameData& operator=(const GameData&&) = delete;
};

#endif
