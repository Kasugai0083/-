#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,			//工房
	STORE_ROOM_VIEW,		//物置
	RECEPTION_ROOM_VIEW,	//客間
	CHILD_ROOM_VIEW,		//子供部屋
	RIGHT_CORRIDOR_VIEW,	//右廊下
	LEFT_CORRIDOR_VIEW,		//左廊下
	NONE					//無とは一体。。。
};

class GameData {
public:
	enum SubGameScene {
		CENTER,
		LEFT,
		RIGHT,
		NONE
	};

	GameData() :
		m_ViewID(CENTER),
		m_ViewTmp(m_ViewID),
		m_MonitorID(MonitorView::WORKSHOP_VIEW),
		m_MonitorTmp(m_MonitorID)
	{
	}


	SubGameScene CurrentViewID() { return m_ViewID;	};
	const MonitorView CurrentMonitorID() { return m_MonitorID;};

	void SetViewID(SubGameScene id_) {	m_ViewID = id_;	};
	void SaveViewID() { m_ViewTmp = m_ViewID; };
	void LoadViewID() { m_ViewID = m_ViewTmp; }

	void SetMonitorID(MonitorView view_) {	m_MonitorID = view_; }
	void SaveMonitorID() { m_MonitorTmp = m_MonitorID; }
	void LoadMonitorID() { m_MonitorID = m_MonitorTmp; }

private:
	SubGameScene m_ViewID, m_ViewTmp;
	MonitorView m_MonitorID, m_MonitorTmp;
};

GameData* GameView();