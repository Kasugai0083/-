/**
*	@file	FileReader.h
*	@author	���{
*	@brief	�Q�[���Ǘ��ɕK�v�ȃf�[�^�������Ă���CSV���Ǘ�����N���X������
*/


#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "../Data/GameData.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

/**
* @brief	FileReader�N���X
*/
class FileReader
{
public:
	/**
	* @fn			bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_)
	* @brief		�Q�[���ɕK�v�ȏ���CSV���甲����邽�߂̊֐�
	* @param[out]	EnemyData*(enemyData_)	�G�ɕK�v�ȏ������邽�߂�EnemyData�|�C���^
	* @param[out]	GameParam*(gameParam_)	�Q�[�����C���ɕK�v�ȃp�����[�^�[��ۑ����邽�߂�GameParam�|�C���^�[
	* @param[out]	Days*(days_)			���ɂ������邽�߂�Dayspointer�|�C���^�[
	* @return		bool					�ǂݍ��݂ɐ��� : true	�ǂݍ��݂Ɏ��s : false
	*/ 
	bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_);

	/**
	* @fn			void WriteCSV(std::string fileName_, int days_)
	* @brief		���݂̐i�s�xCSV�ɕۑ����邽�߂̊֐�
	* @param[in]	std::string(fileName_)	�������ރt�@�C���̖��O
	* @param[in]	int(days_)				���݂̓��ɂ�
	*/
	void WriteCSV(std::string fileName_, int days_);

};

#endif