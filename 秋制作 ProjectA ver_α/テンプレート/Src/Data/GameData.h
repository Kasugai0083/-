#ifndef GAMEDATA_H_
#define GAMEDATA_H_

/**
*	@file Botan.h
*	@author �t����
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

#include "Days/DayController.h"
#include "../Utility/SingletonTemplate.h"
#include "../Character/CharacterID.h"

class CSV;

enum class SubGameScene {
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

struct EnemyData {
	int m_SpownJudge;
	int m_MovementSpeed;
};

struct GameParam {
	float m_MeltRatio;
	int m_TimeMagnification;
};

class GameData : public Singleton<GameData> {

public:
	// �f�[�^�𑗐M����֐�(GameData �� Accesor �ɂ��Ȃ��ꍇ)
	void SendEnemyData(EnemyData* edata_, int i) { *edata_ = m_EData[i]; }
	void SendGameParam(GameParam* gameparam_) { *gameparam_ = m_GameParam; }
	// �Q�b�g�֐�
	EnemyData GetEnemyData(EnemyID enemyId_) const { return m_EData[static_cast<int>(enemyId_)]; }
	GameParam GetGameParam() const { return m_GameParam; }
	Days GetDays() const { return m_Days; }

	// �f�[�^���󂯎��֐�(GameData �� Accesor �ɂ���ꍇ)
	void SetEnemyData(EnemyData edata_, CharacterID charid_) { m_EData[charid_] = edata_; }
	void SetGameParam(GameParam param_) { m_GameParam = param_; }

	// �l��ǂݍ��ރ��\�b�h
	void LoadDay(Days day_);

	void LoadParam(GameParam param_);

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
