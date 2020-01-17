#include <stdio.h>
#include "../../Scene/Scene.h"
#include "../../Engine/Input.h"
#include "../../Engine/Graphics.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Calculation.h"
#include "../../Character/Enemy/Enemy.h"
#include "../../Timer/Timer.h"
#include "../../Character/CharacterManager.h"
#include "../../Object/ObjectManager.h"
#include "../../Object/ObjectID.h"
#include "../..//Data/GameData.h"
#include "GameScene.h"
#include "../../Object/Item/ItemValue.h"
#include "../../Object/Object.h"
#include "../../Object/UI/UIvalue.h"
#include "../../Engine/Audio/Audio.h"
#include "../../Texture/LoadTex.h"

// �Q�[���{�҃V�[���̏�����
void InitGameScene();
// �Q�[���{�҃V�[���̃��C������
void MainGameScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishGameScene();

//�V�[���J��
SceneId UpdateGameScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitGameScene();
		break;
	case SceneStep::MainStep:
		MainGameScene();
		break;
	case SceneStep::EndStep:
		return FinishGameScene();
		break;
	}

	return SceneId::GameScene;
}

void DrawMonitorBg() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer->CurrentViewID() == SubGameScene::WORKSHOP_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::LEFT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::RIGHT_CORRIDOR_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::STORE_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::RECEPTION_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));
	}
	else if (pPlayer->CurrentViewID() == SubGameScene::CHILD_ROOM_VIEW) {
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));
	}

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

	DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

}

//�V�[���̃��C������
void DrawGameScene()
{
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	Object* pLeftCandle = ObjManager()->GetObj(ObjID::CANDLE_LEFT);
	Object* pRightCandle = ObjManager()->GetObj(ObjID::CANDLE_RIGHT);

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);
	Timer* pTimerInstance = Timer::GetInstance();
	
	switch (pPlayer->CurrentViewID()) {
	case SubGameScene::CENTER_VIEW:
		if (pPlayer->HasMonitor() == false) {

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex));

			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		}
		g_Manager.Draw();

		if (pPlayer->HasMonitor() == false) {

			if (pCenterCandle->HasCaLight() == false) {
				DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex));
			}
		}

		ObjManager()->Draw();

		pTimerInstance->Draw();

		pPlayer->Draw();

		break;
	case SubGameScene::RIGHT_VIEW:
		if (pPlayer->HasMonitor() == false) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));
			//�J�[�e��
			if (pRightCandle->HasCaLight() == false) {
				DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightBlackTex));
			}
		}


		g_Manager.Draw();

		ObjManager()->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::LEFT_VIEW:
		if (pPlayer->HasMonitor() == false) {

			DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex));
			DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex));
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

			//�J�[�e��
			if (pLeftCandle->HasCaLight() == false) {
				DrawTexture(128.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftBlackTex));
			}
		}

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::WORKSHOP_VIEW:

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorSpownBgTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::LEFT_CORRIDOR_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorLeftDuctBgTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::RIGHT_CORRIDOR_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorRightDuctBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::STORE_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::RECEPTION_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorResptionRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	case SubGameScene::CHILD_ROOM_VIEW:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorChildRoomBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorDustTex));

		DrawFont(100.f, 900.f, "Space �� �߂�", Large, White);

		ObjManager()->Draw();

		pPlayer->Draw();

		pTimerInstance->Draw();

		g_Manager.Draw();

		break;
	}
	
	


	g_Manager.KillAnimation();
	
}

void InitGameScene()
{
	InitTexture();

	//�f�o�b�O�p
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();
	LoadTexture("Res/Game/Monitor/store_room_bg.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorStoreRoomBgTex);
	InitTexture();

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	ObjManager()->CreateGameObj();
	ObjManager()->Init();

	g_Manager.CreateCharacter();
	
	g_Manager.LoadTex();

	LoadSceneTex(SceneId::GameScene);

	// �I�[�f�B�I
	auto pAudio = AudioPlayer::GetInstance(GetWindowHandle());
	pAudio->Load("GameBGM", "Sound/GameBGM.wav");
	pAudio->Play("GameBGM", 1000, true);

	pAudio->Load("RousokuSE", "Sound/RousokuSE.wav");
	pAudio->Load("MaskSE", "Sound/MaskSE.wav");
	pAudio->Load("OhagiKillVoice", "Sound/OhagiKillVoice.wav");
	pAudio->Load("SakuraKillVoice", "Sound/SakuraKillVoice.wav");
	pAudio->Load("UmeKillVoice", "Sound/UmeKillVoice.wav");
	pAudio->Load("OranKillVoice", "Sound/OranKillVoice.wav");
	pAudio->Load("BotanKillVoice", "Sound/BotanKillVoice.wav");
	pAudio->Load("PuppetKillVoice", "Sound/PuppetKillVoice.wav");
	pAudio->Load("ToMonitor", "Sound/ToMonitor.wav");


	ChangeSceneStep(SceneStep::MainStep);
}


void MainGameScene()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

;

	if (pPlayer == nullptr) {
		return;
	}

	//�^�C�}�[�̃A�b�v�f�[�g

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();

	//�N���A���Ԍo�߂ŃV�[���J��
	if (pTimerInstance->GetClearTime() == CLEAR_TIME) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

	//�v���C���[�̎��S�ŃV�[���J��
	if (pPlayer->IsActive() == false) {

		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

}
//�V�[���̃��C�����������܂�

SceneId FinishGameScene()
{

	ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CENTER);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_LEFT);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_RIGHT);
	ReleaseCategoryTexture(TEXTURE_CATEGORY_MONITOR);

	ObjManager()->ReleaseGameObj();
	//g_Manager.Release();

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Monitor) == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

