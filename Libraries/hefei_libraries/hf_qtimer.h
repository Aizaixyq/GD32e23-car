/*********************************************************************************************************************
* @file            hf_qtimer.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_QTIMER_H
#define _HF_QTIMER_H

#include "headfile.h"

/* 类型定义 */
typedef enum 
{
    Encoder1 = 0,
    Encoder2 = 1,
    Encoder_ALL = 99
} encoder_typedef_enum;

/* 函数定义 */

/* 编码器初始化 */
void timer_quad_init(encoder_typedef_enum Encodernum);
/* 读取编码器数值 */
int16_t timer_quad_get(encoder_typedef_enum Encodernum);

#endif
