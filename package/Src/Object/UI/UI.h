/**
*	@file UI.h
*	@author �t����
*	@brief �I�u�W�F�N�g�̗t�i�ŏI�p����j
*	@brief ���[�U�[�C���^�[�t�F�[�X���Ǘ�����N���X������
*/

#ifndef UI_H_
#define UI_H_

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

		m_Tex = nullptr;
		m_Tex2 = nullptr;
		m_OnHitTex = nullptr;
		m_OnHitTex2 = nullptr;

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

	/**
	* @fn void UpdateTitleUI()
	* @brief TitleScene �Ŏg���Ă��� UI �̍X�V����
	*/
	void UpdateTitleUI();

private:
	//! �e�N�X�`���̏����i�[
	Texture* m_Tex, *m_OnHitTex;
	Texture* m_Tex2, *m_OnHitTex2;
	//! �}�X�N���E���
	bool m_HasMask;	
	//! �}�E�X���d�Ȃ����Ƃ� true
	bool m_OnMouse;		
	//! ���W���
	Vec2 m_Pos;			
	//! �T�C�Y���
	Size m_Size;		

};

#endif