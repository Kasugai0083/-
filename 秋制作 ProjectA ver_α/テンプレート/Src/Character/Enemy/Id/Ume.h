#ifndef UME_H_
#define UME_H_

/**
*	@file	Ume.h
*	@author ���{
*	@brief	�L�����N�^�[�u�E���v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/**
* @brief	�G�l�~�[[�E��]���Ǘ�����N���X
* @details	�E���̋�����`����������Ă���
*/
class Ume : public Enemy
{
public:
	/**
	* @fn		Ume()
	* @brief	�R���X�g���N�^
	*/
	Ume() :
		Enemy(RoomID::ROOM_WORK, EnemyID::UME)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 60;
		m_AnimationTex.m_KillingCounter = 0.f;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Ume()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Ume(){}

	/**
	* @fn		void Init()
	* @brief	�������֐�
	*/
	virtual void Init() override;

	/**
	* @fn		void Init()
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
};

#endif