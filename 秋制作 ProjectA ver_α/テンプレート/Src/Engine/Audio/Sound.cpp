#include"../Audio/Sound.h"

DirectSound::DirectSound(HWND hwnd)
{
	// �C���^�[�t�F�[�X�̍쐬�Ə�����
	// �쐬��͂�����SetCooperativeLevel�֐��ŋ������x���̐ݒ���s��Ȃ��Ƃ����Ȃ�
	DirectSoundCreate8(nullptr, &m_pDSound8, nullptr);
	// �������x���̐ݒ�
	// ���b�N���ꂽ�o�b�t�@������ꍇ�Ăяo���Ȃ�
	m_pDSound8->SetCooperativeLevel(hwnd, DSSCL_NORMAL);

	// �V�����o�b�t�@�[�I�u�W�F�N�g�̓�����ݒ肷��\���̂̍쐬�Ə�����
	DSBUFFERDESC desc = {};
	// �\���̂̃T�C�Y��
	desc.dwSize = sizeof(DSBUFFERDESC);
	// �o�b�t�@�[�I�u�W�F�N�g�̔\�͂̎w�肷��t���O(�����w��\)
	// �����( DSBCAPS_PRIMARYBUFFER = ���̃o�b�t�@���v���C�}���o�b�t�@
	//		   DSBCAPS_CTRLVOLUME    = ���̃o�b�t�@�ɂ̓{�����[������@�\������
	desc.dwFlags = DSBCAPS_PRIMARYBUFFER | DSBCAPS_CTRLVOLUME;
	// �V�����o�b�t�@�T�C�Y�̎w��
	// �����dwFlags��DSBCAPS_PRIMARYBUFFER���w�肵�Ă��邽�߁u0�v�ɂ���
	desc.dwBufferBytes = 0;
	// 0���w��
	desc.dwReserved = 0;
	// Wave�t�H�[�}�b�g�̎w��
	// �����dwFlags��DSBCAPS_PRIMARYBUFFER���w�肵�Ă��邽�߁uNULL�v�ɂ���
	desc.lpwfxFormat = nullptr;
	// �悭�킩��Ȃ����A
	// dwFlags��DSBCAPS_CTRL3D���w�肵�Ă��Ȃ��ꍇ�uGUID_NULL�v
	desc.guid3DAlgorithm = GUID_NULL;

	// ��ō����DSBUFFERDESC�\���̏����g��
	// �T�E���h�o�b�t�@�̍쐬���s��
	m_pDSound8->CreateSoundBuffer(&desc, &m_pPrimaryBuffer, nullptr);
}


IDirectSoundBuffer8* DirectSound::LoadWaveFile(std::string file_name_)
{
	// �}���`���f�B�A�̓��o�͍\����
	// Handle Multi Media Input Output ���Ǝv�����Ԃ�
	HMMIO hmmio = nullptr;
	// �悭�킩��Ȃ���WAVA�t�@�C���̎��͕K�v�݂���
	MMIOINFO mminfo = {};
	// �t�@�C���̃I�[�v��
	hmmio = mmioOpen((LPSTR)file_name_.c_str(), &mminfo, MMIO_READ);

	// �t�@�C���̃I�[�v���Ɏ��s�����ꍇ
	if (!hmmio) {
		MessageBox(0, "wave�t�@�C���̃I�[�v���Ɏ��s", 0, MB_OK);
		return nullptr;
	}

	// �֐����߂����^�[���R�[�h�������ϐ��H
	MMRESULT result;
	// 
	MMCKINFO rif_chunk;
	// 
	rif_chunk.fccType = mmioFOURCC('W', 'A', 'V', 'E');
	// ���t�`�����N�̌���
	result = mmioDescend(hmmio, &rif_chunk, NULL, MMIO_FINDRIFF);

	// ���t�`�����N�̌����Ɏ��s�����ꍇ
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	MMCKINFO fmt_chunk;
	fmt_chunk.ckid = mmioFOURCC('f', 'm', 't', ' ');
	// �t�H�[�}�b�g�`�����N�̌���
	result = mmioDescend(hmmio, &fmt_chunk, &rif_chunk, MMIO_FINDCHUNK);

	// �t�H�[�}�b�g�`�����N�̌����Ɏ��s�����ꍇ
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// ������`�����l�����̏����i�[����
	WAVEFORMATEX format;
	DWORD fmsize = fmt_chunk.cksize;
	// �t�@�C�����̃f�[�^��ǂݍ���
	if (mmioRead(hmmio, (HPSTR)& format, fmsize) != fmsize) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// �f�[�^�����̂��߈�x�߂�
	mmioAscend(hmmio, &fmt_chunk, 0);

	MMCKINFO data_chunk;
	data_chunk.ckid = mmioFOURCC('d', 'a', 't', 'a');
	// �f�[�^�`�����N�̌���
	result = mmioDescend(hmmio, &data_chunk, &rif_chunk, MMIO_FINDCHUNK);
	// �f�[�^�`�����N�̌����Ɏ��s�����ꍇ
	if (result != MMSYSERR_NOERROR) {
		mmioClose(hmmio, 0);
		return nullptr;
	}

	// �g�`�f�[�^�̏���ۑ�����
	DWORD data_size = data_chunk.cksize;
	BYTE* pwav_data = new BYTE[data_chunk.cksize];
	// �g�`�f�[�^�̓ǂݎ��
	if (mmioRead(hmmio, (HPSTR)pwav_data, data_chunk.cksize) != data_chunk.cksize) {
		delete[] pwav_data;
		return nullptr;
	}

	// ����ǂݍ���
	mmioClose(hmmio, 0);

	// �Z�J���_���o�b�t�@�̐ݒ�
	DSBUFFERDESC desc = {};
	desc.dwSize          = sizeof(DSBUFFERDESC);
	desc.dwFlags         = DSBCAPS_CTRLVOLUME | DSBCAPS_GLOBALFOCUS |
						   	 DSBCAPS_CTRLPAN | DSBCAPS_CTRLFREQUENCY;
	desc.dwBufferBytes   = data_size;
	desc.dwReserved      = 0;
	desc.lpwfxFormat     = &format;
	desc.guid3DAlgorithm = GUID_NULL;

	IDirectSoundBuffer* pbuf = 0;
	m_pDSound8->CreateSoundBuffer(&desc, &pbuf, nullptr);

	//�߂�l��IDirectSoundBuffer�ׁ̈AIDirectSoundBuffer8�ɖ߂�
	pbuf->QueryInterface(IID_IDirectSoundBuffer8, (void**)& m_pSecBuffer);
	pbuf->Release();


	// WAV�f�[�^��������
	LPVOID write_data;
	DWORD  len;
	m_pSecBuffer->Lock(
		0,						// ���b�N�J�n�ʒu
		0,						// �������T�C�Y
		&write_data,			// ���b�N�ʒu�̃|�C���^
		&len,					// �傫��
		NULL,					// �͈͂𒴂����ꍇ�̃������̈�̎w��
		NULL,
		DSBLOCK_ENTIREBUFFER	// ���b�N����傫���̎w��
	);

	memcpy(write_data, pwav_data, len);
	m_pSecBuffer->Unlock(write_data, len, nullptr, 0);
	// ���������폜
	delete[] pwav_data;

	if (m_pSecBuffer == nullptr) {
		MessageBox(0, "wave�t�@�C���̓ǂݍ��݂Ɏ��s", 0, MB_OK);
	}

	return m_pSecBuffer;
}


DirectSound::~DirectSound()
{
	m_pDSound8->Release();
	m_pPrimaryBuffer->Release();
}