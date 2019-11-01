#pragma once

#include "../Item.h"
#include "../../../Scene/Scene.h"
#include "../../../Engine/Calculation.h"
#include "../../../Timer/Timer.h"
#include "../../../Engine/Input.h"

const int c_Magnification = 6;

enum MusicBoxStep {
	STEP_1 = c_Magnification * 100,
	STEP_2 = c_Magnification * 200,
	STEP_3 = c_Magnification * 300,
	STEP_4 = c_Magnification * 400,
	STEP_5 = c_Magnification * 500,
	STEP_6 = c_Magnification * 600,
	STEP_7 = c_Magnification * 700,
	STEP_8 = c_Magnification * 800,
	END_STEP = c_Magnification * 900,

};

class Crystal : public Item {
public:

	void Init()override {

		m_Pos = CRYSTAL_POS;
		m_Size = CRYSTAL_SIZE;
		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);

	};
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = CRYSTAL_SIZE;
		LoadTexture("Res/Game/Item/Crystal.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameCrystalTex);
	}


private:

};

class MusicBox : public Item {
public:

	void Init()override {

		m_Pos = MUSICBOX_POS;
		m_Size = MUSICBOX_SIZE;
		LoadTexture("Res/Game/Item/MusicBox.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);

		LoadCircle();

	};
	void Init(Vec2 pos_) override {
		m_Pos = pos_;
		m_Size = MUSICBOX_SIZE;
		LoadTexture("Res/Game/Item/MusicBox.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMusicBoxTex);
	
		LoadCircle();

	}
	
	void Draw() override {
		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

		Lib::Texture polygon("hoge");

		if (m_OnMouse == true) {
			DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
		}

		DrawCircle();

	}

	void Update() override {

		static bool CountDown = false;

		if (GetCurrentSceneId() == CenterScene) {
			if (RectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
				m_OnMouse = true;
				if (OnMousePush(Left) == true) {
					TimerFunc()->CountDown(Timer::Id::MusicBox);
					CountDown = true;
				}
				else {
					CountDown = false;
				}
			}
			else {
				m_OnMouse = false;
				CountDown = false;
			}
		}

		if (CountDown == false) {
			TimerFunc()->Update(Timer::Id::MusicBox);
		}

	}

private:

#pragma region �N���X���Ŏg�p����֐��Q

	void LoadCircle() {
		LoadTexture("Res/Game/Center/Circle/Circle1.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle1Tex);
		LoadTexture("Res/Game/Center/Circle/Circle2.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle2Tex);
		LoadTexture("Res/Game/Center/Circle/Circle3.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle3Tex);
		LoadTexture("Res/Game/Center/Circle/Circle4.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle4Tex);
		LoadTexture("Res/Game/Center/Circle/Circle5.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle5Tex);
		LoadTexture("Res/Game/Center/Circle/Circle6.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle6Tex);
		LoadTexture("Res/Game/Center/Circle/Circle7.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle7Tex);
		LoadTexture("Res/Game/Center/Circle/Circle8.png", TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle8Tex);

	}

	const float MB_Pos_Adjustment_X = 15.0f;
	const float MB_Pos_Adjustment_Y = 100.0f;

	void DrawCircle() {

		if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_1) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle1Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_2) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle2Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_3) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle3Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_4) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle4Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_5) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle5Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_6) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle6Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_7) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle7Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= STEP_8) {
			DrawTexture((m_Pos.X + MB_Pos_Adjustment_X), (m_Pos.Y - MB_Pos_Adjustment_Y), GetTexture(TEXTURE_CATEGORY_CENTER, CenterCategoryTextureList::GameCircle8Tex));
		}
		else if (TimerFunc()->Get(Timer::Id::MusicBox) <= END_STEP) {
		}

	}

#pragma endregion

};

