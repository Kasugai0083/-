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
const Vec2 CANDLE_BIG_POS = { (960.f - CANDLE_BIG_SIZE.Width / 2), (140.f) };


//!< �낤����(��)
const Size CANDLE_SMALL_SIZE = { 12.f,64.f };
const Size CANDLE_SMALL_FRAME = { 64.f,64.f };
const Vec2 CANDLE_SMALL_POS = { (960.f - CANDLE_SMALL_SIZE.Width / 2),320.f };

//!< �낤����(��)
const Size CANDLE_EFFECT_SIZE = { 118.f,118.f };
const Size CANDLE_EFFECT_FRAME = { 128.f,128.f };
const Vec2 BIG_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),60.f };
const Vec2 SMALL_CANDLE_EFFECT_POS = { (960.f - CANDLE_EFFECT_SIZE.Width / 2),250.f };

//!< �낤����(�C��)
const Size CANDLE_STAND_SIZE = { 110.f,512.f };
const Size CANDLE_STAND_FRAME = { 256.f,512.f };
const Vec2 CANDLE_STAND_POS = { (960.f - (CANDLE_STAND_SIZE.Width / 2)), (640.f - (CANDLE_STAND_SIZE.Height / 2)) };

//!< ��(��)
const Size FIRE_BIG_SIZE = { 55.f,114.f };
const Size FIRE_BIG_FRAME = { 256.f,256.f };
const Vec2 FIRE_BIG_POS = { (960.f - (FIRE_BIG_SIZE.Width / 2)), (90.f - (FIRE_BIG_SIZE.Height / 2)) };

//!< ��(��)
const Size FIRE_SMALL_SIZE = { 15.f,32.f };
const Size FIRE_SMALL_FRAME = { 64.f,64.f };
const Vec2 FIRE_SMALL_POS = { (960.f - FIRE_SMALL_SIZE.Width / 2), 290.f };

//!< ����
const Size CRYSTAL_SIZE = { 256.f, 256.f };
const Size CRYSTAL_FRAME = { 256.f,256.f };
const Vec2 CRYSTAL_POS = { (710.f - CRYSTAL_SIZE.Width / 2), (770.f) };

//!< ����
const Size WATCH_SIZE = { 256.f, 256.f };
const Size WATCH_FRAME = { 256.f,256.f };
const Vec2 WATCH_POS = { (1210.f - CRYSTAL_SIZE.Width / 2), (770.f) };

#pragma endregion

#endif