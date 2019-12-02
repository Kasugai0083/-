#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Scene/GameScene/GameData.h"
#include "../../../Engine/Input.h"
#include "../../../Engine/Calculation.h"

enum class CandleType {
	CENTER_CANDLE,
	LEFT_CANDLE,
	RIGHT_CANDLE,
	OTHER
};

const float CANDLE_MELT_BIG = 0.2f;
const float CANDLE_MELT_SMALL = 0.1f;

const float MELT_RATIO = 0.001f;

//struct StatusSave{
//	Size 
//};

class Candle : public Item {
public:

	Candle(CandleType type_)
	{
		m_Type = type_;
		m_Time = 0;
		m_CandleHp = 1.f;
		m_HeightRatio = NULL;

	};
	void Init()override {};
	void Init(object::ObjectId id_)override;

	void Init(object::ObjectId id_, Vec2 pos_) override;

	bool HasLight(CandleLight cl_)override;

	void InitCount()override;
	void Update()override;

	void Draw() override;

	Vec2 GetPos()override;
	float GetHp()override;
	float GetRatio()override;

private:

	CandleType m_Type;
	static int m_Count;
	static Candller m_Candller;

	float m_CandleHp;
	float m_HeightRatio;

	static Candller m_Death;
	int m_Time;

};

