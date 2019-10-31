#ifndef CALCULATION_H_
#define CALCULATION_H_

#include "../Texture/Texture.h"

struct Position {
	float m_X;
	float m_Y;
};

Position GetPosition(float X, float Y);

#define PI 3.141592

//�摜�̔䗦���Z�o����
//a => �`�悷��摜�T�C�Y
//b => �S�̂̉摜�T�C�Y
float GetImageRatio(float a, float b);
//�����摜�̔䗦���Z�o����
//a => �`�悷��摜�T�C�Y
//b => �����摜�̖���
float GetIntegratedImageRatio(float a, float b);

//�_�Ƌ�`�̓����蔻��
//X1, Y1 => GetMousPos()�ȂǗ��p
//X2 - X3 => ��`�͈̔͂��w��(��)
//Y2 - Y3 => ��`�͈̔͂��w��(�c)
bool RectangleHit(float X1, float Y1, float X2, float Y2, float X3, float Y3);
//�摜�T�C�Y��texture_data����Ƃ�ꍇ�A���W�̎w�肾����OK
bool RectangleHit(Texture* texture_data, float X1, float X2, float Y1, float Y2);

//��_�Ԃ̃��W�A�����v�Z
double GetRadian(double startX, double startY, double endX, double endY);
//���W�A����x���@�ɕϊ�����
double GetDegree(double rad);

//��`�Ƌ�`�̓����蔻��
//X1, Y1 => 1�ڂ̍��W���w��
//wide1, hight1 => 1�ڂ̋�`�̃T�C�Y���w��
//X2, Y2 => �Q�ڂ̍��W���w��
//wide2, hight2 => �Q�ڂ̋�`�̃T�C�Y���w��
bool AdvRectangleHit(float X1, float X2, float Y1, float Y2, float wide1, float wide2, float height1, float height2);

#endif