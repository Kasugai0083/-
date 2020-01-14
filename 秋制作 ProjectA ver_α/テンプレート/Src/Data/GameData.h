#ifndef GAMEDATA_H_
#define GAMEDATA_H_

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

/**
* �G�l�~�[�̃X�|�[������p�x\n
* DAY�ɂ���Ē���
*/
const float D1_SPOWN_JUDGE_OHAGI = 1.0f;
const float D1_SPOWN_JUDGE_SAKURA = 1.0f;
const float D1_SPOWN_JUDGE_UME = 1.0f;
const float D1_SPOWN_JUDGE_RAN = 1.0f;
const float D1_SPOWN_JUDGE_BOTAN = 1.0f;

const float D2_SPOWN_JUDGE_OHAGI = 1.0f;
const float D2_SPOWN_JUDGE_SAKURA = 1.0f;
const float D2_SPOWN_JUDGE_UME = 1.0f;
const float D2_SPOWN_JUDGE_RAN = 1.0f;
const float D2_SPOWN_JUDGE_BOTAN = 1.0f;

const float D3_SPOWN_JUDGE_OHAGI = 1.0f;
const float D3_SPOWN_JUDGE_SAKURA = 1.0f;
const float D3_SPOWN_JUDGE_UME = 1.0f;
const float D3_SPOWN_JUDGE_RAN = 1.0f;
const float D3_SPOWN_JUDGE_BOTAN = 1.0f;

const float ED_SPOWN_JUDGE_OHAGI = 1.0f;
const float ED_SPOWN_JUDGE_SAKURA = 1.0f;
const float ED_SPOWN_JUDGE_UME = 1.0f;
const float ED_SPOWN_JUDGE_RAN = 1.0f;
const float ED_SPOWN_JUDGE_BOTAN = 1.0f;

/**
* �G�l�~�[�̈ړ����x\n
* �v�����i�[���������鍀��
*/
const int D1_MOVEMENT_SPEED_OHAGI = 300;
const int D1_MOVEMENT_SPEED_SAKURA = 300;
const int D1_MOVEMENT_SPEED_UME = 300;
const int D1_MOVEMENT_SPEED_RAN = 300;
const int D1_MOVEMENT_SPEED_BOTAN = 0;

const int D2_MOVEMENT_SPEED_OHAGI = 300;
const int D2_MOVEMENT_SPEED_SAKURA = 300;
const int D2_MOVEMENT_SPEED_UME = 300;
const int D2_MOVEMENT_SPEED_RAN = 300;
const int D2_MOVEMENT_SPEED_BOTAN = 0;

const int D3_MOVEMENT_SPEED_OHAGI = 300;
const int D3_MOVEMENT_SPEED_SAKURA = 300;
const int D3_MOVEMENT_SPEED_UME = 300;
const int D3_MOVEMENT_SPEED_RAN = 300;
const int D3_MOVEMENT_SPEED_BOTAN = 0;

const int ED_MOVEMENT_SPEED_OHAGI = 300;
const int ED_MOVEMENT_SPEED_SAKURA = 300;
const int ED_MOVEMENT_SPEED_UME = 300;
const int ED_MOVEMENT_SPEED_RAN = 300;
const int ED_MOVEMENT_SPEED_BOTAN = 0;

//! �X�C���n���鑬�x
const float MELT_RATIO = 0.001f; 

//! �����Ŏ��Ԃ̐i�݂�ύX
const int TIME_MAGNIFICATION = 1;

struct EnemyData {
	float m_SpownJudge;
	float m_MovementSpeed;
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

	// �f�[�^���󂯎��֐�(GameData �� Accesor �ɂ���ꍇ)
	void SetEnemyData(EnemyData edata_, CharacterID charid_) { m_EData[charid_] = edata_; }
	void SetGameParam(GameParam param_) { m_GameParam = param_; }

	// �l��ǂݍ��ރ��\�b�h
	void LoadDay(Days day_);

	void LoadParam(GameParam param_);


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