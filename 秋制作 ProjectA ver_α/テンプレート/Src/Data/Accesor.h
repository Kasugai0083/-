#ifndef ACCESOR_H_
#define ACCESOR_H_

/**
*	@file Botan.h
*	@author �t����
*	@brief �L�����N�^�[�u���O�v���Ǘ�����N���X������
*/

#include "../Utility/SingletonTemplate.h"

class Accesor : public Singleton<Accesor>
{
public:

protected:

private:

	friend Singleton<Accesor>;

	Accesor() {};
	virtual ~Accesor() {};

	//�R�s�[�R���X�g���N�^�̋֎~
	Accesor(const Accesor&) = delete;
	Accesor& operator=(const Accesor&) = delete;
	//���[�u�R���X�g���N�^�̋֎~
	Accesor(const Accesor&&) = delete;
	Accesor& operator=(const Accesor&&) = delete;

};

#endif