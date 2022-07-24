/*********************************************************************************************************************
* @file            hf_pwm.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_PWM_H
#define _HF_PWM_H

#include "headfile.h"

/* �������� */

/* PWM ��ʼ�� */
void pwm_init(uint32_t timer_periph, uint16_t timer_ch, uint16_t freq_div, uint16_t period_temp, uint16_t duty);
/* PWM Ƶ������ */
void pwm_freq(uint32_t timer_periph, uint16_t freq_div, uint16_t period_temp);
/* PWM ռ�ձ����� */
void pwm_duty(uint32_t timer_periph, uint32_t timer_ch, uint16_t duty);
/* PWM ֹͣ */
void pwm_stop(uint32_t timer_periph);

#endif
