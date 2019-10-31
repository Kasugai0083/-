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

	~Puppet() override {}

	/*
		������
	*/
	void Init() override;

	/*
		����
	*/
	void Update() override;
	/*
		m_IsKill��Ԃ�
	*/
	bool HasKill()const override { return m_HasKill; }

	/*
		�����Ɍ��݂̃V�[��������
		�e�N�X�`���̃��[�h
	*/
	void LoadTex(SceneId id_)override;
	/*
		�`��
	*/
	void Draw() override;

private:
	const CharacterID m_CharId = CharacterID::PUPPET;// �L����ID�萔

	RoomID m_RoomId;		// �ǂ��̕����ɂ��邩�ϐ�
	int    m_iFrameCount;	// �t���C���J�E���g�p�ϐ�
	bool   m_IsDeath;		// ����ł邩�ǂ��� True:����ł��� False:�����Ă���
	bool   m_HasKill;		// �E�������ǂ���   True:�E����     False:�E���ĂȂ�
};

#endif