#ifndef BONNIE_H_
#define BONNIE_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�o�j�[(�G�l�~�[)�̃N���X
*/
class Ume : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Ume() :
		Enemy(RoomID::ROOM_WORK, 0)
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
	/*
		�f�X�g���N�^
	*/
	virtual ~Ume(){}
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
	virtual void LoadTex(SceneId id_) override;
	/*
	�`��
	*/
	virtual void Draw() override;


private:
	const CharacterID m_CharId = CharacterID::UME;// �L����ID�萔

};

#endif