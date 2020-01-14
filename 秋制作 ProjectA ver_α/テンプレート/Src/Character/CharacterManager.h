#ifndef CHARACTERMANAGER_H_
#define CHARACTERMANAGER_H_

#include "Character.h"
#include "CharacterID.h"

// キャラクターマネージャークラス
class CharacterManager {

public:
	/*
		コンストラクタ
	*/
	CharacterManager();
	/*
		デストラクタ
	*/
	~CharacterManager();

	/*
		初期化
	*/
	void Initialize();

	/*
		更新
	*/
	void Update();

	/*
		引数に指定したidのインスタンスのアドレスを返す
	*/
	Character* GetCharacter(int id) {
		return m_Charas[id];
	}

	/*
		描画
	*/
	void Draw();

	/*
		テクスチャの読み込み関数
	*/
	void LoadTex();

	/*
		キルアニメーション
	*/
	void KillAnimation();


	bool RefKill();

private:
	void Release();

	Character* m_Charas[8];
};

extern CharacterManager g_Manager;

#endif