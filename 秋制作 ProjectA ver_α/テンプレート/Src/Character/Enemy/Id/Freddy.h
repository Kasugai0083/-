#ifndef FREDDY_H_
#define FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�t���f�B(�G�l�~�[)�̃N���X
*/
class Freddy : public Enemy
{
public:
	Freddy();
	virtual ~Freddy() final;
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
	const CharacterID m_CharId = CharacterID::FREDDY;// �L����ID�萔
};

#endif