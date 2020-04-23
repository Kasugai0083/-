/**
*	@file	Probability.h
*	@author	���{
*	@brief	�m�����o�����߂̃N���X������
*/

#ifndef PROBABILITY_H_
#define PROBABILITY_H_

/**
* @brief	�m�����o���N���X
* @details	�t�H�N�V�[�̋�����`����������Ă���
*/
class Probability
{
public:
	/**
	* @fn			bool GetRandomValue(int floor_, int ceil_, int val_)
	* @brief		����[floor_]�ȏ�[ceil_]�ȉ��̂Ȃ����烉���_���Ȓl������[val_]�ƈ�v������True��Ԃ��֐�
	* @param[in]	int(floor_)	����
	* @param[in]	int(ceil_)	�G�l�~�[��ID
	* @param[in]	int(val_)	�G�l�~�[��ID
	* @return		bool	
	*/
	bool GetRandomValue(int floor_, int ceil_, int val_);
};

#endif