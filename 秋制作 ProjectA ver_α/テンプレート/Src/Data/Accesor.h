#ifndef ACCESOR_H_
#define ACCESOR_H_

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