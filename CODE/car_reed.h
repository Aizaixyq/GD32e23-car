/*********************************************************************************************************************
* @file            car_reed.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_REED_H
#define __CAR_REED_H

#include "headfile.h"

#define REED_PORT    GPIOA
#define REED_PIN     GPIO_PIN_15
#define REED_MODE    IN_PULLUP


//��������
/* ���ܳ��ɻɹܳ�ʼ�� */
void reed_init(void);
/* ���ܳ��ű��� */
void reed_check(void);


//ȫ�ֱ�������

#endif
