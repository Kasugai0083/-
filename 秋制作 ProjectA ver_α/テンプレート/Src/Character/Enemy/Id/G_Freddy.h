#ifndef G_FREDDY_H_
#define G_FREDDY_H_

#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"

/*
	�S�[���f���t���f�B(�G�l�~�[)�̃N���X
*/
class G_Freddy : public Enemy
{
public:
	G_Freddy();
	virtual ~G_Freddy() final;
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
	const CharacterID m_CharId = CharacterID::G_FREDDY;// �L����ID�萔
};

#endif