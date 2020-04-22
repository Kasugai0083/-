#ifndef OHAGI_H_
#define OHAGI_H_

/**
*	@file	Ohagi.h
*	@author ���{
*	@brief	�L�����N�^�[�u�I�n�M�v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/**
* @brief	�G�l�~�[[�I�n�M]���Ǘ�����N���X
* @details	�I�n�M�̋�����`����������Ă���
*/
class Ohagi : public Enemy
{
public:
	/**
	* @fn		Ohagi()
	* @brief	�R���X�g���N�^
	*/
	Ohagi() :
		Enemy(RoomID::ROOM_WORK, EnemyID::OHAGI)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length  = 3;
		m_AnimationTex.m_Speed   = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Ohagi()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Ohagi(){}

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