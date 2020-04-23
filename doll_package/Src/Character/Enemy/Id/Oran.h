#ifndef ORAN_H_
#define ORAN_H_

/**
*	@file	Oran.h
*	@author ���{
*	@brief	�L�����N�^�[�u�I�����v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Texture/Texture.h"

/**
* @brief	�G�l�~�[[�t�H�N�V�[]���Ǘ�����N���X
* @details	�t�H�N�V�[�̋�����`����������Ă���
*/
class Ran : public Enemy
{
public:
	/**
	* @fn		Ran()
	* @brief	�R���X�g���N�^
	*/
	Ran() :
		Enemy(RoomID::ROOM_STORAGE, EnemyID::RAN)
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
	* @fn		~Ran()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Ran(){}

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