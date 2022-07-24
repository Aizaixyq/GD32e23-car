/*********************************************************************************************************************
* @file            hf_gpio.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_GPIO_H
#define _HF_GPIO_H

#include "headfile.h"

/* ö������ */

typedef enum    //ö��GPIO����
{
    IN_AIN = 0,            //ģ������ģʽ
    IN_FLOATING = 1,       //��������ģʽ
    IN_PULLDOWN = 2,       //��������
    IN_PULLUP = 3,         //��������

    OUT_PP = 4,            //ͨ���������ģʽ
    OUT_OD = 5,            //ͨ�ÿ�©���ģʽ

    OUT_AF_0_PP = 6,       //���ù����������ģʽ�����ù���0
    OUT_AF_0_OD = 7,       //���ù��ܿ�©���ģʽ�����ù���0
    OUT_AF_1_PP = 8,       //���ù����������ģʽ�����ù���1
    OUT_AF_1_OD = 9,       //���ù��ܿ�©���ģʽ�����ù���1
    OUT_AF_2_PP = 10,      //���ù����������ģʽ�����ù���2
    OUT_AF_2_OD = 11,      //���ù��ܿ�©���ģʽ�����ù���2
    OUT_AF_3_PP = 12,      //���ù����������ģʽ�����ù���3
    OUT_AF_3_OD = 13,      //���ù��ܿ�©���ģʽ�����ù���3
    OUT_AF_4_PP = 14,      //���ù����������ģʽ�����ù���4
    OUT_AF_4_OD = 15,      //���ù��ܿ�©���ģʽ�����ù���4
    OUT_AF_5_PP = 16,      //���ù����������ģʽ�����ù���5
    OUT_AF_5_OD = 17,      //���ù��ܿ�©���ģʽ�����ù���5
    OUT_AF_6_PP = 18,      //���ù����������ģʽ�����ù���6
    OUT_AF_6_OD = 19,      //���ù��ܿ�©���ģʽ�����ù���6
    OUT_AF_7_PP = 20,      //���ù����������ģʽ�����ù���7
    OUT_AF_7_OD = 21       //���ù��ܿ�©���ģʽ�����ù���7

}GPIOMODE_enum;


/* �������� */

/* GPIO��ʼ�� */
void gpio_init(uint32_t gpio_periph, GPIOMODE_enum mode, uint32_t gpio_pin);
/* GPIO����������� */
void gpio_bit_output(uint32_t gpio_periph, uint32_t gpio_pin, uint8_t dat);
/* GPIO���������ת */
void gpio_toggle(uint32_t gpio_periph, uint32_t gpio_pin);
/* GPIO��ȡ�������� */
uint8_t gpio_get_input(uint32_t gpio_periph,uint32_t gpio_pin);
/* GPIO��ȡ������� */
uint8_t gpio_get_output(uint32_t gpio_periph,uint32_t gpio_pin);

#endif
