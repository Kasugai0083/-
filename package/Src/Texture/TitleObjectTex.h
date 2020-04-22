/**
*	@file TitleObjectTex.h
*	@author ���n
*			�t����
*	@brief �^�C�g���Ŏg�p����I�u�W�F�N�g�̉摜���X�g
*/

#ifndef TITLE_OBJECTTEX_H_
#define TITLE_OBJECTTEX_H_

#include "GameSceneTex.h"

enum TitleObjectCategoryTextureList {

	// TITLE_SCENE_OBJECT
	OBJECT_TITLELOGO_TEX,

	OBJECT_NEWGAME_TEX,
	OBJECT_NEWGAME_ONHIT_TEX,

	OBJECT_CONTINUE_TEX,
	OBJECT_CONTINUE_ONHIT_TEX,

	OBJECT_DAYS_TEX,
	OBJECT_DAYS_ONHIT_TEX,

	TITLE_OBJECT_TEXTURE_MAX,			//!< ���X�g�ő吔
};

#define TEXTURE_CATEGORY_TITLE_OBJECT (SceneId::TitleObjectScene)				//!< �Q�[���{�҃J�e�S���[

#endif