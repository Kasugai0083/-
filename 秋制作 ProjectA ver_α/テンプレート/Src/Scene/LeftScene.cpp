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
#include "../Object/ObjectID.h"
#include "../Object/Item/ItemValue.h"

// �Q�[���{�҃V�[���̏�����
void InitLeftScene();
// �Q�[���{�҃V�[���̃��C������
void MainLeftScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishLeftScene();

SceneId UpdateLeftScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitLeftScene();
		break;
	case SceneStep::MainStep:
		MainLeftScene();
		break;
	case SceneStep::EndStep:
		return FinishLeftScene();
		break;
	}

	return SceneId::LeftScene;
}

void DrawLeftItem() {
	ObjManager()->Draw(object::CANDLE_BIG);
	ObjManager()->Draw(object::FIRE_BIG);
	ObjManager()->Draw(object::CANDLE_STAND);
	ObjManager()->Draw(object::CANDLE_EFFECT);
}

void DrawLeftScene()
{
	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex));

	DrawLeftItem();

	g_Manager.Draw();
}

void InitLeftScene()
{

	Vec2 EffectPos = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };
	ObjManager()->Init(object::CANDLE_EFFECT, EffectPos);

	TimerFunc()->Set(0, Timer::Id::Scene);

	LoadTexture("Res/Game/Left/GameLeftBg.png", TEXTURE_CATEGORY_LEFT, LeftCategoryTextureList::GameLeftBgTex);

	g_Manager.LoadTex(GetCurrentSceneId());

	ChangeSceneStep(SceneStep::MainStep);
}

void MainLeftScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//�^�C�}�[�̃A�b�v�f�[�g
	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::MusicBox);

	SceneController()->GameEnd();

	ObjManager()->Update();

	g_Manager.Update();

	//�L�[���͂ŃV�[���J��
	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {

		if (GetKey(D_KEY) == true) {
			SceneController()->SetID(SceneTransition::Id::Center, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//�N���A���Ԍo�߂ŃV�[���J��
	if (TimerFunc()->Get(Timer::Id::Clear) >= CLEAR_TIME) {
		if (tmp_player->IsDeath() == false) {
			SceneController()->SetID(SceneTransition::Id::Clear, true);
			ChangeSceneStep(SceneStep::EndStep);
		}
	}

	//�v���C���[�̎��S�ŃV�[���J��
	if (tmp_player->IsDeath() == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, true);
		ChangeSceneStep(SceneStep::EndStep);
	}
}

SceneId FinishLeftScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_LEFT);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Center) == true) {
		SceneController()->SetID(SceneTransition::Id::Center, false);
		return SceneId::CenterScene;
	}
}

