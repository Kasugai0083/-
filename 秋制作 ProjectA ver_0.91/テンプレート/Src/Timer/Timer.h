#ifndef TIMER_H_
#define TIMER_H_

class Timer {
public:
	enum Id {
		Scene,
		Clear,
		MusicBox,

		//����Ȃ�����
		Enemy,
	};

	struct TIMERS {
		int m_Scene;
		int m_Clear;
		int m_MusicBox;

		//����Ȃ�����
		int m_Enemy;
	};

	void Init();
	int Get(Id id);
	void Set(int val, Id id);
	void Update(Id id);
	void CountDown(Id id);
private:
	TIMERS Timers;
};

Timer* TimerFunc();

#endif