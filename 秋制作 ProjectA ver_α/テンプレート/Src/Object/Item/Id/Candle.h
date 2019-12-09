#pragma once

/**
* �I�u�W�F�N�g�̗t�i�ŏI�p����j@n
* �X�C���Ǘ�����N���X���i�[
*/

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

const float MELT_RATIO = 0.001f; //!< @brief �X�C���n���鑬�x

/**
* @brief �X�C�ɓZ���I�u�W�F�N�g���Ǘ�����N���X@n
* �X�C�A�C��A�X�C�̃G�t�F�N�g@n
*/
class Candle : public Item {
public:

	/**
	* @fn Candle(ObjID id_)
	* @brief �R���X�g���N�^@n�e�탁���o�ϐ��̏�����@n
	* @param[in] id_ �Ŏw�肳�ꂽ ObjID ����
	*/
	Candle(ObjID id_)
	{
		m_Id = id_;
		m_IsDeath = true;
		m_HeightRatio = NULL;
		m_HasCaLight = false;
		m_CandleHp = 1.f;

	};

	/**
	* @fn void Init()
	* @brief �e��f�[�^�� m_Id �Ɋ�Â��ď�����@n
	* �摜�ǂݍ���@n���W�̎w��@n�A�C�e���̑傫����ݒ�@n�摜�̑傫����ݒ�@n
	*/
	void Init()override;

	/**
	* @fn void Update()
	* @brief �X�C�̍X�V@n�X�C�̐����Ǘ�@n�L�����h�����ł̊Ǘ�@n
	* �L�����h�����n���č��W�������鏈��
	*/
	void Update()override;

	/**
	* @fn void Draw()
	* @brief m_Id �Ɋ�Â��ĕ`��@n
	* �X�C�̏ꍇ => �w���X�ɉ����ėn����悤�ɕ`�悳���@n
	* ����ȊO   => �w�肳�ꂽ���W�ƃT�C�Y�ŕ`��
	*/
	void Draw() override;

	/**
	* @fn float GetHp()
	* @brief �C���X�^���X�����ė��p����
	* @return float �C���X�^���X�� m_CandleHp ��Ԃ�
	*/
	float GetHp()override	  { return m_CandleHp;	 };

	/**
	* @fn float GetRatio()
	* @brief �C���X�^���X�����ė��p����
	* @return float �C���X�^���X�� m_HeightRatio ��Ԃ�
	*/
	float GetRatio()override  { return m_HeightRatio;};

	/**
	* @fn float HasCaLight()
	* @brief �C���X�^���X�����ė��p����
	* @return float �C���X�^���X�� m_HasCaLight ��Ԃ�
	*/
	bool HasCaLight()override {	return m_HasCaLight; };

private:
	/**
	* Update���Ŏg�p�����֐��Q
	*/

	/**
	* @fn void SceneDeath()
	* @brief GameScene �ȊO�ŃL�����h�������S������@n
	* GameView ���ɂ���ăL�����h���̐������Ǘ�����@n
	*/
	void SceneDeath();

	/**
	* @fn void SceneDeath()
	* @brief �L�����h���̐������Ǘ�����X�C�b�`
	* @param[in] center_switch_  true ���� CANDLE_CENTER ����
	* @param[in] left_switch_  true ���� CANDLE_LEFT ����
	* @param[in] right_switch_  true ���� CANDLE_RIGHT ����
	*/
	void CandleSwitch(bool center_switch_, bool left_switch_, bool right_switch_);

	/**
	* @fn void MeltCandle(ObjID id_)
	* @brief �L�����h����n�������߂Ɍv�Z����֐�
	* @param[in] id_ �w�肵���L�����h����n����
	*/
	void MeltCandle(ObjID id_);

	/**
	* @fn void EffectUpdate()
	* @brief �L�����h���G�t�F�N�g�̐��������Ǘ�
	*/
	void EffectUpdate();

private:
	//! @brief �L�����h�����_�����
	bool m_HasCaLight;

	//! @brief �L�����h����HP
	float m_CandleHp; 

	//! @brief �L�����h���̍����䗦
	float m_HeightRatio; 
};

