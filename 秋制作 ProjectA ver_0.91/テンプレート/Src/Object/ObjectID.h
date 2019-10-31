#ifndef OBJECT_ID_H_
#define OBJECT_ID_H_

namespace object {

	enum ObjectId {
		//UI
		TITLE_LOGO,
		NEW_GAME,
		CONTINUE,
		MONITOR_SPOWN,
		BLACK_MONITOR_SPOWN,
		LEFT_DUCT,
		BLACK_LEFT_DUCT,
		RIGHT_DUCT,
		BLACK_RIGHT_DUCT,
		PLAYER_ROOM,
		CLEAR_LOGO,

		//Item
		CANDLE_BIG,
		CANDLE_SMALL,
		CANDLE_EFFECT,
		CANDLE_STAND,
		FIRE_BIG,
		FIRE_SMALL,
		CRYSTAL,
		MUSICBOX,

		MAX_OBJECT_NUM
	};

	//enum UserInterfaceId {
	//	//UI
	//	TITLE_LOGO,
	//	NEW_GAME,
	//	CONTINUE,
	//	MONITOR_SPOWN,
	//	BLACK_MONITOR_SPOWN,
	//	LEFT_DUCT,
	//	BLACK_LEFT_DUCT,
	//	RIGHT_DUCT,
	//	BLACK_RIGHT_DUCT,
	//	PLAYER_ROOM,
	//	CLEAR_LOGO,

	//	MAX_UI_NUM,
	//};

	//enum ItemId {
	//	//Item
	//	CANDLE_BIG,
	//	CANDLE_SMALL,
	//	CANDLE_EFFECT,
	//	CANDLE_STAND,
	//	FIRE_BIG,
	//	FIRE_SMALL,
	//	CRYSTAL,
	//	MASK,
	//	MUSICBOX,

	//	MAX_ITEM_NUM,
	//};

	//const int MAX_OBJECT_NUM = MAX_UI_NUM + MAX_ITEM_NUM;

}
#endif