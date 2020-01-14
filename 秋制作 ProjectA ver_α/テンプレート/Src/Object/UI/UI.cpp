#include "UI.h"
#include "../../Engine/Input.h"
#include "../../Engine/Calculation.h"
#include "../../Texture/Texture.h"
#include "../../Engine/Graphics.h"
#include "../ObjectManager.h"
#include "..//..//Character/CharacterManager.h"
#include "../../Data/Days/DayController.h"

Object* g_pTitleLogo;


void UI::Init(){

	m_IsDeath = true;

	switch (m_Id) {
	case ObjID::TITLE_LOGO:
		m_Pos = TITLE_LOGO_POS;
		m_Size = TITLE_LOGO_SIZE;
		LoadTexture("Res/Title/TitleLogo.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleLogoTex);
		break;
	case ObjID::BUTTON_NEW_GAME:
		m_Pos = NEWGAME_UI_POS;
		m_Size = NEWGAME_UI_SIZE;
		LoadTexture("Res/Title/TitleMenuStart.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		LoadTexture("Res/Title/titlemenu_start_effect.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameOnHitUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameUITex);
		m_OnHitTex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleNewGameOnHitUITex);
		break;
	case ObjID::BUTTON_CONTINUE:
		m_Pos = CONTINUE_UI_POS;
		m_Size = CONTINUE_UI_SIZE;

		LoadTexture("Res/Title/TitleMenuHelp.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);
		LoadTexture("Res/Title/titlemenu_help_effect.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueOnHitUITex);

		m_Tex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueUITex);		
		m_OnHitTex = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleContinueOnHitUITex);

		if (DayManager()->GetCurrentDays() == Days::DAY_1) {
			// 一日目の画像
			LoadTexture("Res/Title/itiyame_UI.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysUITex);
			LoadTexture("Res/Title/itiyame_effect.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysOnHitUITex);
		}
		else if (DayManager()->GetCurrentDays() == Days::DAY_2) {
			// 二日目の画像
			LoadTexture("Res/Title/niyame_UI.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysUITex);
			LoadTexture("Res/Title/niyame_effect.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysOnHitUITex);
		}
		else if (DayManager()->GetCurrentDays() == Days::DAY_3) {
			// 三日目の画像
			LoadTexture("Res/Title/sannyame_UI.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysUITex);
			LoadTexture("Res/Title/sannyame_effect.png", TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysOnHitUITex);
		}

		m_Tex2 = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysUITex);
		m_OnHitTex2 = GetTexture(TEXTURE_CATEGORY_TITLE, TitleCategoryTextureList::TitleDaysOnHitUITex);

		break;	
	case ObjID::GAME_BASE_UI:
		m_Pos = GAME_BASE_UI_POS;
		m_Size = GAME_BASE_UI_SIZE;
		LoadTexture("Res/Game/UI/base_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMainUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMainUITex);
		break;
	case ObjID::BUTTON_CONTROL_UI:
		m_Pos = GAME_CONTROL_UI_POS;
		m_Size = GAME_CONTROL_UI_SIZE;
		LoadTexture("Res/Game/UI/control_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameControlUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameControlUITex);
		break;
	case ObjID::BUTTON_ON_CONTROL_UI:
		m_Pos = GAME_CONTROL_UI_POS;
		m_Size = GAME_CONTROL_UI_SIZE;
		LoadTexture("Res/Game/UI/onhit_control_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitControlUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameOnHitControlUITex);
		break;
	case ObjID::MO_MASK_UI:
		m_Pos = GAME_MASK_UI_POS;
		m_Size = GAME_MASK_UI_SIZE;
		LoadTexture("Res/Game/UI/mask_ui_bar.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameMaskUITex);
		break;
	case ObjID::DESCRIPTION_UI:
		m_Pos = GAME_DESCRIPTION_UI_POS;
		m_Size = GAME_DESCRIPTION_UI_SIZE;
		LoadTexture("Res/Game/UI/control_ui_main.png", TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameDescriptionUITex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_GAME, GameCategoryTextureList::GameDescriptionUITex);
		break;
	case ObjID::BUTTON_WORKSHOP:
		m_Pos = WORKSHOP_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom1Tex);
		break;
	case ObjID::BUTTON_STORE_ROOM:
		m_Pos = STORE_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom2Tex);
		break;
	case ObjID::BUTTON_RECEPTION_ROOM:
		m_Pos = RECEPTION_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom3Tex);
		break;
	case ObjID::BUTTON_CHILD_ROOM:
		m_Pos = CHILD_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom4Tex);
		break;
	case ObjID::BUTTON_RIGHT_CORRIDOR:
		m_Pos = RIGHT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom5Tex);
		break;
	case ObjID::BUTTON_LEFT_CORRIDOR:
		m_Pos = LEFT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorButtom6Tex);
		break;
	case ObjID::BUTTON_ON_WORKSHOP:
		m_Pos = WORKSHOP_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom1Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom1Tex);
		break;
	case ObjID::BUTTON_ON_STORE_ROOM:
		m_Pos = STORE_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom2Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom2Tex);
		break;
	case ObjID::BUTTON_ON_RECEPTION_ROOM:
		m_Pos = RECEPTION_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom3Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom3Tex);
		break;
	case ObjID::BUTTON_ON_CHILD_ROOM:
		m_Pos = CHILD_ROOM_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom4Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom4Tex);
		break;
	case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
		m_Pos = RIGHT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom5Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom5Tex);
		break;
	case ObjID::BUTTON_ON_LEFT_CORRIDOR:
		m_Pos = LEFT_CORRIDOR_BUTTON_POS;
		m_Size = MONITOR_BUTTON_SIZE;
		LoadTexture("Res/Game/Monitor/MonitorUI/on_map_UI_crystal.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom6Tex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorOnButtom6Tex);
		break;
	case ObjID::MONITOR_MAP:
		m_Pos = MAP_UI_POS;
		m_Size = {0.f,0.f};
		LoadTexture("Res/Game/Monitor/MonitorUI/map.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapTex);
		break;	
	case ObjID::MONITOR_PLAYER:
		m_Pos = MAP_PLAYER_UI_POS;
		m_Size = {0.f,0.f};
		LoadTexture("Res/Game/Monitor/MonitorUI/map_UI_pin.png", TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapPlayerTex);
		m_Tex = GetTexture(TEXTURE_CATEGORY_MONITOR, MonitorCategoryTextureList::GameMonitorMapPlayerTex);
		break;	
	}

};

