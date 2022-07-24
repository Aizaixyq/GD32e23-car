/*********************************************************************************************************************
* @file            hf_HC-SR04.h
* @author          Davis Klay HF
* @version         1.0
* @Target core     GD32E230C8T6
* @date            2021-9-29
********************************************************************************************************************/

#ifndef _HF_HC_SR04_H
#define _HF_HC_SR04_H

#include "headfile.h"

/* 资源定义 */
#define TRIG_PORT    GPIOB
#define TRIG_PIN     GPIO_PIN_0
#define TRIG_MODE    OUT_PP

#define ECHO_PORT    GPIOA
#define ECHO_PIN     GPIO_PIN_6
#define ECHO_MODE    IN_PULLDOWN

#define EXTI_PORT    EXTI_SOURCE_GPIOA
#define EXTI_PIN     EXTI_SOURCE_PIN6
#define EXTI_NUM     EXTI_6


/* 函数声明 */
/* 超声波初始化 */
void ultra_init(void);
/* 超声波发射一次并返回距离 */
unsigned int ultra_get_distance(void);

//全局变量声明

#endif
