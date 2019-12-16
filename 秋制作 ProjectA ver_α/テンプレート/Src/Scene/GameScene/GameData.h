#pragma once

enum class MonitorView {
	WORKSHOP_VIEW,			//�H�[
	STORE_ROOM_VIEW,		//���u
	RECEPTION_ROOM_VIEW,	//�q��
	CHILD_ROOM_VIEW,		//�q������
	RIGHT_CORRIDOR_VIEW,	//�E�L��
	LEFT_CORRIDOR_VIEW,		//���L��
	NONE					//���Ƃ͈�́B�B�B
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