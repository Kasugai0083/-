#ifndef CHARACTER_H_
#define CHARACTER_H_

// �L�����N�^�[�̊�b�ƂȂ�N���X

#include "..//Scene/Scene.h"
#include "../Data/GameData.h"

class Character {
public:
	Character(bool is_active_)
	{
		m_IsActive = is_active_;
	}

	virtual ~Character(){}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual bool HasLight() const
	{
		return m_HasLight;
	}

	virtual bool HasMask() const {
		return m_HasMask;
	}

	virtual bool HasMonitor() const {
		return m_HasMonitor;
	}

	virtual bool HasKill() const{
		return m_HasKill;
	}
	virtual bool IsActive() { return m_IsActive; }

	virtual SubGameScene CurrentViewID() const{
		return m_ViewID;
	}
	virtual void Draw() = 0;

	virtual void LoadTex() {};

	virtual void KillAnimation() {}

	// 2019/12/05�ǉ�
	virtual bool ControlMonitor() { return 0; };
	virtual bool ControlGameScene() { return 0; };
	virtual bool HasGFreddySpown() { return 0; };

	// �����ɒǉ����܂��B
	virtual bool SpawnJudgement() const { return 0; }

	virtual const bool CurrentViewID(const SubGameScene sceneId_) const { return 0; }

	virtual RoomID GetRoomID() const {}

protected:
	bool m_IsActive;

private:
	//�v���C���[�̏��
	bool m_HasMask;
	bool m_HasLight;
	bool m_HasMonitor;
	SubGameScene m_ViewID;

	//�G�l�~�[�̏��
	bool m_HasKill;
};

#endif