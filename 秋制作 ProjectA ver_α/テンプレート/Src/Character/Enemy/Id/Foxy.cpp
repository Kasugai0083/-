#include "Foxy.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Object/ObjectManager.h"

void Ran::Init()
{
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/1_.png", m_AnimationTex.m_TextureData[0]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/2_.png", m_AnimationTex.m_TextureData[1]);
	CreateTexture("Res/Game/Enemy/Ran/KillAnimation/3_.png", m_AnimationTex.m_TextureData[2]);
}

void Ran::Update()
{
	m_iFrameCount++;
	
	//�ǉ����I
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	if (m_IsActive == false && m_iFrameCount >= 3000) {

		m_iFrameCount = 0;
		m_IsActive    = true;
	}

	if (m_IsActive == false) { return; }
	// ����ł��炱����艺�̏����ɂ͂����Ȃ�

#pragma region �t�H�N�V�[�̈ړ�
	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_BACK;
		}
		break;

	case RoomID::HALL_BACK:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId = RoomID::HALL_FRONT;
		}
		break;

	case RoomID::HALL_FRONT:
		if (m_iFrameCount >= 300) {

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
		//�����ς������I//

		if (pCenterCandle->HasCaLight() == true) {

			m_iFrameCount = 0;
		}
		break;
		//�����ς������I//


	case RoomID::ROOM_PRAYER:
	{
		m_CanKill = true;

		// �L���A�j���[�V�������I�������E������
		if (m_AnimationTex.m_Counter >= 2) {
			m_iFrameCount = 0;
			m_HasKill = true;
			m_CanKill = false;
		}
	}
		break;
	default:
		break;
	}
}

void Ran::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case GameScene:
		LoadTexture("Res/Game/Enemy/Ran/Ran.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanTex);
		LoadTexture("Res/Game/Enemy/Ran/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		LoadTexture("Res/Game/Enemy/Ran/Ran_Far.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanFarTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Ran/Ran_Near.png", TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex);
		break;
	default:
		break;
	}
}

void Ran::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex));
		}

		return;
	}

	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);

	switch (m_RoomId)
	{
	case RoomID::ROOM_STORAGE:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {

			DrawTexture(840.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanNearTex));
		}
		break;

	case RoomID::HALL_BACK:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene
				&& pCenterCandle->HasCaLight() == true) {

			DrawTexture(650.0f, 340.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanFarTex));
		}
		break;

	case RoomID::HALL_FRONT:

		if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER
			&& GetCurrentSceneId() == SceneId::GameScene) {

			DrawTexture(750.0f, 500.0f, GetTexture(TEXTURE_CATEGORY_ENEMY, EnemyCategoryTextureList::RanTex));
		}
		break;
	default:
		break;
	}

	if (m_CanKill == true)
	{
		DrawAnimation(0.0f, 0.0f, &m_AnimationTex);
	}
}
