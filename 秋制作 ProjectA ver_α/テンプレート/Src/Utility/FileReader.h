#ifndef FILEREADER_H_
#define FILEREADER_H_

#include "../Data/GameData.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>


class FileReader
{
public:
	bool LoadCSV(EnemyData* enemyData_, GameParam* gameParam_, Days* days_);

	/*
		CSV�ɓ��ɂ����������ފ֐�
		[fileName_] �t�@�C���̖��O
		[days_]     �������ޓ��ɂ�
	*/
	void WriteCSV(std::string fileName_, int days_);

private:
	EnemyData m_EData[6];
	GameParam m_GameParam;
	Days m_Days;
};

#endif