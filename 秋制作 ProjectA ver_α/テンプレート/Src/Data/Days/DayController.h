#ifndef  DAY_CONTROLLER_H_
#define  DAY_CONTROLLER_H_

/**
*	@file DayController.h
*	@author �t����
*	@brief ���t(��Փx)���Ǘ�����N���X���`
*/

class Character;

/**
* @enum Days
* @brief ���t(��Փx)�̒i�K
*/
enum class Days 
{
	DAY_0,
	DAY_1,
	DAY_2,
	DAY_3,

};

/**
* @class DayController
* @brief ���t(��Փx)���Ǘ�����N���X
*/
class DayController 
{
public:

	DayController();		/** @brief �R���X�g���N�^ */
	~DayController() {};	/** @brief �f�X�g���N�^ */

	/**
	* @fn LoadDays
	* @param[in] savedata_ �w�肳�ꂽ�l�� m_Days �ɑ��
	* @brief �Z�[�u�f�[�^�̓��t��ǂݍ���
	*/
	void LoadDays(Days savedata_ = Days::DAY_0) { m_Days = savedata_; };


	/**
	* @fn CheckClear
	* @brief �N���A�ς̏ꍇ������i�s������
	*/
	void CheckClear();

	/**
	* @fn DrawCurrentDays
	* @brief ���݂̓�������ʂɕ\��(�f�o�b�O�p)
	*/
	void DrawCurrentDays();

	Days GetCurrentDays() { return m_Days; };

private:
	Days m_Days;			/** @brief ������� */
	Character* m_pPlayer;	/** @brief �v���C���[�̃|�C���^ */
};

DayController* DayManager();/** @brief �ȈՔŃV���O���g�� */

#endif 