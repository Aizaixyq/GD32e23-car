/*********************************************************************************************************************
* @file            car_motion.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_MOTION_H
#define __CAR_MOTION_H

#include "headfile.h"

//�궨��


//��������
/* ���ܳ�ǰ�� */
void car_forward(void);
/* ���ܳ����� */
void car_backward(void);
/* ���ܳ�ͣ�� */
void car_stop(void);
/* ���ܳ���ת */
void car_turnleft(void);
/* ���ܳ���ת */
void car_turnright(void);
void car_turnright1(void);
void car_turnleft1(void);
void car_back(void);
void car_stopturnright1(void);
void car_moving(unsigned int , unsigned int);
//ȫ�ֱ�������

#endif
