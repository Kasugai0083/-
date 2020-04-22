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

#if 1
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
	// �A�N�e�B�u����Ȃ������炱����艺�̏����ɂ͂����Ȃ�
	static bool once = false;
	// �{�^���̍U������(��)
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	if (pCenterCandle->HasCaLight() == true
		|| m_pPlayer->HasMonitor() == true) {

		m_CanKill = true;
		m_iFrameCount = 0;

		if (!once)
		{
			pAudio->Play("BotanKillVoice", 0);
			once = true;
		}
	}

	// �����v���C���[�����j�^�[��������
	// ���ʏ���������
	//
	///////////////////////
	if (m_CanKill){ m_Color.a += 0.01f; }
	
	// �{�^���̎��S����
	if (m_pPlayer->HasMask() == true 
		&& m_pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW
		&& m_CanKill == false) {
		m_IsActive = false;
		m_RoomId   = RoomID::ROOM_VOID;
	}


	// �L���A�j���[�V�������I�������E������
	if (m_CanKill && m_Color.a >= 1.4f) {
		m_iFrameCount = 0;
		m_HasKill = true;
		once = false;
		m_IsActive = false;
	//	m_CanKill = false;
	}
}

void Botan::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false) { return; }
	// ����ł����炱����艺�̏����ɂ͂����Ȃ�

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
		DrawFade(false, m_Color);
	}
}
