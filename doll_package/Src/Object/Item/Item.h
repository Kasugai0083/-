/**
*	@file Item.h
*	@author 春日井
*	@brief オブジェクトの継承クラス@n
*	Candle, Fire, PlayerItem class に派生
*/

#ifndef ITEM_H_
#define ITEM_H_

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"
#include "../../Texture/Texture.h"
#include "../Object.h"
#include "ItemValue.h"

/**
* @brief 最終継承先に使えそうな関数や変数を格納するクラス
*/
class Item : public Object 
{
public:
	//! コンストラクタ
	Item();	
	//! デストラクタ
	~Item() {};

	/**
	* @fn void Draw()
	* @brief 座標と画像情報に基づいて描画@n
	* マウスが重なったら黒ポリゴンを重ねる
	*/
	void Draw()override;

	/**
	* @fn void Update()
	* @brief マウスが画像情報に重なった場合、黒ポリゴンを重ねる
	*/
	void Update()override;

	/**
	* @fn void HasOnMouse()
	* @brief m_OnMouseを取得する
	* @return マウスが重なっていた時 true@n
	* マウスが重なっていない時 false
	*/
	bool HasOnMouse()override { return m_OnMouse; };
	
protected:
	//! テクスチャの情報を格納
	Texture* m_pTex;	
	//! マウスが重なったとき true
	bool m_OnMouse;
	//! 座標情報
	Vec2 m_Pos;
	//! サイズ情報
	Size m_Size;		
	//! 画像サイズ情報
	Size m_Frame;		
};

#endif