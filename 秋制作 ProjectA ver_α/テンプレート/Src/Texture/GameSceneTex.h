#pragma once

/** @brief �Q�[���{�җp�e�N�X�`���̃��X�g */
enum GameCategoryTextureList
{
	GameBlackFanceTex,	//!< ���t�B���^�[
	GameBlackFilterTex, //!< ���t�B���^�[(�S��)

	GameLeftShojiFrontTex,
	GameLeftShojiBackTex,
	GameLeftBlackTex,	//!< �Z���^�[�V�[���̍��e�N�X�`��

	GameRightShojiFrontTex,
	GameRightShojiBackTex,
	GameRightBlackTex,	//!< �Z���^�[�V�[���̍��e�N�X�`��

	GameFreeTex,

	GameTextureMax,			//!< ���X�g�ő吔
};

enum CenterCategoryTextureList {
	GameCenterBgTex,

	GameCenterDeskTex,	//!< �Z���^�[�V�[���̃f�X�N
	GameCenterBlackTex,	//!< �Z���^�[�V�[���̍��e�N�X�`��

	GameCenterFreddy,
	GameCenterPuppet,

	GameCircle1Tex,
	GameCircle2Tex,
	GameCircle3Tex,
	GameCircle4Tex,
	GameCircle5Tex,
	GameCircle6Tex,
	GameCircle7Tex,
	GameCircle8Tex,

	GameCenterTextureMax,			//!< ���X�g�ő吔
};

enum RightCategoryTextureList {
	GameRightBgTex,

	GameRightChicaTex,

	GameRightTextureMax,			//!< ���X�g�ő吔
};

enum LeftCategoryTextureList {
	GameLeftBgTex,
	GameLeftTextureMax,			//!< ���X�g�ő吔
};

enum MonitorCategoryTextureList {

	GameMonitorDustTex,	//!< �_�X�g

	GameMonitorSpownBgTex,
	GameMonitorLeftDuctBgTex,
	GameMonitorRightDuctBgTex,

	GameMonitorChildRoomBgTex,
	GameMonitorResptionRoomBgTex,
	GameMonitorStoreRoomBgTex,

	GameMonitorSpownUITex,
	GameMonitorLeftDuctUITex,
	GameMonitorRightDuctUITex,

	GameMonitorOnSpownUITex,
	GameMonitorOnLeftDuctUITex,
	GameMonitorOnRightDuctUITex,

	GameMonitorPlayerRoomUITex,

	GameMonitorFreddy,
	GameMonitorChicaTex,
	GameMonitorPuppetTex,

	GameMonitorTextureMax,			//!< ���X�g�ő吔
};

#define TEXTURE_CATEGORY_GAME (SceneId::GameScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_CENTER (SceneId::CenterScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_LEFT (SceneId::LeftScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_RIGHT (SceneId::RightScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_MONITOR (SceneId::MonitorScene)				//!< �Q�[���{�҃J�e�S���[