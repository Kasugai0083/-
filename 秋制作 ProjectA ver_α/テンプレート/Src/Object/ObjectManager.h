/**
*	@file ObjectManager.h
*	@author �t����
*	@brief �I�u�W�F�N�g���Ǘ�����}�l�[�W���[�N���X���`
*/

#pragma once


#include "Object.h"
#include "ObjectID.h"
#include "../Data/GameData.h"

/**
* @brief �I�u�W�F�N�g���Ǘ�����}�l�[�W���[�N���X
*/
class ObjectManager {

public:

	/**
	* @fn ObjectManager()
	* @brief �R���X�g���N�^@n
	* m_pObjects �Ɋe��I�u�W�F�N�g���C���X�^���X��@n
	*/
	ObjectManager();

	/**
	* @fn ~ObjectManager()
	* @brief �f�X�g���N�^@nm_pObjects �� delete ����
	*/
	~ObjectManager();

	/**
	* @fn Object* GetObj(ObjID id_) 
	* @brief m_pObjects �� �C���X�^���X�����擾����
	* @param[in] id_ m_pObjects �̎��ʔԍ����w��
	* @return �w�肳�ꂽ�C���X�^���X�̃A�h���X���擾�����
	*/
	Object* GetObj(ObjID id_) {
		return m_pObjects[static_cast<int>(id_)];
	}

	/**
	* @fn Init()
	* @brief �S�Ă� m_pObjects ������������
	*/
	void Init();

	/**
	* @fn Update()
	* @brief �S�Ă� m_pObjects ���X�V����
	*/
	void Update();

	/**
	* @fn Release()
	* @brief �S�Ă� m_pObjects ���������
	*/
	void Release();

	/**
	* @fn void Release(int id)
	* @brief �w�肳�ꂽ m_pObjects ���������
	* @param[in] id_ m_pObjects �̎��ʔԍ����w��
	*/
	void Release(ObjID id_);

	// �e�V�[���̃I�u�W�F�N�g�����
	void ReleaseTitleObj();
	void ReleaseGameObj();

	// �e�V�[���̗̈���m��(new)
	void CreateTitleObj();
	void CreateGameObj();

	/**
	* @fn Draw()
	* @brief �S�Ă� m_pObjects ��`�悷��
	*/
	void Draw();

	/**
	* @fn HasOnMouse(ObjID id_)
	* @brief �w�肳�ꂽ m_pObjects �� HasOnMouse ���擾
	* @param[in] id_�@m_pObjects �̎��ʔԍ����w��
	* @return m_pObjects �Ƀ}�E�X���G��Ă���ꍇ true@n
	* m_pObjects �Ƀ}�E�X���G��Ă��Ȃ��ꍇ false@n
	*/
	bool HasOnMouse(ObjID id_);

	// Object�̃e�N�X�`����ǂݍ���
	void LoadTex();




private:

	//! ObjectID.h �Ŏw�肳�ꂽ���ʔԍ����A�C���X�^���X������
	Object* m_pObjects[static_cast<int>(ObjID::MAX_OBJECT_NUM)];

};
//! �^���I�ȃV���O���g�����v���g�^�C�v�錾
ObjectManager* ObjManager(); 

