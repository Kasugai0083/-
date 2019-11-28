#ifndef PUPPET_H_
#define PUPPET_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

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
		Enemy(RoomID::ROOM_CHILDREN, 1000, false)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}
	}
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
	const int MAX_COUNT = 300;
};

#endif