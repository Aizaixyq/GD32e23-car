/*********************************************************************************************************************
* @file            car_reed.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_REED_H
#define __CAR_REED_H

#include "headfile.h"

#define REED_PORT    GPIOA
#define REED_PIN     GPIO_PIN_15
#define REED_MODE    IN_PULLUP


//函数声明
/* 智能车干簧管初始化 */
void reed_init(void);
/* 智能车磁标检测 */
void reed_check(void);


//全局变量声明

#endif
