#include <stdio.h>
#include "../Scene/Scene.h"
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

// �Q�[���{�҃V�[���̏�����
void InitCenterScene();
// �Q�[���{�҃V�[���̃��C������
void MainCenterScene();
// �Q�[���{�҃V�[���̏I��
SceneId FinishCenterScene();

//�V�[���J��
SceneId UpdateCenterScene()
{
	switch (GetCurrentSceneStep())
	{
	case SceneStep::InitStep:
		InitCenterScene();
		break;
	case SceneStep::MainStep:
		MainCenterScene();
		break;
	case SceneStep::EndStep:
		return FinishCenterScene();
		break;
	}

	return SceneId::CenterScene;
}

void DrawCenterItem() {
	//�L�����h��
	ObjManager()->Draw(object::CANDLE_SMALL);
	ObjManager()->Draw(object::FIRE_SMALL);
	ObjManager()->Draw(object::CANDLE_STAND);
	ObjManager()->Draw(object::CANDLE_EFFECT);

	//�v���C���[�̃A�C�e��
	ObjManager()->Draw(object::CRYSTAL);
	ObjManager()->Draw(object::MUSICBOX);

}

//�V�[���̃��C������
void DrawCenterScene()
{

	DrawTexture(0.0f, 0.0f, GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex));

	DrawCenterItem();

	g_Manager.Draw();

}

void InitCenterScene()
{
	TimerFunc()->Set(0 ,Timer::Id::Scene);

	ObjManager()->Init();

	g_Manager.LoadTex(GetCurrentSceneId());

	LoadTexture("Res/Game/Center/GameCenterBg.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCenterBgTex);

	ChangeSceneStep(SceneStep::MainStep);
}

void MainCenterScene()
{
	Character* tmp_player = g_Manager.GetCharacter(PLAYER);

	if (tmp_player == nullptr) {
		return;
	}

	//�^�C�}�[�̃A�b�v�f�[�g
	TimerFunc()->Update(Timer::Id::Scene);
	TimerFunc()->Update(Timer::Id::Clear);

	SceneController()->GameEnd();
	
	g_Manager.Update();

	ObjManager()->Update();

	//�L�[���͂ŃV�[���J��
	if (TimerFunc()->Get(Timer::Id::Scene) >= SCENE_WAIT) {
		
		SceneController()->ChangeStep(SceneTransition::Id::Left, A_KEY);
		SceneController()->ChangeStep(SceneTransition::Id::Right, D_KEY);
		SceneController()->ChangeStep(SceneTransition::Id::Monitor, S_KEY);

	}

	//�N���A���Ԍo�߂ŃV�[���J��
	if (TimerFunc()->Get(Timer::Id::Clear) >= CLEAR_TIME) {
		if(tmp_player->IsDeath() == false){
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
//�V�[���̃��C�����������܂�

SceneId FinishCenterScene()
{
	ReleaseCategoryTexture(TEXTURE_CATEGORY_CENTER);

	if (SceneController()->IsGetID(SceneTransition::Id::Clear) == true) {
		SceneController()->SetID(SceneTransition::Id::Clear, false);
		return SceneId::ClearScene;
	}	
	else if (SceneController()->IsGetID(SceneTransition::Id::Left) == true) {
		SceneController()->SetID(SceneTransition::Id::Left, false);
		return SceneId::LeftScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Right) == true) {
		SceneController()->SetID(SceneTransition::Id::Right, false);
		return SceneId::RightScene;
	}
	else if (SceneController()->IsGetID(SceneTransition::Id::Monitor) == true) {
		SceneController()->SetID(SceneTransition::Id::Monitor, false);
		return SceneId::MonitorScene;
	}
}

