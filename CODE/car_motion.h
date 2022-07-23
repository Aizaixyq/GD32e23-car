/*********************************************************************************************************************
* @file            car_motion.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_MOTION_H
#define __CAR_MOTION_H

#include "headfile.h"

//宏定义


//函数声明
/* 智能车前进 */
void car_forward(void);
/* 智能车后退 */
void car_backward(void);
/* 智能车停车 */
void car_stop(void);
/* 智能车左转 */
void car_turnleft(void);
/* 智能车右转 */
void car_turnright(void);
void car_turnright1(void);
void car_turnleft1(void);
void car_back(void);
void car_stopturnright1(void);
void car_moving(unsigned int , unsigned int);
//全局变量声明

#endif
