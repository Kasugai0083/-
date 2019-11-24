#ifndef ENEMYTEX_H_
#define ENEMYTEX_H_

#include "GameSceneTex.h"

enum EnemyCategoryTextureList
{
	FredyFarTex,	// �t���f�B(200*200)�̃e�N�X�`��
	FredyNearTex,	// �t���f�B(350*350)�̃e�N�X�`��

	EnemyBoonieTex,	// �e�X�g�p
	
	EnemyBonnieTex,	// �o�j�[(512*512)�̃e�N�X�`���[
	BonnieSpawnTex,	// �o�j�[(350*350)�̃e�N�X�`���[
	BonnieLookTex,	// �o�j�[(300*300)�̃e�N�X�`���[

	ChicaTex,
	ChicaSpawnTex,
	ChicaLookTex,

	RanTex,		// ����(512*512)�̃e�N�X�`��
	RanFarTex,	// ����(200*200)�̃e�N�X�`��
	RanNearTex,	// ����(350*350)�̃e�N�X�`��


	EnemyBotanTex,	// �{�^���e�N�X�`��

	EnemyTextureMax,
};

#define TEXTURE_CATEGORY_ENEMY (SceneId::EnemyScene)				//!< �Q�[���{�҃J�e�S���[

#endif