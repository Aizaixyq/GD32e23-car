/*********************************************************************************************************************
* @file            car_value_process.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_VALUE_PROCESS_H
#define __CAR_VALUE_PROCESS_H

#include "headfile.h"

//�궨��


//��������
/* 32λ�޷�������ת��ΪASCII�� */
void int_to_ascii(unsigned int adc_value, unsigned char *ascii_value);
void int_to_ascii0(unsigned int adc_value, unsigned char *ascii_value);


//ȫ�ֱ�������

#endif
