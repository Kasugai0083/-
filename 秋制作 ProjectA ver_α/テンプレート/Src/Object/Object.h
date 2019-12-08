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

	Object() {}; //!< �R���X�g���N�^
	~Object() {}; //!< �f�X�g���N�^

	virtual void Init() = 0; //!< Init �̉��z�֐�

	virtual void Update() = 0;

	virtual bool HasOnMouse() = 0;
	
	virtual void Draw() = 0;

	virtual Vec2 GetPos() { return m_Pos; };
	virtual float GetHp() { return 0; };
	virtual float GetRatio() { return 0; };
	virtual bool HasCaLight() { return 0; };

	virtual bool HasMask() { return 0; };
protected:

	bool m_IsDeath;
	ObjID m_Id;

private:
	Vec2 m_Pos;
};
