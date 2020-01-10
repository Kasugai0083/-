#pragma once

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
const float SPOWN_JUDGE_OHAGI = 1.0f;
const float SPOWN_JUDGE_SAKURA = 1.0f;
const float SPOWN_JUDGE_UME = 1.0f;
const float SPOWN_JUDGE_RAN = 1.0f;
const float SPOWN_JUDGE_BOTAN = 1.0f;

/**
* �G�l�~�[�̈ړ����x\n
* �v�����i�[���������鍀��
*/
const int MOVEMENT_SPEED_OHAGI = 300;
const int MOVEMENT_SPEED_SAKURA = 300;
const int MOVEMENT_SPEED_UME = 300;
const int MOVEMENT_SPEED_RAN = 300;
const int MOVEMENT_SPEED_BOTAN = 0;

//! �X�C���n���鑬�x
const float MELT_RATIO = 0.001f; 

//! �����Ŏ��Ԃ̐i�݂�ύX
const int TIME_MAGNIFICATION = 100000000;
