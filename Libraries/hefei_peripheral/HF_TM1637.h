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

/* LED显示数组，共阴极 */
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
                0x00,  //熄灭
                0x00  //自定义
                         };

//宏定义
#define led_scl_clr() gpio_bit_output(GPIOB, GPIO_PIN_6, 0)
#define led_scl_set() gpio_bit_output(GPIOB, GPIO_PIN_6, 1)

#define led_sda_clr() gpio_bit_output(GPIOB, GPIO_PIN_7, 0)
#define led_sda_set() gpio_bit_output(GPIOB, GPIO_PIN_7, 1)

#define led_sda_get() gpio_get_output(GPIOB, GPIO_PIN_7)


#define BIT_1    1
#define BIT_2    2
#define BIT_3    3
#define BIT_4    4


//函数声明
/* 外部函数，用户可自行调用 */
/* 数码管初始化 */
void tm1637_init(void);
/* 起始信号 */
void tm1637_start(void);
/* 停止信号 */
void tm1637_stop(void);
/* 写一个字节 */
void tm1637_write_byte(unsigned char dat);
/* 等待应答 */
void tm1637_wait_ack(void);
/* 发送一个命令 */
void tm1637_command(unsigned char cmd);
/* 数码管显示 */
void tm1637_leddisplay(unsigned char num_position, unsigned char num, unsigned char dp);


//全局变量声明

#endif
