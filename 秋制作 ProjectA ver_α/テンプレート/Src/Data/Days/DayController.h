#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

/**
*	@file Botan.h
*	@author �t����
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/


class Character;

enum class Days {
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

// �Ȃ�ƂȂ�������c�`�x�Ǘ��N���X
class DayController {
public:
	//���ɃR���X�g���N�^�ŏ�����
	DayController();
	~DayController() {};

	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	void CheckClear();

	Days GetCurrentDays() { return m_Days; };

	void DrawCurrentDays();

private:
	Days m_Days;
	Character* m_pPlayer;
};

DayController* DayManager();

#endif 