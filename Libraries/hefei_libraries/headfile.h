/*********************************************************************************************************************
* @file            headfile.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/
 
#ifndef _HEADFILE_H
#define _HEADFILE_H

#include "gd32e23x.h"                   // Device header
#include <stdint.h>
#include <stdio.h>
#include <math.h>

//------MCU外设驱动头文件
#include "hf_adc.h"
#include "hf_exti.h"
#include "hf_flash.h"
#include "hf_gpio.h"
#include "hf_pit.h"
#include "hf_pwm.h"
#include "hf_qtimer.h"
#include "hf_uart.h"
#include "hf_i2c_hardware.h"
#include "hf_i2c_software.h"
#include "hf_systick.h"
#include "hf_spi.h"

//------外设驱动头文件
#include "HF_L9110S_2.h"
#include "HF_WS2812b.h"
#include "HF_HC-SR04.h"
#include "HF_TM1637.h"

//------智能车驱动头文件
#include "board.h"
#include "car_init.h"
#include "car_motion.h"
#include "car_light.h"
#include "car_uart.h"
#include "car_buzzer.h"
#include "car_4keys.h"
#include "car_adc.h"
#include "car_reed.h"
#include "car_value_process.h"



#endif
