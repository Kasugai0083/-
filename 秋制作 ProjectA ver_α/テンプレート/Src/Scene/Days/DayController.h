#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_



enum class Days {
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

	ENDING
};

// �Ȃ�ƂȂ�������c�`�x�Ǘ��N���X
class DayController {
public:
	//���ɃR���X�g���N�^�ŏ�����
	DayController() { m_Days = Days::DAY_0; };
	~DayController() {};

	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	void CheckClear() {
		// �N���A�t���O���ǂ����łƂ���DAY��i�s����
		bool Clear = false;

		if (Clear == true) {
			switch (m_Days)
			{
			case Days::DAY_0:
				m_Days = Days::DAY_1;
				break;
			case Days::DAY_1:
				m_Days = Days::DAY_2;
				break;
			case Days::DAY_2:
				m_Days = Days::DAY_3;
				break;
			case Days::DAY_3:
				m_Days = Days::ENDING;
				break;
			default:
				break;
			}
		}
	};

	Days GetCurrentDays() { return m_Days; };

private:
	static Days m_Days;
};

#endif // ! DAY_CONTROLLER_H_
