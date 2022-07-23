/*********************************************************************************************************************
* @file            car_adc.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef __CAR_ADC_H
#define __CAR_ADC_H

#include "headfile.h"

//�궨��
#define ADC_CH_00     ADC_CHANNEL_0
#define ADC_CH_01     ADC_CHANNEL_1
#define ADC_CH_02     ADC_CHANNEL_2
#define ADC_CH_03     ADC_CHANNEL_3
#define ADC_CH_04     ADC_CHANNEL_4
#define ADC_CH_05     ADC_CHANNEL_5
#define ADC_CH_06     ADC_CHANNEL_6
#define ADC_CH_07     ADC_CHANNEL_7
#define ADC_CH_08     ADC_CHANNEL_8
#define ADC_CH_09     ADC_CHANNEL_9


//��������
/* adc��ʼ�� */
void adc_channel_init(uint32_t adc_ch);
/* adcת��һ�� */
void  adc_get();


//ȫ�ֱ�������

#endif
