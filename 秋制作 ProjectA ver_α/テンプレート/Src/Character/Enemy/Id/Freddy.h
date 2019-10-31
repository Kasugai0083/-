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
	const CharacterID m_CharId = CharacterID::FREDDY;// �L����ID�萔

	RoomID m_RoomId;		// �ǂ��̕����ɂ��邩�ϐ�
	int    m_iFrameCount;	// �t���C���J�E���g�p�ϐ�
	bool   m_IsDeath;		// ����ł邩�ǂ��� True:����ł��� False:�����Ă���
	bool   m_HasKill;		// �E�������ǂ���   True:�E����     False:�E���ĂȂ�
};

#endif