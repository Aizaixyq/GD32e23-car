/*********************************************************************************************************************
* @file            HF_L9110S_2.h
* @author          Davis Klay HF
* @version         1.0
* @Target core     GD32E230C8T6
* @date            2021-9-26
********************************************************************************************************************/

#ifndef _HF_L9110S_2_H
#define _HF_L9110S_2_H

#include "headfile.h"

//宏定义
#define L_PWM1_PORT        GPIOB
#define L_PWM1_PIN         GPIO_PIN_14
#define L_PWM1_MODE        OUT_AF_1_PP
#define L_PWM1_TIMER       TIMER14
#define L_PWM1_TIMER_CH    TIMER_CH_0

#define L_PWM2_PORT        GPIOB
#define L_PWM2_PIN         GPIO_PIN_1
#define L_PWM2_MODE        OUT_AF_0_PP
#define L_PWM2_TIMER       TIMER13
#define L_PWM2_TIMER_CH    TIMER_CH_0

#define R_PWM1_PORT        GPIOB
#define R_PWM1_PIN         GPIO_PIN_8
#define R_PWM1_MODE        OUT_AF_2_PP
#define R_PWM1_TIMER       TIMER15
#define R_PWM1_TIMER_CH    TIMER_CH_0

#define R_PWM2_PORT        GPIOB
#define R_PWM2_PIN         GPIO_PIN_9
#define R_PWM2_MODE        OUT_AF_2_PP
#define R_PWM2_TIMER       TIMER16
#define R_PWM2_TIMER_CH    TIMER_CH_0


/* 类型定义 */
typedef enum
{
	left,
	right
}left_or_right;


/* 函数声明 */
/* PWM初始化 */
void l9110s_init(left_or_right object);
/* 控制电机正转 */
void l9110s_forward(left_or_right object, uint16_t value);
/* 控制电机反转 */
void l9110s_backward(left_or_right object, uint16_t value);


//全局变量声明

#endif
