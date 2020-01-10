#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "Character.h"
#include "CharacterID.h"

// �L�����N�^�[�}�l�[�W���[�N���X
class CharacterManager {

public:
	/*
		�R���X�g���N�^
	*/
	CharacterManager();
	/*
		�f�X�g���N�^
	*/
	~CharacterManager();

	/*
		������
	*/
	void Initialize();

	/*
		�X�V
	*/
	void Update();

	/*
		�����Ɏw�肵��id�̃C���X�^���X�̃A�h���X��Ԃ�
	*/
	Character* GetCharacter(int id) {
		return m_Charas[id];
	}

	/*
		�`��
	*/
	void Draw();

	/*
		�e�N�X�`���̓ǂݍ��݊֐�
	*/
	void LoadTex();

	/*
		�L���A�j���[�V����
	*/
	void KillAnimation();


	bool RefKill();

private:
	void Release();

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif