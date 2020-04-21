#ifndef OHAGI_H_
#define OHAGI_H_

/**
*	@file Botan.h
*	@author 中本
*	@brief キャラクター「牡丹」を管理するクラスを処理
*/


#include "../../Enemy/Enemy.h"
#include "../../CharacterID.h"
#include "../../../Utility/RoomID.h"
#include "../../../Scene/Scene.h"
#include "../../CharacterManager.h"

/*
	フレディ(エネミー)のクラス
*/
class Ohagi : public Enemy
{
public:
	/*
		コンストラクタ
	*/
	Ohagi() :
		Enemy(RoomID::ROOM_WORK, EnemyID::OHAGI)
	{
		m_pPlayer = g_Manager.GetCharacter(PLAYER);
		if (m_pPlayer == nullptr) {

			return;
		}

		m_AnimationTex.m_Counter = 0;
		m_AnimationTex.m_Length  = 3;
		m_AnimationTex.m_Speed   = 15;

		for (int i = 0; i < m_AnimationTex.m_Length; i++) {
			m_AnimationTex.m_TextureData[i] = new Texture();
		}
	}
	/*
		デストラクタ
	*/
	virtual ~Ohagi(){}
	/*
		初期化
	*/
	virtual void Init() override;

	/*
		挙動
	*/
	virtual void Update() override;
	/*
		m_IsKillを返す
	*/
	virtual bool HasKill()const override { return m_HasKill; }

	/*
		引数に現在のシーンを入れる
		テクスチャのロード
	*/
	virtual void LoadTex() override;
	/*
		描画
	*/
	virtual void Draw() override;

	/*
		キルアニメーション
	*/
	virtual void KillAnimation() override;


private:
	const CharacterID m_CharId = CharacterID::OHAGI;// キャラID定数
};

#endif