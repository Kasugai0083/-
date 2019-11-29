#include "Puppet.h"
#include "../../CharacterManager.h"
#include "../../../Engine/Graphics.h"
#include "../../../Texture/Texture.h"
#include "../../../Timer/Timer.h"
#include "../../../Object/Item/Id/PlayerItem.h"

void Margaret::Init()
{
}

void Margaret::Update()
{
	// ���j�^�[�V�[�����q�����������Ă���Ƃ�
	if (m_pPlayer->HasMonitor() == true
		&& m_pPlayer->CurrentViewMonitorID() == MonitorView::CHILD_ROOM_VIEW) {

		m_iFrameCount++;
		// ����l�ɂȂ��������l�������
		if (m_iFrameCount == MAX_COUNT) {
			m_iFrameCount = MAX_COUNT;
		}
	}
	else {
		m_iFrameCount--;
	}

	Timer* pTimerInstance = Timer::GetInstance();

	if (m_IsActive == false && pTimerInstance->GetTime(Timer::Id::MUSICBOX) >= END_STEP) {

		m_iFrameCount = 0;
		m_IsActive = true;
	}

	if (m_iFrameCount == 0) {

		m_IsActive = true;
	}

	if (m_IsActive == false) { return; }
	// �A�N�e�B�u����Ȃ������炱����艺�̏����ɂ͂����Ȃ�

	if (m_IsActive == true) {
		// ���Q�[���I�[�o�[������ //
		m_HasKill = true;
	}

}

void Margaret::LoadTex(SceneId id_)
{
	switch (id_)
	{
	case CenterScene:
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_base.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		break;

	case MonitorScene:
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_base.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet);
		LoadTexture("Res/Game/Enemy/Margaret/mag_camera_eye.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex);
		break;
	default:
		break;
	}
}

void Margaret::Draw()
{
	if (m_IsActive == false)
	{
		if (GetCurrentSceneId() == SceneId::MonitorScene
			&& GameView()->CurrentMonitorID() == MonitorView::CHILD_ROOM_VIEW) {

			DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorPuppetTex));
			DrawTexture(1000.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterPuppet));
		}
	}
}

void Margaret::KillAnimation()
{
}
