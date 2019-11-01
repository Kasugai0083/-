#include "Chica.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"

void Chica::Init()
{
	m_iFrameCount = 0;
	m_IsDeath	  = true;
	m_HasKill     = false;
	m_RoomId      = RoomID::SPAWN_ROOM;
}

void Chica::Update()
{
#pragma region �Q�Ɨp�ϐ�
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	if (pPlayer == nullptr) {

		return;
	}
#pragma endregion

	m_iFrameCount++;

	if (m_IsDeath == true && m_iFrameCount >= 2900) {

		m_iFrameCount = 0;
		m_IsDeath	  = false;
		m_RoomId	  = RoomID::SPAWN_ROOM;
	}

	if (m_IsDeath == true) { return; }
	// ����ł��炱����艺�̏����ɂ͂����Ȃ�

#pragma region �`�J�̈ړ�
	switch (m_RoomId)
	{
	case RoomID::SPAWN_ROOM:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId	  = RoomID::RIGHT_DUCT;
		}
		break;

	case RoomID::RIGHT_DUCT:

		if (m_iFrameCount >= 300) {

			m_iFrameCount = 0;
			m_RoomId	  = RoomID::RIGHT_ROOM;
		}
		break;
	default:
		break;
	}
#pragma endregion


	switch (m_RoomId)
	{
	case RoomID::RIGHT_DUCT:

		if (pPlayer->HasLight() == true) {

			m_iFrameCount = 0;
			m_IsDeath	  = true;
		}
		break;

	case RoomID::RIGHT_ROOM:

		if (pPlayer->HasMask() == true) {

			m_iFrameCount = 0;
			m_IsDeath	  = true;
		}

		if (m_iFrameCount >= 300) {
			// �Q�[���I�[�o�[����
			m_HasKill	 = true;
		}
		break;
	default:
		break;
	}
}

void Chica::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case RightScene:
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Chica.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex);
		break;
	default:
		break;
	}
}

void Chica::Draw()
{
	if (m_IsDeath == true) { return; }
	// ����ł��炱����艺�̏����ɂ͂����Ȃ�

	switch (m_RoomId)
	{
	case RoomID::SPAWN_ROOM:

		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}
		break;

	case RoomID::RIGHT_DUCT:

		if (GetCurrentSceneId() == SceneId::MonitorScene 
			&& MonitorFunc()->Get() == MonitorTransition::Id::Right_Duct) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChicaTex));
		}
		break;

	case RoomID::RIGHT_ROOM:

		if (GetCurrentSceneId() == SceneId::RightScene) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightChicaTex));
		}
		break;
	default:
		break;
	}
}