/*********************************************************************************************************************
* @file            car_light.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_LIGHT_H
#define __CAR_LIGHT_H

#include "headfile.h"

//�궨��
/* rgb��ɫ���� */
static unsigned char rgb_off[3] = {0x00, 0x00, 0x00};
static unsigned char rgb_blue[3] = {0x00, 0x00, 0xFF};
static unsigned char rgb_green[3] = {0x00, 0xFF, 0x00};
static unsigned char rgb_cyan[3] = {0x00, 0xFF, 0xFF};
static unsigned char rgb_red[3] = {0xFF, 0x00, 0x00};
static unsigned char rgb_purple[3] = {0xFF, 0x00, 0xFF};
static unsigned char rgb_yellow[3] = {0xFF, 0xFF, 0x00};
static unsigned char rgb_white[3] = {0xFF, 0xFF, 0xFF};
static unsigned char rgb_user_define[3] = {0xA7, 0xC8, 0xE2};


/* ���Ͷ��� */
typedef enum
{
    red,
    yellow,
    white,
    green,
    blue,
    cyan,
    purple,
}rgb_color;


//��������(�ⲿ�������û������е��ã�
/* ���ܳ�β��ͬʱ���� */
void car_both_rgb_on(rgb_color color, unsigned int time);
/* ���ܳ�β��Ϩ�� */
void car_both_rgb_off(void);
/* ���ܳ�β�������˸ */
void car_left_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time);
/* ���ܳ�β���ҵ���˸ */
void car_right_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time);
/* ���ܳ�β��ͬʱ��˸ */
void car_both_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time);


//ȫ�ֱ�������

#endif
