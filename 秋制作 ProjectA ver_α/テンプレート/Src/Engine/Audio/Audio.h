#ifndef AUDIO_H_
#define AUDIO_H_

#include <string>
#include <unordered_map>
#include "Sound.h"
#include "../../Engine/Window.h"

/*
	�I�[�f�B�I�v���C���[�N���X
*/
class AudioPlayer
{
public:
	static AudioPlayer* GetInstance(HWND hwnd_ = nullptr) {
		static AudioPlayer instance(hwnd_);
		return &instance;
	}

	/*
		Wave�t�@�C���̓ǂݍ���
	*/
	bool Load(std::string alias_, std::string file_name_);

	/*
		�Đ�����
	*/
	void Play(std::string alias_, int volume = -1000, bool is_loop = false);

	/*
		��~
	*/
	void Stop(std::string alias_);

	/*
		�{�����[���ݒ�
	*/
	void SetVolume(std::string alias_, int volume_);

	// �������
	void Release(std::string alias_);


private:
	// �R���X�g���N�^
	AudioPlayer(HWND hwnd) {
		// �Đ���̃E�B���h�E�n���h�����擾
		m_pSound = new DirectSound(hwnd);
		ZeroMemory(&m_SoundData, 0, sizeof(IDirectSoundBuffer8));
	}

	/*
		�T�E���h�t�@�C���̌���
	*/
	IDirectSoundBuffer8* Find(std::string alias_);

	/*
		�f�X�g���N�^
	*/
	~AudioPlayer();

private:
	//
	DirectSound* m_pSound;
	// �Z�J���_���o�b�t�@�[
	std::unordered_map<std::string, IDirectSoundBuffer8*> m_SoundData;
	// �f�[�^�t�H�[�}�b�g�\����
	WAVEFORMATEX m_Format;
	// wave�t�@�C���̃T�C�Y
	DWORD        m_Size;

};


#endif