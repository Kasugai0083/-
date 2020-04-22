#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

/**
*	@file	CharacterManager.h
*	@author ���{
*	@brief	�L�����N�^�[���Ǘ�����N���X������
*/


#include "Character.h"
#include "CharacterID.h"
#include "../Utility/RoomID.h"

/**
* @brief	�L�����N�^�[�}�l�[�W���[�N���X
* @details	�L�����N�^�[�S�̂��Ǘ�����N���X
*/
class CharacterManager {

public:
	/**
	* @fn		CharacterManager()
	* @brief	�R���X�g���N�^
	*/
	CharacterManager();

	/**
	* @fn		~CharacterManager()
	* @brief	�f�X�g���N�^
	*/
	~CharacterManager();

	/**
	* @fn		void Initialize()
	* @brief	�L�����N�^�[�S�̂����������邽�߂̊֐�
	*/
	void Initialize();

	/**
	* @fn		void Update()
	* @brief	�L�����N�^�[�S�̂��X�V���邽�߂̊֐�
	*/
	void Update();

	/**
	* @fn		void Draw()
	* @brief	�L�����N�^�[�S�̂�`�悷�邽�߂̊֐�
	*/
	void Draw();

	/**
	* @fn			Character* GetCharacter(int id)
	* @brief		�L�����N�^�[�̃C���X�^���X���擾����֐�
	* @param[in]	int(id_)	�~�����L�����N�^�[��ID
	*/
	Character* GetCharacter(int id_) {
		return m_Charas[id_];
	}

	/*
		m_Charas�ϐ���delete����֐�
		ClearScene�ň�x�����s��

		�܂��̓Q�[�����I�������Ƃ��ɍs����
	*/

	/**
	* @fn		void Release()
	* @brief	�L�����N�^�[���������֐�
	*/
	void Release();

	/**
	* @fn		void Draw()
	* @brief	�G�l�~�[�̃L���A�j���[�V�����֐�
	*/
	void KillAnimation();

	/*
		�G�l�~�[���v���C���[���E�������ǂ�����Ԃ��֐�
	*/

	/**
	* @fn		bool HasKill()
	* @brief	�G�l�~�[���v���C���[���E�������ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���ĂȂ�
	*/
	bool HasKill();

	/**
	* @fn		const bool CanKill() const
	* @brief	�G�l�~�[���v���C���[���E�����Ԃ��ǂ�����Ԃ��֐�
	* @return	bool true : �E����	false : �E���Ȃ�
	*/
	const bool CanKill() const;

	/**
	* @fn		void CreateCharacter()
	* @brief	�L�����N�^�[���쐬�֐�
c
	*/
	void CreateCharacter();

	/*
		�����̕����ɓG�����邩�ǂ���
		[roomId_] -> RoomID
	*/

	/**
	* @fn			bool IsSameRoom(RoomID roomId_)
	* @brief		�����̕����ɓG�����邩�ǂ����𒲂ׂ�֐�
	* @param[in]	int(id_)	������ID
	* @return		bool true : ����	false : ���Ȃ�
	*/
	bool IsSameRoom(RoomID roomId_);

private:

	Character* m_Charas[8];	//! �L�����N�^�[�̃C���X�^���X��ۑ�����|�C���^�ϐ�
};

extern CharacterManager g_Manager;

#endif