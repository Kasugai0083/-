#include "Oran.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../..//..//Data/GameData.h"
#include "../../../Object/ObjectManager.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Audio/Audio.h"
#include "../../../Utility/Probability.h"

void Ran::Init()
{
}

void Ran::Update()
{
	Probability Prob;
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	m_iFrameCount++;
	
	//�ǉ����I
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

#if 1
	if (GetKeyDown(FOUR_KEY)) {

		m_iFrameCount = 0;
		m_IsActive = true;
		m_RoomId = RoomID::ROOM_STORAGE;
	}
#endif

#if 0
	if (m_IsActive == false && m_iFrameCount >= 100) {
		if (Prob.GetRandomValue(0, m_EnemyData.m_SpownJudge, 5) == false) { 
			m_iFrameCount = 0;
			return; 
		}

		m_iFrameCount = 0;
		m_IsActive    = true;
		m_RoomId = RoomID::ROOM_STORAGE;
	}
#endif

	if (m_IsActive == false) { return; }
	// ����ł��炱����艺�̏����ɂ͂����Ȃ�

#pragma region �t�H�N�V�[�̈ړ�
	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(HALL_BACK) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_BACK;
		}
		break;

	case RoomID::HALL_BACK:

		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed){
			if (g_Manager.IsSameRoom(HALL_FRONT) == true) {
				m_iFrameCount = 0;
					break;
			}
			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_FRONT;
		}
		break;

	case RoomID::HALL_FRONT:
		if (m_iFrameCount >= m_EnemyData.m_MovementSpeed) {
			if (g_Manager.IsSameRoom(ROOM_LEFT_PRAYER) == true
				|| g_Manager.IsSameRoom(ROOM_RIGHT_PRAYER) == true) {
				m_iFrameCount = 0;
				break;
			}

			m_iFrameCount = 0;
			m_RoomId = RoomID::ROOM_PRAYER;
		}
		break;
	}
#pragma endregion

	switch (m_RoomId)
	{
	case RoomID::HALL_BACK:
	case RoomID::HALL_FRONT:
	{
		//�����ς������I//
		static int ActiveTimer = 0;
		if (pCenterCandle->HasCaLight() == true) {

			m_iFrameCount = 0;
		}
		if (ActiveTimer >= 700) {

			m_IsActive = false;
			ActiveTimer = 0;
			m_RoomId = RoomID::ROOM_STORAGE;
		}
		ActiveTimer++;

		break;
		//�����ς������I//
	}

	case RoomID::ROOM_PRAYER:
	{
	// �L���A�j���[�V�������I�������E������
	if (m_CanKill && m_Color.a >= 1.5f) {
		m_iFrameCount = 0;
		m_HasKill = true;
		//m_CanKill = false;
	}

	m_CanKill = true;
	m_Color.a += 0.01f;

	static bool once = false;
		if (!once)
		{
			pAudio->Play("OranKillVoice");
			once = true;
		}

	}
		break;
	default:
		break;
	}
}

void Ran::LoadTex()
{
}

void Ran::Draw()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (m_IsActive == false)
	{
		if (pPlayer->CurrentViewID(SubGameScene::STORE_ROOM_VIEW)) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX));
		}

		return;
	}

	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (pPlayer->CurrentViewID(SubGameScene::STORE_ROOM_VIEW)) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_SPAWN_TEX));
		}
		break;

	case RoomID::HALL_BACK:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(650.0f, 340.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_FAR_TEX));
		}
		break;

	case RoomID::HALL_FRONT:

		if (pPlayer->CurrentViewID(SubGameScene::CENTER_VIEW)
				&& pCenterCandle->HasCaLight() == true) {
				
			DrawTexture(880.0f, 550.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_NEAR_TEX));
		}
		break;
	default:
		break;
	}
}

void Ran::KillAnimation()
{
	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::ORAN_KILLANIME_TEX));
		DrawFade(false, m_Color);
		//if (DrawBlood(0.f, 0.f) == true) { m_CanKill = false; }
	}
}
