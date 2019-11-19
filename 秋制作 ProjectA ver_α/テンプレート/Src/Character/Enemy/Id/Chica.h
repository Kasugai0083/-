#ifndef CHICA_H_
#define CHICA_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�`�J(�G�l�~�[)�̃N���X
*/
class Chica : public Enemy
{
public:
	Chica();
	virtual ~Chica() final;
	/*
		������
	*/
	virtual void Init() final;

	/*
		����
	*/
	virtual void Update() final;
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
	virtual void Draw() final;

private:
	const CharacterID m_CharId = CharacterID::CHICA;// �L����ID�萔

};

#endif