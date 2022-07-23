/*********************************************************************************************************************
* @file            car_4keys.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_4KEY_H
#define __CAR_4KEY_H

#include "headfile.h"

//�궨��
#define KEYDOWN    0
#define KEYUP      1

#define K1         2
#define K2         3
#define K3         4
#define K4         5

#define K1_PORT    GPIOB
#define K1_PIN     GPIO_PIN_10
#define K1_MODE    IN_PULLUP

#define K2_PORT    GPIOB
#define K2_PIN     GPIO_PIN_11
#define K2_MODE    IN_PULLUP

#define K3_PORT    GPIOB
#define K3_PIN     GPIO_PIN_12
#define K3_MODE    IN_PULLUP

#define K4_PORT    GPIOB
#define K4_PIN     GPIO_PIN_13
#define K4_MODE    IN_PULLUP


//��������
/* ������ʼ�� */
void key_init(unsigned char key_num);
/* ����ֵ */
unsigned char key_check(void);


//ȫ�ֱ�������

#endif
