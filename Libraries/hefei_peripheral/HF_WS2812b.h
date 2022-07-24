/*********************************************************************************************************************
* @file            HF_WS2812b.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_WS2812B_H
#define _HF_WS2812B_H

#include "headfile.h"

//函数声明
/* RGB初始化 */
void ws2812b_init(void);
/* RGB写入 */
void ws2812b_write(uint8_t* RGB);

//全局变量声明

#endif
