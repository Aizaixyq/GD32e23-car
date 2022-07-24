/*********************************************************************************************************************
* @file            HF_DS18B20.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef  _HF_TM1637_H
#define  _HF_TM1637_H

#include "headfile.h"

/* LED��ʾ���飬������ */
static const unsigned char leddata[]={
                0x3F,  //"0"
                0x06,  //"1"
                0x5B,  //"2"
                0x4F,  //"3"
                0x66,  //"4"
                0x6D,  //"5"
                0x7D,  //"6"
                0x07,  //"7"
                0x7F,  //"8"
                0x6F,  //"9"
                0x77,  //"A"
                0x7C,  //"B"
                0x39,  //"C"
                0x5E,  //"D"
                0x79,  //"E"
                0x71,  //"F"
                0x00,  //Ϩ��
                0x00  //�Զ���
                         };

//�궨��
#define led_scl_clr() gpio_bit_output(GPIOB, GPIO_PIN_6, 0)
#define led_scl_set() gpio_bit_output(GPIOB, GPIO_PIN_6, 1)

#define led_sda_clr() gpio_bit_output(GPIOB, GPIO_PIN_7, 0)
#define led_sda_set() gpio_bit_output(GPIOB, GPIO_PIN_7, 1)

#define led_sda_get() gpio_get_output(GPIOB, GPIO_PIN_7)


#define BIT_1    1
#define BIT_2    2
#define BIT_3    3
#define BIT_4    4


//��������
/* �ⲿ�������û������е��� */
/* ����ܳ�ʼ�� */
void tm1637_init(void);
/* ��ʼ�ź� */
void tm1637_start(void);
/* ֹͣ�ź� */
void tm1637_stop(void);
/* дһ���ֽ� */
void tm1637_write_byte(unsigned char dat);
/* �ȴ�Ӧ�� */
void tm1637_wait_ack(void);
/* ����һ������ */
void tm1637_command(unsigned char cmd);
/* �������ʾ */
void tm1637_leddisplay(unsigned char num_position, unsigned char num, unsigned char dp);


//ȫ�ֱ�������

#endif
