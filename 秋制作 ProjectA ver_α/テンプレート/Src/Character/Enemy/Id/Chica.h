#ifndef CHICA_H_
#define CHICA_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	�`�J(�G�l�~�[)�̃N���X
*/
class Chica : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Chica() :
		Enemy(RoomID::ROOM_WORK, 0, false)
	{
	}
	/*
		�f�X�g���N�^
	*/
	virtual ~Chica(){}
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
	const CharacterID m_CharId = CharacterID::CHICA;// �L����ID�萔

};

#endif