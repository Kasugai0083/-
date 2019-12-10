#ifndef ITEM_VALUE_H_
#define ITEM_VALUE_H_

/**
* item �̍��W���A�摜�T�C�Y�A�A�C�e���̑傫����ݒ�
*/

#include "../../Utility/Vec.h"
#include "../../Utility/Size.h"

#pragma region �Q�[�����I�u�W�F�N�g

//!<����ԍ��W
const Vec2 VOID_POS = { 9999.f, 9999.f };

//!< �낤�����i��j
const Size CANDLE_BIG_SIZE = { 46.f,256.f };
const Size CANDLE_BIG_FRAME = { 256.f,256.f };
const Vec2 CANDLE_BIG_LEFT_POS = { (1215.f - CANDLE_BIG_SIZE.Width / 2), (612.5f) };
const Vec2 CANDLE_BIG_RIGHT_POS = { (705.f - CANDLE_BIG_SIZE.Width / 2), (612.5f) };


//!< �낤����(��)
const Size CANDLE_SMALL_SIZE = { 12.f,77.f };
const Size CANDLE_SMALL_FRAME = { 32.f,128.f };
const Vec2 CANDLE_SMALL_POS = { (960.f - CANDLE_SMALL_SIZE.Width / 2), 635.f };

//!< �낤����(��)
const Size CANDLE_EFFECT_SIZE = { 118.f,118.f };
const Size CANDLE_EFFECT_FRAME = { 128.f,128.f };
const Vec2 BIG_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2), 60.f };
const Vec2 SMALL_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2), 250.f };

//!< �낤����(�C�䏬)
const Size CANDLE_STAND_CENTER_SIZE = { 84.f,162.f };
const Size CANDLE_STAND_CENTER_FRAME = { 128.f,256.f };
const Vec2 CANDLE_STAND_CENTER_POS = { (960.f - 35.f), (790.f - (CANDLE_STAND_CENTER_SIZE.Height / 2)) };

//!< �낤����(�C��E)
const Size CANDLE_STAND_RIGHT_SIZE = { 70.f, 135.f };
const Size CANDLE_STAND_RIGHT_FRAME = { 128.f, 256.f };
const Vec2 CANDLE_STAND_RIGHT_POS = { (720.f - (CANDLE_STAND_RIGHT_SIZE.Width / 2)), (930.f - (CANDLE_STAND_RIGHT_SIZE.Height / 2)) };
//!< �낤����(�C�䍶)
const Size CANDLE_STAND_LEFT_SIZE = { 70.f, 135.f };
const Size CANDLE_STAND_LEFT_FRAME = { 128.f, 256.f };
const Vec2 CANDLE_STAND_LEFT_POS = { (1200.f - (CANDLE_STAND_LEFT_SIZE.Width / 2)), (930.f - (CANDLE_STAND_LEFT_SIZE.Height / 2)) };

//! ��(����)
const Size FIRE_SIZE = { 12.f, 32.f };
const Size FIRE_FRAME = { 32.f, 32.f };

//!< ��(�E)
const Vec2 FIRE_BIG_RIGHT_POS = { (730.f - (FIRE_SIZE.Width / 2)), (510.f) };
//!< ��(��)
const Vec2 FIRE_BIG_LEFT_POS = { (1210.f - (FIRE_SIZE.Width / 2)), (510.f) };
//!< ��(��)
const Vec2 FIRE_SMALL_POS = { (960.f - FIRE_SIZE.Width / 2), 640 - FIRE_SIZE.Height };

//!< ����
const Size CRYSTAL_SIZE = { 256.f, 256.f };
const Size CRYSTAL_FRAME = { 256.f,256.f };
const Vec2 CRYSTAL_POS = { (710.f - CRYSTAL_SIZE.Width / 2), (770.f) };

//!< ���v
const Size WATCH_SIZE = { 256.f, 256.f };
const Size WATCH_FRAME = { 256.f,256.f };
const Vec2 WATCH_POS = { (1210.f - CRYSTAL_SIZE.Width / 2), (770.f) };

#pragma endregion

#endif