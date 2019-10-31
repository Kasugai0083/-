#include "Puppet.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"

void Puppet::Init()
{
	m_iFrameCount = 0;
	m_IsDeath	  = true;
	m_HasKill	  = false;
	m_RoomId	  = RoomID::SPAWN_ROOM;
}

void Puppet::Update()
{
	m_iFrameCount++;

	if (m_IsDeath == true && TimerFunc()->Get(Timer::Id::MusicBox) >= 900) {

		m_iFrameCount = 0;
		m_IsDeath     = false;
	}

	if (m_IsDeath == true) { return; }
	// ����ł��炱����艺�̏����ɂ͂����Ȃ�

	if (m_iFrameCount >= 300) {
		// ���Q�[���I�[�o�[������ //
		m_HasKill = true;
	}
}

void Puppet::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case CenterScene:
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/The_Puppet.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex);
		break;
	default:
		break;
	}
}

void Puppet::Draw()
{
	if (m_IsDeath != true) { return; }
	// �����Ă����炱����艺�̏����ɂ͂����Ȃ�

	if (GetCurrentSceneId() == SceneId::MonitorScene 
		&& MonitorFunc()->Get() == MonitorTransition::Id::Spown) {

		DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex));
	}
}
