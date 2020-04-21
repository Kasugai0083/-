#ifndef BOTAN_H_
#define BOTAN_H_

/**
*	@file Botan.h
*	@author ���{
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"


/**
* @brief	�G�l�~�[[�{�^��]���Ǘ�����N���X
* @details	�{�^���̋�����`����������Ă���
*/
class Botan : public Enemy
{
public:
	/**
	* @fn		Botan()
	* @brief	�R���X�g���N�^
	*/
	Botan() :
		Enemy(RoomID::ROOM_VOID, EnemyID::BOTAN)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Botan()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Botan(){}

	/**
	* @fn		void Init()
	* @brief	�������֐�
	*/
	virtual void Init() override;

	/**
	* @fn		void Update()
	* @brief	�X�V�֐�
	*/
	virtual void Update() override;

	/**
	* @fn		void Draw()
	* @brief	�`��֐�
	*/
	virtual void Draw() override;

	/**
	* @fn		void KillAnimation()
	* @brief	�L���A�j���[�V�����̕`��֐�
	*/
	virtual void KillAnimation() override;

	/**
	* @fn		bool SpawnJudgement() const
	* @brief	m_SpawnJudgement��Ԃ�
	* @return	bool
	*/
	bool SpawnJudgement() const override { return m_SpawnJudgement; }

private:

	bool m_SpawnJudgement;	//! �{�^�����X�|�[�����Ă��������ǂ�����ۑ�����ϐ�
};

#endif