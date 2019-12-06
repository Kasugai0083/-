#include "../Engine/Graphics.h"
#include "../Engine/Input.h"
#include "../Texture/Texture.h"
#include "OpeningScene.h"
#include "../Engine/Calculation.h"
#include "..//Timer/Timer.h"
#include "../Character/Player/Player.h"
#include "../Character/CharacterManager.h"
#include "../Character/CharacterID.h"
#include "Days/DayController.h"

class OpController {
public:
	OpController() {};
	~OpController() {};

	void Init() { 
		m_Count = 0;
	};
	void Update() {
		Timer* pTimerInstance = Timer::GetInstance();
		pTimerInstance->Update();

		if (pTimerInstance->GetTime(Timer::Id::SCENE) >= SCENE_WAIT) {
			if (OnMouseDown(Left) == true) {
				m_Count++;
			}
		}
	};

	int GetCount() { return m_Count; };
private:

	int m_Count;
};

static OpController OpCon;

// ゲームオーバーシーンの初期化
void InitOpeningScene();
// ゲームオーバーシーンのメイン
void MainOpeningScene();
// ゲームオーバーシーンの終了
SceneId FinishOpeningScene();

SceneId UpdateOpeningScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitOpeningScene();
		break;
	case SceneStep::MainStep:
		MainOpeningScene();
		break;
	case SceneStep::EndStep:
		return FinishOpeningScene();
		break;
	}

	return SceneId::OpeningScene;
}


void DrawOpeningScene()
{
	DayController DayCon;

	switch (DayCon.GetCurrentDays())
	{
	case Days::DAY_0:
		if (OpCon.GetCount() == 0) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary1Tex));
		}
		else if (OpCon.GetCount() == 1) {
			DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary2Tex));
		}
		break;
	case Days::DAY_1:
		break;
	case Days::DAY_2:
		break;
	case Days::DAY_3:
		break;
	default:
		break;
	}

}

void InitOpeningScene()
{
	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init(Timer::Id::SCENE);

	OpCon.Init();

	LoadTexture("Res/Opening/operation_scene.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary1Tex);
	LoadTexture("Res/Opening/operation_scene2.png", TEXTURE_CATEGORY_OPENING, OpeningCategoryTextureList::OpeningDiary2Tex);

	ChangeSceneStep(SceneStep::MainStep);

}

void MainOpeningScene()
{
	SceneController()->GameEnd();

	OpCon.Update();

	if (OpCon.GetCount() == 2) {
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishOpeningScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_OPENING);

	Timer* pTimerInstance = Timer::GetInstance();
	pTimerInstance->Init();

	return SceneId::GameScene;
}

