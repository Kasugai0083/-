#ifndef UI_H_
#define UI_H_

/**
* �I�u�W�F�N�g�̗t�i�ŏI�p����j@n
* UserInterface ���Ǘ�����N���X���i�[
*/

#include "UIvalue.h"
#include "../../Texture/Texture.h"
#include "../Object.h"

/**
* @brief UI���Ǘ�����N���X@n
*/
class UI : public Object {
public:

	/**
	* @fn UI(ObjID id_)
	* @brief �R���X�g���N�^@n�����o�ϐ��̏�����@n
	* @param[in] id_ �Ŏw�肳�ꂽ ObjID ����
	*/
	UI(ObjID id_) {
		m_Id = id_;
		m_HasMask = false;
	};

	/**
	* @fn void Init()
	* @brief �e��f�[�^�� m_Id �Ɋ�Â��ď�����@n
	* �摜�ǂݍ���@n���W�̎w��@n�A�C�e���̑傫����ݒ�@n
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief UI�̐������̍X�V@n
	* GameScene �Ɏ�������Ă��� UI �̏���
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief �������Ɋ�Â��ĕ`��@n
	* �}�E�X���d�Ȃ��Ă���ꍇ�A���|���S�����d�˂�
	*/
	void Draw()override;

	/**
	* @fn bool HasOnMouse()
	* @brief m_OnMouse ���擾����
	* @return �}�E�X���d�Ȃ��Ă����� true@n
	* �}�E�X���d�Ȃ��Ă��Ȃ��� false
	*/
	bool HasOnMouse()override {	return m_OnMouse; };

	/**
	* @fn bool HasMask()
	* @brief m_HasMask ���擾����
	* @return �}�X�N�����Ă��鎞 true@n
	* �}�X�N�����Ă��Ȃ��� false
	*/
	bool HasMask()override { return m_HasMask; };

private:
	/**
	* Update �ŌĂяo�����֐�
	*/

	/**
	* @fn void UpdateGameUI()
	* @brief GameScene �Ŏg���Ă��� UI �̍X�V����
	*/
	void UpdateGameUI();

private:
	Texture* m_Tex;		//!< �e�N�X�`���̏����i�[
	bool m_HasMask;		//!< �}�X�N���E���
	bool m_OnMouse;		//!< �}�E�X���d�Ȃ����Ƃ� true
	Vec2 m_Pos;			//!< ���W���
	Size m_Size;		//!< �T�C�Y���


};

#endif