#pragma once

/**
* �I�u�W�F�N�g�̗t�i�ŏI�p����j\n
* �������Ǘ�����N���X���i�[
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Engine/Calculation.h"
#include "../../../Timer/Timer.h"
#include "../../../Engine/Input.h"
#include "../../../Scene/GameScene/GameData.h"

/**
* @brief �������Ǘ�����N���X
*/
class Crystal : public Item {
public:
	//! �R���X�g���N�^
	Crystal() { m_IsDeath = true; };
	//! �f�X�g���N�^
	~Crystal() {};						

	/**
	*@fn void Init()
	*@brief �����̏�����@n
	*�e�N�X�`���̓ǂݍ���@n
	*���W�̎w��@n
	*�I�u�W�F�N�g�T�C�Y�̎w��
	*/
	void Init()override {

		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		LoadTexture("Res/Game/Item/crystal_effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitCrystalTex);

		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);	
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitCrystalTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = CRYSTAL_POS;
		m_Size = CRYSTAL_SIZE;

	};

	/**
	*@fn void Update()
	*@brief �����̍X�V\n
	*�Q�[���V�[���ȊO�ł͎��S\n
	*����ł��Ȃ���Γ����蔻������\n
	*/
	void Update()override {

		if (GetCurrentSceneId() == GameScene) {

			if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER) {
				m_IsDeath = false;
			}
			else {
				m_IsDeath = true;

			}
		}
		else {
			m_IsDeath = true;
		}

		if (m_IsDeath == false) {
			if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
				m_OnMouse = true;
			}
			else {
				m_OnMouse = false;
			}
		}
	}


	/**
	*@fn void Draw()
	*@brief �����̕`��\n
	*���S���Ă��Ȃ���Ε`��\n
	*�}�E�X�I�[�o�[�ŃG�t�F�N�g�̒ǉ�\n
	*/
	void Draw()override {

		if (m_IsDeath == false) {
			if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);
		}
	}

private:
	//! �}�E�X�I�[�o�[���̉摜
	Texture* m_pOnHitTex;
};

/**
* @brief ���v���Ǘ�����N���X
*/
class Watch : public Item {
public:
	//! �R���X�g���N�^
	Watch() { m_IsDeath = true; };
	//! �f�X�g���N�^
	~Watch() {};					

	/**
	*@fn void Init()
	*@brief ���v�̏�����\n
	*�e�N�X�`���̓ǂݍ���\n
	*���W�̎w��\n
	*�I�u�W�F�N�g�T�C�Y�̎w��
	*/
	void Init()override {

		LoadTexture("Res/Game/Item/pocket_watch.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameWatchTex);
		LoadTexture("Res/Game/Item/pocket_watch_effect.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitWatchTex);

		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameWatchTex);
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitWatchTex);

		if (m_pTex == nullptr) {
			return;
		}

		m_Pos = WATCH_POS;
		m_Size = WATCH_SIZE;

	};

	/**
	*@fn void Update()
	*@brief ���v�̍X�V\n
	*�Q�[���V�[���ȊO�ł͎��S\n
	*����ł��Ȃ���Γ����蔻������\n
	*/
	void Update()override {

		if (GetCurrentSceneId() == GameScene) {

			if (GameView()->CurrentViewID() == GameData::SubGameScene::CENTER) {
				m_IsDeath = false;
			}
			else {
				m_IsDeath = true;

			}
		}
		else {
			m_IsDeath = true;
			m_OnMouse = false;
		}

		if (m_IsDeath == false) {

			if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
				m_OnMouse = true;
			}
			else {
				m_OnMouse = false;
			}
			
		}

	}


	/**
	*@fn void Draw()
	*@brief ���v�̕`��\n
	*���S���Ă��Ȃ���Ε`��\n
	*�}�E�X�I�[�o�[�ŃG�t�F�N�g�̒ǉ�\n
	*/
	void Draw()override {

		if (m_IsDeath == false) {
			if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}
			DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);
		}
	}

private:
	//! �}�E�X�I�[�o�[���̉摜
	Texture* m_pOnHitTex;
};

