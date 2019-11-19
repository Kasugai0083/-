#ifndef BONNIE_H_
#define BONNIE_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�o�j�[(�G�l�~�[)�̃N���X
*/
class Bonnie : public Enemy
{
public:
	Bonnie();
	virtual ~Bonnie() final;
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
	const CharacterID m_CharId = CharacterID::BONNIE;// �L����ID�萔

};

#endif