#include "Item.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"


Item::Item() {
	m_Pos = { 0.f, 0.f };
	m_Size = { 0.f, 0.f };
	m_OnMouse = false;
}

void Item::Draw() {

	DrawTexture(m_Pos.X, m_Pos.Y, m_pTex);

	Lib::Texture polygon("hoge");

	if (m_OnMouse == true) {
		DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
	}

}

void Item::Update() {

	if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
		m_OnMouse = true;
	}
	else {
		m_OnMouse = false;
	}
}

void Item::Update2() {

	m_IsDeath = true;

	if (GetCurrentSceneId() == SceneId::GameScene) {
		switch (GameView()->CurrentViewID())
		{
		case GameData::SubGameScene::CENTER:

			break;
		case GameData::SubGameScene::LEFT:
			
			break;
		case GameData::SubGameScene::RIGHT:
			
			break;
		default:
			break;
		}
	}
}


bool Item::HasOnMouse() {
	return m_OnMouse;
}

void Item::SetPosition(Vec2 pos_) {
	m_Pos = pos_;
}