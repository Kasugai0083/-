/**
*	@file	RoomID.h
*	@author	���{
*	@brief  ��������ʂ��邽�߂�ID
*/

#ifndef ROOMID_H_
#define ROOMID_H_

/**
*	@enum       RoomID
*	@brief      �����̒萔
*/
enum RoomID {

	ROOM_WORK,			//! �H�[
	ROOM_STORAGE,		//! ���u
	ROOM_CHILDREN,		//! �q������

	ROOM_RECEPTION,		//! ���ڊ�
	HALL_BACK,			//! ��L��
	HALL_FRONT,			//! �O�L��
	LEFT_CORRIDOR,		//! ���L��
	RIGHT_CORRIDOR,		//! �E�L��
	LEFT_SHOJI,			//! ����q
	RIGHT_SHOJI,		//! �E��q

	ROOM_PRAYER,		//! �F����
	ROOM_RIGHT_PRAYER,	//! �E�F����
	ROOM_LEFT_PRAYER,	//! ���F����

	ROOM_VOID,			//! �����
};


#endif