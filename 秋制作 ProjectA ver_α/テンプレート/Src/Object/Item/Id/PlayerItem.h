/**
*	@file Botan.h
*	@author �t����
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

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
#include "../..//..//Data/GameData.h"
#include "../../../Character/CharacterManager.h"

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


		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_CRYSTAL_TEX);

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

		Character* pPlayer = g_Manager.GetCharacter(PLAYER);

		if (pPlayer->HasMonitor() == false) {
			if (GetCurrentSceneId() == GameScene) {

				if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW) {
					m_IsDeath = false;
				}
				else {
					m_IsDeath = true;
				}
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
			/*if (m_OnMouse == true) {
				DrawTexture(m_Pos, m_pOnHitTex);
			}*/
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


		m_pTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_WATCH_TEX);
		m_pOnHitTex = GetTexture(TEXTURE_CATEGORY_GAME_OBJECT, GameObjectCategoryTextureList::OBJECT_ONHITWATCH_TEX);

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

		Character* pPlayer = g_Manager.GetCharacter(PLAYER);

		if (pPlayer->HasMonitor() == false) {
			if (GetCurrentSceneId() == GameScene) {

				if (pPlayer->CurrentViewID() == SubGameScene::CENTER_VIEW) {
					m_IsDeath = false;
				}
				else {
					m_IsDeath = true;
					m_OnMouse = false;
				}
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

		if (pPlayer->HasMask() == true) {
			m_OnMouse = false;
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

