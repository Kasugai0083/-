#ifndef PUPPET_H_
#define PUPPET_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�p�y�b�g(�G�l�~�[)�̃N���X
*/	
class Margaret : public Enemy
{
public:
	/*
		�R���X�g���N�^
	*/
	Margaret() :
		Enemy(RoomID::ROOM_CHILDREN, 0, false)
	{}
	/*
		�f�X�g���N�^�[
	*/
	virtual ~Margaret(){}

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

	/*
		�L���A�j���[�V����
	*/
	virtual void KillAnimation() override;

private:
	const CharacterID m_CharId = CharacterID::MARGARET;// �L����ID�萔
};

#endif