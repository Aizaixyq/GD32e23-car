/*********************************************************************************************************************
* @file            hf_adc.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_ADC_H
#define _HF_ADC_H

#include "headfile.h"

/* �������� */

/* ADC��ʼ�� */
void adc_init(uint32_t adc_ch);
/* ADCת��һ�� */
uint16_t adc_convert(uint32_t adc_ch);
/* ADCת����� */
uint16_t adc_mean_filter(uint32_t adc_ch, uint8_t count);

#endif
