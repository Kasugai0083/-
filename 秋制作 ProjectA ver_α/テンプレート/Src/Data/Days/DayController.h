#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

/**
*	@file DayController.h
*	@author �t����
*	@brief ���t(��Փx)���Ǘ�����N���X������
*/


class Character;

enum class Days 
{
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

class DayController 
{
public:

	DayController();		// �R���X�g���N�^
	~DayController() {};	// �f�X�g���N�^

	// �Z�[�u�f�[�^�̓��t��ǂݍ���
	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };

	// �N���A�ς̏ꍇ������i�s������
	void CheckClear();

	// ���݂̓�������ʂɕ\��(�f�o�b�O�p)
	void DrawCurrentDays();

	Days GetCurrentDays() { return m_Days; };

private:
	Days m_Days;			// �������
	Character* m_pPlayer;	// �v���C���[�̃|�C���^
};

// �ȈՔŃV���O���g��
DayController* DayManager();

#endif 