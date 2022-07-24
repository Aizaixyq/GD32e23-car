/*********************************************************************************************************************
* @file            hf_exti.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_EXTI_H
#define _HF_EXTI_H

#include "headfile.h"

/* 变量声明 */

typedef enum 
{
    CHANGE = 0,
    RISING = 1,
    FALLING = 2
} exti_Mode_enum;


/* 函数声明 */

/* 开启引脚外部中断 */
void exti_enable(uint32_t gpio_periph, uint32_t exti_pin, exti_Mode_enum Mode);
/* 关闭引脚外部中断 */
void exti_disable(uint32_t exti_pin);

#endif