void UI::Draw(){

	if (m_IsDeath == false) {

		switch (m_Id)
		{
		case ObjID::BUTTON_NEW_GAME:
			if (m_OnMouse == true) {
				DrawTexture(m_Pos.X, m_Pos.Y, m_OnHitTex);
			}
			break;
		case ObjID::BUTTON_CONTINUE:
			if (m_OnMouse == true) {
				DrawTexture(m_Pos.X, m_Pos.Y, m_OnHitTex);
				DrawTexture(DAYS_UI_POS.X, DAYS_UI_POS.Y, m_OnHitTex2);
			}

			DrawTexture(DAYS_UI_POS.X, DAYS_UI_POS.Y, m_Tex2);

			break;
		default:
			break;
		}

		DrawTexture(m_Pos.X, m_Pos.Y, m_Tex);

		Lib::Texture polygon("hoge");

		switch (m_Id) {
		case ObjID::MO_MASK_UI:
			if (m_OnMouse == true) {
				DrawAlphaBox2D(polygon, m_Pos, m_Size, D3DXCOLOR(0.f, 0.f, 0.f, 0.5f));
			}
			break;
		}

	}
		
}

void UI::Update() {

	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (GetCurrentSceneId() == SceneId::TitleScene) {
		switch (m_Id)
		{
		case ObjID::TITLE_LOGO:
		case ObjID::BUTTON_NEW_GAME:
		case ObjID::BUTTON_CONTINUE:
			m_IsDeath = false;
			break;
		default:
			m_IsDeath = true;
			break;
		}
	}
	else if (GetCurrentSceneId() == SceneId::GameScene) {
		if (pPlayer->HasMonitor() == false) {
			switch (m_Id)
			{
			case ObjID::GAME_BASE_UI:
			case ObjID::BUTTON_CONTROL_UI:
			case ObjID::MO_MASK_UI:
				m_IsDeath = false;
				break;
			default:
				m_IsDeath = true;
				break;
			}
		}else {
			switch (m_Id)
			{
			case ObjID::BUTTON_WORKSHOP:
			case ObjID::BUTTON_STORE_ROOM:
			case ObjID::BUTTON_RECEPTION_ROOM:
			case ObjID::BUTTON_CHILD_ROOM:
			case ObjID::BUTTON_RIGHT_CORRIDOR:
			case ObjID::BUTTON_LEFT_CORRIDOR:
			case ObjID::BUTTON_ON_WORKSHOP:
			case ObjID::BUTTON_ON_STORE_ROOM:
			case ObjID::BUTTON_ON_RECEPTION_ROOM:
			case ObjID::BUTTON_ON_CHILD_ROOM:
			case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
			case ObjID::BUTTON_ON_LEFT_CORRIDOR:
			case ObjID::MONITOR_MAP:
			case ObjID::MONITOR_PLAYER:
				m_IsDeath = false;
				break;
			default:
				m_IsDeath = true;
				break;
			}

			switch (pPlayer->CurrentViewID())
			{
			case SubGameScene::WORKSHOP_VIEW:

				switch (m_Id)
				{
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
					break;
				default:
					break;
				}
				break;
			case SubGameScene::STORE_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
					break;
				default:
					break;
				}
				break;
			case SubGameScene::RECEPTION_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case SubGameScene::CHILD_ROOM_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case SubGameScene::RIGHT_CORRIDOR_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_LEFT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			case SubGameScene::LEFT_CORRIDOR_VIEW:
				switch (m_Id)
				{
				case ObjID::BUTTON_ON_WORKSHOP:
				case ObjID::BUTTON_ON_STORE_ROOM:
				case ObjID::BUTTON_ON_RECEPTION_ROOM:
				case ObjID::BUTTON_ON_CHILD_ROOM:
				case ObjID::BUTTON_ON_RIGHT_CORRIDOR:
					m_IsDeath = true;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
	UpdateGameUI();

	if (m_IsDeath == false) {
		if (HasRectangleHit(GetMousePos().X, GetMousePos().Y, m_Pos.X, m_Pos.Y, (m_Pos.X + m_Size.Width), (m_Pos.Y + m_Size.Height)) == true) {
			m_OnMouse = true;
		}
		else {
			m_OnMouse = false;
		}
	}
}



void UI::UpdateGameUI() {

	static bool HasPull = false;
	Character* pPlayer = g_Manager.GetCharacter(PLAYER);

	if (GetCurrentSceneId() == SceneId::GameScene) {

		if (pPlayer->HasMonitor() == false) {
			if (HasPull == true) {
				switch (m_Id) {
				case ObjID::BUTTON_ON_CONTROL_UI:
					m_IsDeath = false;
					break;
				case ObjID::DESCRIPTION_UI:
					m_IsDeath = false;
					break;
				}
			}

			if (m_OnMouse == true) {
				switch (m_Id)
				{
				case ObjID::BUTTON_CONTROL_UI:
					if (OnMouseDown(Left) == true) {
						HasPull = true;
					}
					break;
				case ObjID::MO_MASK_UI:
					m_HasMask = true;
					break;

				}
			}
			else {

				switch (m_Id)
				{
				case ObjID::BUTTON_CONTROL_UI:
					HasPull = false;
					break;
				case ObjID::MO_MASK_UI:
					m_HasMask = false;
					break;
				}
			}
		}
		else {
			switch (m_Id)
			{
			case ObjID::BUTTON_CONTROL_UI:
				HasPull = false;
				break;
			case ObjID::MO_MASK_UI:
				m_HasMask = false;
				break;
			}
		}

	}
}