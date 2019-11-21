#ifndef FOXY_H_
#define FOXY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�t�H�N�V�[(�G�l�~�[)�̃N���X
*/
class Foxy : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Foxy() :
		Enemy(RoomID::ROOM_STORAGE, 0, false)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}
	}
	/*
		�f�X�g���N�^
	*/
	virtual ~Foxy(){}
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

private:
	const CharacterID m_CharId = CharacterID::FOXY;// �L����ID�萔
};

#endif 