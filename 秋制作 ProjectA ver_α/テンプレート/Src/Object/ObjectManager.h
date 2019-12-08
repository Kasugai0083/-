#pragma once

/**
* オブジェクトを管理するマネージャークラスを定義
*/

#include "Object.h"
#include "ObjectID.h"
#include "../Scene/GameScene/GameData.h"

/**
* @brief オブジェクトを管理するマネージャークラス
*/
class ObjectManager {

public:

	/**
	* @fn ObjectManager()
	* @brief コンストラクタ@n
	* m_pObjects に各種オブジェクトをインスタンス化@n
	*/
	ObjectManager();

	/**
	* @fn ~ObjectManager()
	* @brief デストラクタ@nm_pObjects を delete する
	*/
	~ObjectManager();

	/**
	* @fn Object* GetObj(ObjID id_) 
	* @brief m_pObjects の インスタンス情報を取得する
	* @param[in] id_ m_pObjects の識別番号を指定
	* @return 指定されたインスタンスのアドレスが取得される
	*/
	Object* GetObj(ObjID id_) {
		return m_pObjects[static_cast<int>(id_)];
	}

	/**
	* @fn Init()
	* @brief 全ての m_pObjects を初期化する
	*/
	void Init();

	/**
	* @fn Update()
	* @brief 全ての m_pObjects を更新する
	*/
	void Update();

	/**
	* @fn Release()
	* @brief 全ての m_pObjects を解放する
	*/
	void Release();

	/**
	* @fn void Release(int id)
	* @brief 指定された m_pObjects を解放する
	* @param[in] id_ m_pObjects の識別番号を指定
	*/
	void Release(int id_);

	/**
	* @fn Draw()
	* @brief 全ての m_pObjects を描画する
	*/
	void Draw();

	/**
	* @fn HasOnMouse(ObjID id_)
	* @brief 指定された m_pObjects の HasOnMouse を取得
	* @param[in] id_　m_pObjects の識別番号を指定
	* @return m_pObjects にマウスが触れている場合 true@n
	* m_pObjects にマウスが触れていない場合 false@n
	*/
	bool HasOnMouse(ObjID id_);

private:

	//!< ObjectID.h で指定された識別番号分、インスタンス化する
	Object* m_pObjects[static_cast<int>(ObjID::MAX_OBJECT_NUM)];

};

ObjectManager* ObjManager(); //!< 疑似的なシングルトンをプロトタイプ宣言

