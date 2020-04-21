#ifndef MARGARET_H_
#define MARGARET_H_

/**
*	@file	Margaret.h
*	@author ���{
*	@brief	�L�����N�^�[�u�}�[�K���b�g�v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/EnemyTex.h"


/**
* @brief	�G�l�~�[[�}�[�K���b�g]���Ǘ�����N���X
* @details	�}�[�K���b�g�̋�����`����������Ă���
*/
class Margaret : public Enemy
{
public:
	/**
	* @fn		Margaret()
	* @brief	�R���X�g���N�^
	*/
	Margaret() :
		Enemy(RoomID::ROOM_CHILDREN, EnemyID::MARGARET)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_iFrameCount = 3600;
		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}

	/**
	* @fn		~Margaret()
	* @brief	�f�X�g���N�^
	*/
	virtual ~Margaret(){}

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

private:
	const int MAX_COUNT = 3600;

	int m_TextureCategory = EnemyCategoryTextureList::MARGARET_PIZA_9;
};

#endif