/**
*	@file Timer.h
*	@author �t����
*	@brief �V�[����G�l�~�[�𐧌䂷�邽�߂̃^�C�}�[�N���X���`@n
*	�����I�ɍ����搶�̃V���O���g���𓱓�
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <string>

class Timer {

	//�V���O���g���f�U�C���p�^�[��
public:

	//���̂����֐�
	static void CreateInstance() {
		if (IsNull() == true) {
			p_Instance = new Timer;
		}
	}

	//���̂�j������֐�
	static void DestroyInstance() {
		if (IsNull() == false) {
			delete p_Instance;
		}
	}

	//���̂����݂��邩�m�F����ϐ�
	static bool IsNull() {
		return p_Instance == nullptr;
	}

	//���̂��擾����֐�
	static Timer* GetInstance() {
		return p_Instance;
	}

public:
	//�{����肽���֐��Q

	/**
	* �\���� TIMERS �̎��ʔԍ�
	*/
	enum class Id {
		SCENE,
		CLEAR,
		MUSICBOX,
		MAX_TIMERS
	};

	//! �^�C�}�[�ϐ����܂Ƃ߂��\����
	struct TIMERS {
		//! �V�[���؂�ւ��̃N�[���^�C��
		int m_Scene;	
		//! �N���A���Ԃ𐧌�
		int m_Clear;	
		//! �p�y�b�g�̋N���𐧌�
		int m_MusicBox;
	};

	/**
	* @fn void Init()
	* @brief TIMERS �� m_HourCount ��������
	*/
	void Init();

	/**
	* @fn void Init(Id id_)
	* @brief ���ʔԍ��Ŏw�肳�ꂽ�����o�ϐ���������
	* param[in] id_ ���ʔԍ�
	*/
	void Init(Id id_);

	/**
	* @fn int GetTime(Id id_)
	* @brief ���ʔԍ��Ŏw�肳�ꂽ�����o�ϐ����擾
	* @param[in] id_ ���ʔԍ�
	* @return ���ʔԍ��Ŏw�肳�ꂽ�����o�ϐ��̒l
	*/
	int GetTime(Id id_);


	/**
	* @fn void Draw()
	* @brief m_Clear ��`��@npocket_watch���}�E�X�I�[�o�[���Ă���ꍇ�Ɏ��Ԃ��\�������
	*/
	void Draw();

	/** 
	* @fn void Update()
	* @brief �����o�ϐ��̍X�V@nDraw �p�� m_Minute, m_Hour, m_Sample �ɕ��������
	*/
	void Update();

	/**
	* @fn int GetClearTime()
	* @brief �V�[���J�ڂɕK�v�Ȓl���擾
	* @return m_HourCount �̒l���擾
	*/
	int GetClearTime() { return m_HourCount; };

private:
	Timer() {}	//�R���X�g���N�^�}��
	~Timer() {}	//�f�X�g���N�^�}��

private:
	static Timer* p_Instance;	//�������g�̗B��̎���
private:
	//�{���g�������ϐ��Q

	//! TIMERS �̃C���X�^���X
	TIMERS Timers;		
	//! �N���A�ɕK�v�ȃJ�E���g
	int m_HourCount;	

	int m_Timemag;

	//! �f�W�^�����v���̕`��ɕK�v�ȕ�����
	std::string m_Minute, m_Hour, m_Sample; 

};



#endif