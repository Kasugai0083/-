#ifndef ITEM_H_
#define ITEM_H_

/**
* �I�u�W�F�N�g�̌p���N���X@n
* Candle, Fire, PlayerItem class �ɔh��
*/


#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"
#include "../../Texture/Texture.h"
#include "../Object.h"
#include "ItemValue.h"

/**
* @brief �ŏI�p����Ɏg�������Ȋ֐���ϐ����i�[����N���X
*/
class Item : public Object {
public:

	Item();		//!< �R���X�g���N�^
	~Item();	//!< �f�X�g���N�^

	void Draw()override;
	void Update()override;

	bool HasOnMouse()override;
	
protected:
	Texture* m_pTex;
	bool m_OnMouse;
	Vec2 m_Pos;
	Size m_Size;
	Size m_Frame;


};

#endif