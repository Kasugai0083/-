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

	/**
	* @fn void Draw()
	* @brief ���W�Ɖ摜���Ɋ�Â��ĕ`��@n
	* �}�E�X���d�Ȃ����獕�|���S�����d�˂�
	*/
	void Draw()override;

	/**
	* @fn void Update()
	* @brief �}�E�X���摜���ɏd�Ȃ����ꍇ�A���|���S�����d�˂�
	*/
	void Update()override;

	/**
	* @fn void HasOnMouse()
	* @brief m_OnMouse���擾����
	* @return �}�E�X���d�Ȃ��Ă����� true@n
	* �}�E�X���d�Ȃ��Ă��Ȃ��� false
	*/
	bool HasOnMouse()override { return m_OnMouse; };
	
protected:
	Texture* m_pTex;	//!< �e�N�X�`���̏����i�[
	bool m_OnMouse;		//!< �}�E�X���d�Ȃ����Ƃ� true
	Vec2 m_Pos;			//!< ���W���
	Size m_Size;		//!< �T�C�Y���
	Size m_Frame;		//!< �摜�T�C�Y���
};

#endif