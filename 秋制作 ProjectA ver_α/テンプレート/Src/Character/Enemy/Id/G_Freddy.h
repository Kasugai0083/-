#ifndef G_FREDDY_H_
#define G_FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�S�[���f���t���f�B(�G�l�~�[)�̃N���X
*/
class Botan : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Botan() :
		Enemy(RoomID::ROOM_PRAYER,0, false)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}
	}
	/*
		�f�X�g���N�^�[
	*/
	virtual ~Botan(){}
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
	virtual void LoadTex(SceneId id_) override;
	/*
	�`��
	*/
	virtual void Draw() override;

private:
	const CharacterID m_CharId = CharacterID::BOTAN;// �L����ID�萔
};

#endif