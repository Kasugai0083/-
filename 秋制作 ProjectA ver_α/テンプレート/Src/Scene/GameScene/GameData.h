#pragma once

enum class SubGameScene {
	CENTER_VIEW,			//�v���C���[���[������
	LEFT_VIEW,				//�v���C���[���[����
	RIGHT_VIEW,				//�v���C���[���[���E
	WORKSHOP_VIEW,			//�H�[
	STORE_ROOM_VIEW,		//���u
	RECEPTION_ROOM_VIEW,	//�q��
	CHILD_ROOM_VIEW,		//�q������
	RIGHT_CORRIDOR_VIEW,	//�E�L��
	LEFT_CORRIDOR_VIEW,		//���L��
};
class GameData {
public:


	//GameData() :
	//	m_ViewID(CENTER),
	//	m_ViewTmp(CENTER),
	//	m_MonitorID(MonitorView::NONE),
	//	m_MonitorTmp(MonitorView::WORKSHOP_VIEW)
	//{
	//}


	//SubGameScene CurrentViewID() { return m_ViewID;	};
	//const MonitorView CurrentMonitorID() { return m_MonitorID;};

	//void SetViewID(SubGameScene id_) {	m_ViewID = id_;	};

	//void SaveViewID() { 
	//	if (m_ViewID != NONE) {
	//		m_ViewTmp = m_ViewID;
	//	}
	//};

	//void LoadViewID() { m_ViewID = m_ViewTmp; }

	//void SetMonitorID(MonitorView view_) {	m_MonitorID = view_; }

	//void SaveMonitorID() { 
	//	if (m_MonitorID != MonitorView::NONE) {
	//		m_MonitorTmp = m_MonitorID;
	//	}
	//}

	//void LoadMonitorID() { m_MonitorID = m_MonitorTmp; }

private:
	//SubGameScene m_ViewID, m_ViewTmp;
	//MonitorView m_MonitorID, m_MonitorTmp;
};

GameData* GameView();