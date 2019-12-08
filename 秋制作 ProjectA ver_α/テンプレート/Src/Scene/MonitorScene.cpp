#include <stdio.h>
#include "../Engine/Input.h"
#include "../Engine/Graphics.h"
#include "../Texture/Texture.h"
#include "../Engine/Calculation.h"
#include "../Character/Player/Player.h"
#include "../Character/Enemy/Enemy.h"
#include "..//Timer/Timer.h"
#include "../Character/CharacterManager.h"
#include "../Object/ObjectManager.h"
#include "../Object/UI/UIvalue.h"


// �Q�[���{�҃V�[���̏�����
void InitMonitorScene();
// �Q�[���{�҃V�[���̃��C������
void MainMonitorScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishMonitorScene();


#pragma region ���j�^�[�̕`��֐�

void LoadMonitor() {

	ObjManager()->Init();

	LoadTexture("Res/Game/Monitor/GameMonitorBg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex);
	LoadTexture("Res/Game/Monitor/Duct/LeftDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex);
	LoadTexture("Res/Game/Monitor/Duct/RightDuct.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex);
	LoadTexture("Res/Game/Monitor/child_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex);
	LoadTexture("Res/Game/Monitor/resption_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex);
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	LoadTexture("Res/Game/Monitor/dust.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex);

}

void DrawBg() {
	if (GameView()->CurrentMonitorID() == MonitorView::WORKSHOP_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::LEFT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::RIGHT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::STORE_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::RECEPTION_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));
	}
	else if (GameView()->CurrentMonitorID() == MonitorView::CHILD_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));
	}

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

	DrawFont(100.f, 900.f, "Space �� �߂�",Large, White);

}

#pragma endregion

SceneId UpdateMonitorScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitMonitorScene();
		break;
	case SceneStep::MainStep:
		MainMonitorScene();
		break;
	case SceneStep::EndStep:
		return FinishMonitorScene();
		break;
	}

	return SceneId::MonitorScene;
}

void DrawMonitorScene()
{	
	DrawBg();

	g_Manager.Draw();///����������

	ObjManager()->Draw();


}

void InitMonitorScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	LoadMonitor();

	ObjManager()->Init();

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainMonitorScene()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer == nullptr) {
		return;
	}

	//UI�̃A�b�v�f�[�g

	ObjManager()->Update();

	//�^�C�}�[�̃A�b�v�f�[�g

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();


	//�L�[���͂ŃV�[���J��

	if (pPlayer->ControlMonitor() == true) {
		SceneController()->SetID(SceneTransition::Id::Game, true);
		ChangeSceneStep(SceneStep::EndStep);
	}


	//�N���A���Ԍo�߂ŃV�[���J��
	if (pTimerInstance->GetClearTime() == CLEAR_TIME) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

	//�v���C���[�̎��S�ŃV�[���J��
	if (pPlayer->IsActive() == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}

SceneId FinishMonitorScene()
{
	//ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	//ObjManager()->Release();

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Game) == true) {
		SceneController()->SetID(SceneTransition::Id::Game, false);
		return SceneId::GameScene;
	}
}

