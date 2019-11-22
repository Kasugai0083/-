#pragma once

/** @brief �Q�[���{�җp�e�N�X�`���̃��X�g */
enum GameCategoryTextureList
{
	GameMaskTex,				//!< �w�i

	//item
	GameCandleBigTex,
	GameCandleSmallTex,
	GameCandleStandTex,
	GameCandleEffectTex,
	GameFireBigTex,
	GameFireSmallTex,
	GameCrystalTex,
	GameMusicBoxTex,

	GameLeftShojiFrontTex,
	GameLeftShojiBackTex,
	GameRightShojiFrontTex,
	GameRightShojiBackTex,

	GameFreeTex,

	GameTextureMax,			//!< ���X�g�ő吔
};

enum CenterCategoryTextureList {
	GameCenterBgTex,

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

	GameMonitorMapTex,

	GameMonitorButtom1Tex,
	GameMonitorButtom2Tex,
	GameMonitorButtom3Tex,
	GameMonitorButtom4Tex,
	GameMonitorButtom5Tex,
	GameMonitorButtom6Tex,

	GameMonitorOnButtom1Tex,
	GameMonitorOnButtom2Tex,
	GameMonitorOnButtom3Tex,
	GameMonitorOnButtom4Tex,
	GameMonitorOnButtom5Tex,
	GameMonitorOnButtom6Tex,




	GameMonitorTextureMax,			//!< ���X�g�ő吔
};

#define TEXTURE_CATEGORY_GAME (SceneId::GameScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_CENTER (SceneId::CenterScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_LEFT (SceneId::LeftScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_RIGHT (SceneId::RightScene)				//!< �Q�[���{�҃J�e�S���[
#define TEXTURE_CATEGORY_MONITOR (SceneId::MonitorScene)				//!< �Q�[���{�҃J�e�S���[