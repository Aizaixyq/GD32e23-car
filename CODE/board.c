/*********************************************************************************************************************
* @file            board.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
*                  -2021.10.24, V1.1
* @modify          1. �޸��˰���LEDϨ�����Ͱ���LED��ƽ��ת������ע��
*                  2. ɾ���˰���LED����������ʹ��һ��LEDϨ��ĺ���
********************************************************************************************************************/

#include "board.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����LED��ʼ��   
// @param        led_num            ѡ��LED��LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_init(LED1);//����LED1��ʼ��
//-------------------------------------------------------------------------------------------------------------------
void board_led_init(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_init(LED1_PORT, LED1_MODE, LED1_PIN);//����LED1������
        gpio_bit_output(LED1_PORT, LED1_PIN, OFF);//LED1Ϩ��
    }
    if(led_num == LED2)
    {
        gpio_init(LED2_PORT, LED2_MODE, LED2_PIN);//����LED2������
        gpio_bit_output(LED2_PORT, LED2_PIN, OFF);//LED2Ϩ��
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����LED����   
// @param        led_num            ѡ��LED��LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_on(LED1);//��������LED1
//-------------------------------------------------------------------------------------------------------------------
void board_led_on(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_bit_output(LED1_PORT, LED1_PIN, ON);
    }
    if(led_num == LED2)
    {
        gpio_bit_output(LED2_PORT, LED2_PIN, ON);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����LEDϨ��
// @param        led_num            ѡ��LED��LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_off(LED1);//����LED1Ϩ��
//-------------------------------------------------------------------------------------------------------------------
void board_led_off(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_bit_output(LED1_PORT, LED1_PIN, OFF);
    }
    if(led_num == LED2)
    {
        gpio_bit_output(LED2_PORT, LED2_PIN, OFF);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ����LED��ƽ��ת
// @param        led_num            ѡ��LED��LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_toggle(LED1);//����LED1��ƽ��ת
//-------------------------------------------------------------------------------------------------------------------
void board_led_toggle(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_toggle(LED1_PORT, LED1_PIN);
    }
    if(led_num == LED2)
    {
        gpio_toggle(LED2_PORT, LED2_PIN);
    }
}
