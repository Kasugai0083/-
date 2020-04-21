#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

/**
*	@file Botan.h
*	@author ���{
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/


#include "Character.h"
#include "CharacterID.h"
#include "../Utility/RoomID.h"

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
		m_Charas�ϐ���delete����֐�
		ClearScene�ň�x�����s��

		�܂��̓Q�[�����I�������Ƃ��ɍs����
	*/
	void Release();

	/*
		�e�N�X�`���̓ǂݍ��݊֐�
	*/
	void LoadTex();

	/*
		�L���A�j���[�V����
	*/
	void KillAnimation();

	/*
		�G�l�~�[���v���C���[���E�������ǂ�����Ԃ��֐�
	*/
	bool RefKill();

	/*
		�G�l�~�[���v���C���[���E���邩�ǂ���
	*/
	const bool CanKill() const;

	void CreateCharacter();

	/*
		�����̕����ɓG�����邩�ǂ���
		[roomId_] -> RoomID
	*/
	bool IsSameRoom(RoomID roomId_);

private:

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif