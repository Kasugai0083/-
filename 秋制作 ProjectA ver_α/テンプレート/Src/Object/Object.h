#pragma once

/**
* �I�u�W�F�N�g�̐e(�h����)@n
* UI �� Item �ɔh������N���X���i�[
*/

#include "../Utility/Vec.h"
#include "../Utility/Size.h"
#include "../Texture/Texture.h"
#include "ObjectID.h"

/**
* @brief �I�u�W�F�N�g���Ǘ�����N���X
*/
class Object {
public:

	Object() {};	//!< �R���X�g���N�^
	~Object() {};	//!< �f�X�g���N�^

	virtual void Init() = 0;		//!< Init �̏����z�֐�

	virtual void Update() = 0;		//!< Update �̏����z�֐�

	virtual bool HasOnMouse() = 0;	//!< HasOnMouse �̏����z�֐�
	
	virtual void Draw() = 0;		//!< Draw �̏����z�֐�

	/**
	* @fn float GetHp()
	* @brief Candle �N���X�Ŏg�p���� GaetHp() �̉��z�֐�
	* Candle ���C���X�^���X�����Ďg�p����
	*/
	virtual float GetHp() { return 0; }; 

	/**
	* @fn float GetHp()
	* @brief Candle �N���X�Ŏg�p���� GaetHp() �̉��z�֐�
	* Candle ���C���X�^���X�����Ďg�p����
	*/
	virtual float GetRatio() { return 0; };

	/**
	* @fn float HasCaLight()
	* @brief Candle �N���X�Ŏg�p���� HasCaLight() �̉��z�֐�
	* Candle ���C���X�^���X�����Ďg�p����
	*/
	virtual bool HasCaLight() { return 0; };

	/**
	* @fn bool HasMas()
	* @brief UI �N���X�Ŏg�p���� HasMask() �̉��z�֐�
	* UI ���C���X�^���X�����Ďg�p����
	*/
	virtual bool HasMask() { return 0; };
protected:

	bool m_IsDeath; //!< �I�u�W�F�N�g�̐������
	ObjID m_Id;		//!< �I�u�W�F�N�g�̎��ʔԍ�

private:

};
