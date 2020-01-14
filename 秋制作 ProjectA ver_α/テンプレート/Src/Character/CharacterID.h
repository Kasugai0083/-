#ifndef CHARACTERID_H_
#define CHARACTERID_H_

enum CharacterID {

	PLAYER,		// �v���C���[
	OHAGI,		// ����
	UME,		// �E
	SAKURA,		// ��
	RAN,		// ���ʂɂ��Č��Ō���
	BOTAN,		// �J��������߂��Ă����炽�܂ɂ�����
	MARGARET,	// �I���S�[��

	ENEMY_NUM = MARGARET,

	MAX_CHARACTER,
};

enum class EnemyID : int {
	
	OHAGI,		// ����
	UME,		// �E
	SAKURA,		// ��
	RAN,		// ���ʂɂ��Č��Ō���
	BOTAN,		// �J��������߂��Ă����炽�܂ɂ�����
	MARGARET,	// �I���S�[��

	MAX_ENEMY,
	
};

#endif
