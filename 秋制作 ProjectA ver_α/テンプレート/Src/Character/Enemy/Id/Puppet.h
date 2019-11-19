#ifndef PUPPET_H_
#define PUPPET_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�p�y�b�g(�G�l�~�[)�̃N���X
*/	
class Puppet : public Enemy
{
public:
	Puppet(){}
	virtual ~Puppet() final {}

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
	const CharacterID m_CharId = CharacterID::PUPPET;// �L����ID�萔
};

#endif