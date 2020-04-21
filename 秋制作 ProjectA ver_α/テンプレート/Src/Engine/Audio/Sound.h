#ifndef SOUND_H_
#define SOUND_H_

/**
*	@file Botan.h
*	@author ���{
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

#include <dsound.h>
#include <string>

/*
	�T�E���h�N���X
*/
class DirectSound
{
public:
	/*
		�R���X�g���N�^
		�C���^�[�t�F�[�X�̍쐬�Ə�����
		�T�E���h�o�b�t�@�̍쐬�Ə�����
	*/
	DirectSound(HWND hwnd = nullptr);

	/*
		Wave�t�@�C���̓ǂݍ��݊֐�
		�����Ƀt�@�C���̃p�X������
		��:
			LoadWaveFile("Res/Sound/hoge.wave");
	*/
	IDirectSoundBuffer8* LoadWaveFile(std::string file_name_);

	/*
		�f�X�g���N�^
		�C���^�[�t�F�[�X�̉��
		�T�E���h�o�b�t�@�̉��
	*/
	~DirectSound();

private:
	IDirectSound8*		 m_pDSound8;		// �T�E���h�C���^�[�t�F�[�X
	IDirectSoundBuffer*  m_pPrimaryBuffer;	// �v���C�}���[�o�b�t�@�[
	IDirectSoundBuffer8* m_pSecBuffer;		// 

};


#endif