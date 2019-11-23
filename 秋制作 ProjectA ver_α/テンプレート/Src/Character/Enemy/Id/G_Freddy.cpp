#include "G_Freddy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void Botan::Init()
{
	srand((unsigned)time(NULL));
}

void Botan::Update()
{
	if (m_pPlayer->HasMonitor() == true
		&& SpawnJudgement(0.1) == true) {

		m_IsDeath = false;
	}

	if (m_IsDeath == true) { return; }
	// ����ł����炱����艺�̏����ɂ͂����Ȃ�
	
	// �{�^���̍U������
	//if (m_pPlayer->HasLight() == true
	//	|| m_pPlayer->HasMonitor() == true) {
	//	m_HasKill = true;
	//}

	// �{�^���̍U������(��)
	if (m_pPlayer->HasLight() == true) {

		m_HasKill = true;
	}
	
	// �{�^���̎��S����
	if (m_pPlayer->HasMask() == true) {
		m_IsDeath = true;
	}
}

bool Botan::SpawnJudgement(double probability_)
{
	static double Probability = probability_; // �m��

	if ((double)rand() / RAND_MAX < Probability) {
		return true;
	}

	return false;
}


void Botan::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Botan.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBotanTex);
		break;
	default:
		break;
	}
}

void Botan::Draw()
{
	if (m_IsDeath == true) { return; }
	// ����ł����炱����艺�̏����ɂ͂����Ȃ�

	if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
		&& GetCurrentSceneId() == SceneId::GameScene) {

		DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::EnemyBotanTex));
	}
}
