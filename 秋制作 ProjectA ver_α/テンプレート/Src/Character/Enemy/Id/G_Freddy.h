#ifndef G_FREDDY_H_
#define G_FREDDY_H_

#include "../../Enemy/Enemy.h"
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
		Enemy(RoomID::ROOM_PRAYER, 0)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length = 3;
		m_AnimationTex.m_Speed = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
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
		�������邩���Ȃ����̔���֐�
		�v���C���[�����j�^�[�V�[���̎��Ɏg���B
		true�Ő�������
	*/
	bool SpawnJudgement(double probability_);

	// m_SpawnJudgement��Ԃ�
	bool SpawnJudgement() const override { return m_SpawnJudgement; }

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
	// �L����ID�萔
	const CharacterID m_CharId = CharacterID::BOTAN;

	// �����ɍ���Ă݂�
	// SpawnJudgement�֐����g�������ǂ���
	bool m_SpawnJudgement;
};

#endif