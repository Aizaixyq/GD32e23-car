/*********************************************************************************************************************
* @file            car_value_process.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_VALUE_PROCESS_H
#define __CAR_VALUE_PROCESS_H

#include "headfile.h"

//宏定义


//函数声明
/* 32位无符号整型转换为ASCII码 */
void int_to_ascii(unsigned int adc_value, unsigned char *ascii_value);
void int_to_ascii0(unsigned int adc_value, unsigned char *ascii_value);


//全局变量声明

#endif
