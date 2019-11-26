#ifndef CHARACTER_H_
#define CHARACTER_H_

// �L�����N�^�[�̊�b�ƂȂ�N���X

#include "..//Scene/Scene.h"

class Character {
public:
	Character(bool is_active_)
	{
		m_IsActive = is_active_;
	}

	virtual ~Character(){}

	virtual void Init() = 0;

	virtual void Update() = 0;

	virtual bool HasLight()
	{
		return m_HasLight;
	}

	virtual bool HasMask() {
		return m_HasMask;
	}

	virtual bool HasMonitor() {
		return m_HasMonitor;
	}

	virtual bool HasKill() const{
		return m_HasKill;
	}
	virtual bool IsDeath() { return m_IsActive; }
	virtual void Draw() = 0;

	virtual void LoadTex(SceneId id) {};

protected:
	bool m_IsActive;

private:
	//�v���C���[�̏��
	bool m_HasMask;
	bool m_HasLight;
	bool m_HasMonitor;

	//�G�l�~�[�̏��
	bool m_HasKill;
};

#endif