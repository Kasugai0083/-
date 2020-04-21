/**
*	@file Botan.h
*	@author �t����
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

#pragma once

/**
* �I�u�W�F�N�g�̗t�i�ŏI�p����j@n
* �X�C�̉΂��Ǘ�����N���X���i�[
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "Candle.h"
#include "../../ObjectManager.h"

/**
* @brief �X�C�̉΂��Ǘ�����N���X@n
*/
class Fire : public Item {
public:

	/**
	* @fn Fire(ObjID id_)
	* @brief �R���X�g���N�^@n�����o�ϐ��̏�����@n
	* @param[in] id_ �Ŏw�肳�ꂽ ObjID ����
	*/
	Fire(ObjID id_) {
		m_Id = id_;
		m_IsDeath = true;
	}

	/**
	* @fn void Init()
	* @brief �e��f�[�^�� m_Id �Ɋ�Â��ď�����@n
	* �摜�ǂݍ���@n���W�̎w��@n�A�C�e���̑傫����ݒ�@n�摜�̑傫����ݒ�@n
	* m_Id �Ɋ�Â��� Candle ���C���X�^���X��
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief �X�C�̓_�����Ɋ�Â��āA�΂��X�V@n
	* �΂̐����Ǘ�@n
	* �X�C���n���ĉ΂̍��W�������鏈��
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief �X�C�̓_�����Ǝ��g�̐������Ɋ�Â��ĕ`��@n
	*/
	void Draw()override;

private:
	/**
	* Update���Ŏg�p����Ă���֐�
	*/

	//! GameView ��񂩂琶�������Ǘ�
	void SceneDeath();

	//! �������������ɂ���ĊǗ�
	void FireSwitch(bool center_switch_, bool left_switch_, bool right_switch_);
private:
	//! @brief �X�C���̎擾�p�ϐ�
	Object* m_pObject;	
};
