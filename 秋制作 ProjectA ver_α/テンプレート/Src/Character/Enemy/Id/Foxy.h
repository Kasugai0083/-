#ifndef FOXY_H_
#define FOXY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"
#include "../../../Texture/Texture.h"

/*
	�t�H�N�V�[(�G�l�~�[)�̃N���X
*/
class Ran : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Ran() :
		Enemy(RoomID::ROOM_STORAGE, 0)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

	}
	/*
		�f�X�g���N�^
	*/
	virtual ~Ran(){}
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
	virtual void LoadTex(SceneId id_) final;
	/*
	�`��
	*/
	virtual void Draw() override;

	/*
		�L���A�j���[�V����
	*/
	virtual void KillAnimation() override;

private:
	// �L����ID�萔
	const CharacterID m_CharId = CharacterID::RAN;
	
	// �A�j���[�V����
	Texture* KillAnimationTex[3];
};

#endif 