/*********************************************************************************************************************
* @file            board.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __BOARD_H_
#define __BOARD_H_

#include "headfile.h"

//�궨��
#define LED1    1
#define LED2    2

#define LED1_PORT    GPIOB
#define LED1_PIN     GPIO_PIN_2
#define LED1_MODE    OUT_PP

#define LED2_PORT    GPIOB
#define LED2_PIN     GPIO_PIN_11
#define LED2_MODE    OUT_PP

#define ON      0
#define OFF     1


//��������
/* ����LED��ʼ�� */
void board_led_init(unsigned char led_num);
/* ����LED���� */
void board_led_on(unsigned char led_num);
/* ����LEDϨ�� */
void board_led_off(unsigned char led_num);
/* ����LED��ƽ��ת */
void board_led_toggle(unsigned char led_num);

//ȫ�ֱ�������

#endif