#ifndef TIMER_H_
#define TIMER_H_

class Timer {

	//�V���O���g���f�U�C���p�^�[��
public:

	//���̂����֐�
	static void CreateInstance() {
		if (IsNull() == true) {
			p_Instance = new Timer;
		}
	}

	//���̂�j������֐�
	static void DestroyInstance() {
		if (IsNull() == false) {
			delete p_Instance;
		}
	}

	//���̂����݂��邩�m�F����ϐ�
	static bool IsNull() {
		return p_Instance == nullptr;
	}

	//���̂��擾����֐�
	static Timer* GetInstance() {
		return p_Instance;
	}

public:
	//�{����肽���֐��Q

	enum Id {
		SCENE,
		CLEAR,
		MUSICBOX,
		MAX_TIMERS
	};

	struct TIMERS {
		int m_Scene;
		int m_Clear;
		int m_MusicBox;
	};

	void Init();
	void Init(Id id_);
	int GetTime(Id id_);

	void Draw();

	void Update();
	void Update(Id id_);

	void WindMusicBox();

private:
	Timer() {}	//�R���X�g���N�^�}��
	~Timer() {}	//�f�X�g���N�^�}��

private:
	static Timer* p_Instance;	//�������g�̗B��̎���
private:
	//�{���g�������ϐ��Q
	TIMERS Timers;

};



#endif