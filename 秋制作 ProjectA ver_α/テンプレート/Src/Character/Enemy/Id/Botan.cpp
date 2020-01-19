#include "Botan.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"
#include <time.h>
#include <stdlib.h>

void Botan::Init()
{
	srand((unsigned)time(nullptr));
}

void Botan::Update()
{
	Probability Prob;
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());

#if 1
	if (m_pPlayer->HasGFreddySpown() == true) {
		if (GetKey(FIVE_KEY)) {
			m_IsActive = true;
		}
		m_SpawnJudgement = true;
	}
	else {
		m_SpawnJudgement = false;
	}
#endif

#if 0
	if (m_pPlayer->HasGFreddySpown() == true) {
		if (Prob.GetRandomValue(0, m_EnemyData.m_SpownJudge, 5)) { 
			m_IsActive = true; 
			m_RoomId   = RoomID::ROOM_PRAYER;
		}
		m_SpawnJudgement = true;
	}
	else {
		m_SpawnJudgement = false;
	}
#endif

	if (m_IsActive == false) { return; }
	// アクティブじゃなかったらここより下の処理にはいかない

	// ボタンの攻撃処理(仮)
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	if (pCenterCandle->HasCaLight() == true
		|| m_pPlayer->HasMonitor() == true) {

		m_CanKill = true;

		m_iFrameCount = 0;

		static bool once = false;
		if (!once)
		{
			pAudio->Play("BotanKillVoice");
			once = true;
		}
	}

	// もしプレイヤーがモニターを見たら
	// 死ぬ処理を入れる
	//
	///////////////////////
	
	// ボタンの死亡処理
	if (m_pPlayer->HasMask() == true 
		&& m_CanKill == false) {
		m_IsActive = false;
		m_RoomId   = RoomID::ROOM_VOID;
	}



	// キルアニメーションが終わったら殺す処理
	if (!m_CanKill && m_iFrameCount >= 120) {
		m_iFrameCount = 0;
		m_HasKill = true;
		m_CanKill = false;
	}
}

bool Botan::SpawnJudgement(double probability_)
{
	static double Probability = probability_; // 確率

	if ((double)rand() / RAND_MAX < Probability) {
		return true;
	}

	return false;
}

void Botan::LoadTex()
{
}

void Botan::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false) { return; }
	// 死んでいたらここより下の処理にはいかない

	if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW
		&& GetCurrentSceneId() == SceneId::GameScene) {

		DrawTexture(1360.0f, 540.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BOTAN_PLAYER_TEX));
	}
}

void Botan::KillAnimation()
{
	if (m_CanKill == true)
	{
		m_iFrameCount++;
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::BOTAN_KILLANIME_TEX));
		if (DrawBlood(0.f, 0.f) == true) { m_CanKill = false; }
	}
}
