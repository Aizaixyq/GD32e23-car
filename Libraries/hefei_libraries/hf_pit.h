/*********************************************************************************************************************
* @file            hf_pit.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_PIT_H
#define _HF_PIT_H

#include "headfile.h"

/* 函数定义 */

/* 定时器中断初始化(ms) */
void timer_pit_interrupt_us(uint32_t timer_periph, uint16_t timer_period);
/* 定时器中断初始化(us) */
void timer_pit_interrupt_ms(uint32_t timer_periph, uint16_t timer_period);
/* 关闭定时器中断 */
void timer_pit_close(uint32_t timer_periph);

#endif
