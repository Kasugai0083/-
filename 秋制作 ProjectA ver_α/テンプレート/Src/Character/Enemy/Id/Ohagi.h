#ifndef OHAGI_H_
#define OHAGI_H_

/**
*	@file Botan.h
*	@author ���{
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�t���f�B(�G�l�~�[)�̃N���X
*/
class Ohagi : public Enemy
{
public:
	/*
		�R���X�g���N�^
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
	/*
		�f�X�g���N�^
	*/
	virtual ~Ohagi(){}
	/*
		������
	*/
	virtual void Init() override;

	/*
		����
	*/
	virtual void Update() override;
	/*
		m_IsKill��Ԃ�
	*/
	virtual bool HasKill()const override { return m_HasKill; }

	/*
		�����Ɍ��݂̃V�[��������
		�e�N�X�`���̃��[�h
	*/
	virtual void LoadTex() override;
	/*
		�`��
	*/
	virtual void Draw() override;

	/*
		�L���A�j���[�V����
	*/
	virtual void KillAnimation() override;


private:
	const CharacterID m_CharId = CharacterID::OHAGI;// �L����ID�萔
};

#endif