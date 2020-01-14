#include "DayController.h"
#include "..//..//Engine/Graphics.h"
#include <string>
#include "../../Character/CharacterManager.h"


DayController::DayController() {
	m_Days = Days::DAY_1;
	m_pPlayer = g_Manager.GetCharacter(PLAYER);
};


DayController* DayManager() {
	static DayController Days;
	return &Days;
}

void DayController::DrawCurrentDays() {

	std::string debug;

	debug = std::to_string(static_cast<int>(m_Days));

	DrawFont(100.f, 100.f, debug.c_str(), Large, Yellow);
}

void DayController::CheckClear() {
	// �N���A�t���O���ǂ����łƂ���DAY��i�s����

	//bool check = true;
	bool check = m_pPlayer->IsActive();

	if (check != true) {
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
			break;
		default:
			break;
		}
	}
	else if (check == false) {

	}

};