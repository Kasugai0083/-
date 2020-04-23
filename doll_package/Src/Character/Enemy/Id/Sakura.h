#ifndef SAKURA_H_
#define SAKURA_H_

/**
*	@file	Sakura.h
*	@author ���{
*	@brief	�L�����N�^�[�u�T�N���v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/**
* @brief	�G�l�~�[[�T�N��]���Ǘ�����N���X
* @details	�T�N���̋�����`����������Ă���
*/
class Sakura : public Enemy
{
public:
	/**
	* @fn		Sakura()
	* @brief	�R���X�g���N�^
	*/
	Sakura() :
		Enemy(RoomID::ROOM_WORK, EnemyID::SAKURA)
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
	* @fn		~Sakura()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Sakura(){}

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