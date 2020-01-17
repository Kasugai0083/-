#ifndef SAKURA_H_
#define SAKURA_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�o�j�[(�G�l�~�[)�̃N���X
*/
class Sakura : public Enemy
{
public:
	/*
		�R���X�g���N�^
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
	/*
		�f�X�g���N�^
	*/
	virtual ~Sakura(){}
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
	virtual bool HasKill()const final { return m_HasKill; }
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
	const CharacterID m_CharId = CharacterID::SAKURA;// �L����ID�萔

};

#endif