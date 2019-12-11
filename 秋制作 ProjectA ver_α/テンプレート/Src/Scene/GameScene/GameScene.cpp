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
#include "GameData.h"
#include "GameScene.h"
#include "../../Object/Item/ItemValue.h"
#include "../../Object/Object.h"
#include "../../Object/UI/UIvalue.h"

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

//�V�[���̃��C������
void DrawGameScene()
{
	Object* pCenterCandle = ObjManager()->GetObj(ObjID::CANDLE_CENTER);
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	switch (GameView()->CurrentViewID()) {
	case GameData::CENTER:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex));

		g_Manager.Draw();

		if (pCenterCandle->HasCaLight() == false) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex));
		}

		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		ObjManager()->Draw();

		pPlayer->Draw();


		break;
	case GameData::RIGHT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		g_Manager.Draw();

		ObjManager()->Draw();


		break;
	case GameData::LEFT:
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex));
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex));
		
		DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex));

		ObjManager()->Draw();

		g_Manager.Draw();

		break;
	}


	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Draw();
	
}

void InitGameScene()
{

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	ObjManager()->Init();


	g_Manager.LoadTex(GetCurrentSceneId());

	//�Q�[���V�[���w�i
	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);
	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);
	LoadTexture("Res/Game/Right/GameRightBg.png", TEXTURE_CATEGORY_RIGHT, RightCategoryTextureList::GameRightBgTex);

	//�Z���^�[�V�[��
	LoadTexture("Res/Game/Center/fence_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFanceTex);
	LoadTexture("Res/Game/Center/all_black_texture.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameBlackFilterTex);
	LoadTexture("Res/Game/Center/desk.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterDeskTex);
	LoadTexture("Res/Game/Center/black_texture_center.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBlackTex);

	//�E�V�[��
	LoadTexture("Res/Game/Right/right_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiFrontTex);
	LoadTexture("Res/Game/Right/right_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameRightShojiBackTex);
	//���V�[��
	LoadTexture("Res/Game/Left/left_shoji_front.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiFrontTex);
	LoadTexture("Res/Game/Left/left_shoji_back.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameLeftShojiBackTex);


	ChangeSceneStep(SceneStep::MainStep);
}

bool HasSceneChange(GameData::SubGameScene scene_) {
	switch (scene_)
	{
	case GameData::CENTER:
		if (GetKey(A_KEY) == true) {
			return true;
		}
		break;
	case GameData::LEFT:
		break;
	case GameData::RIGHT:
		break;
	default:
		break;
	}
}

void MainGameScene()
{
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (pPlayer == nullptr) {
		return;
	}

	//�^�C�}�[�̃A�b�v�f�[�g

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Update();

	SceneController()->GameEnd();

	g_Manager.Update();

	ObjManager()->Update();


	//�L�[���͂ŃV�[���J��
	if (pPlayer->ControlGameScene() == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, true);
		ChangeSceneStep(SceneStep::EndStep);
	}

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
	//ReleaseCategoryTexture(TEXTURE_CATEGORY_GAME);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Monitor) == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

