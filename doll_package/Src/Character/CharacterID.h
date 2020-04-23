#ifndef CHARACTERID_H_
#define CHARACTERID_H_

/**
*	@file Botan.h
*	@author ���{
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

/** 
*	@enum       CharacterID
*	@brief      Character�̒萔
*/
enum CharacterID {
	PLAYER,	

	OHAGI,	
	UME,	
	SAKURA,	
	RAN,	
	BOTAN,	
	MARGARET,

	ENEMY_NUM = MARGARET,

	MAX_CHARACTER,
};

/**
*	@enum       EnemyID
*	@brief      Enemy�̒萔
*/
enum class EnemyID : int {
	OHAGI,	
	UME,	
	SAKURA,	
	RAN,	
	BOTAN,	
	MARGARET,

	MAX_ENEMY,
};

#endif