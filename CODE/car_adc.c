/*********************************************************************************************************************
* @file            car_adc.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "headfile.h"
unsigned int adc_value[3]; 
//-------------------------------------------------------------------------------------------------------------------
// @brief        adc初始化   
// @param        adc_ch            选择ADC通道：ADC_CHANNEL_x(x = 0..9)
// @return       void
// Sample usage:       adc_channel_init(ADC_CHANNEL_8);//初始化ADC通道8
//-------------------------------------------------------------------------------------------------------------------
void adc_channel_init(uint32_t adc_ch)
{
    adc_init(adc_ch);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        adc转换一次
// @param        adc_ch            选择ADC通道：ADC_CHANNEL_x(x = 0..9)
// @return       void 
// Sample usage:        adc_get(ADC_CH_08);//ADC通道8转换一次
//-------------------------------------------------------------------------------------------------------------------
void adc_get()
{
    unsigned int  ADC_Value_Sum2 = 0, ADC_Value_Sum3 = 0, ADC_Value_Sum1 = 0, Weight_Ration[10] = {4,6,7,8,10,15,20,30,200,700}, Weight_Ration_Sum = 1000;  
    for(unsigned int i = 0; i < 10; i++){ ;
			ADC_Value_Sum1 += (int)adc_convert(ADC_CH_05) * Weight_Ration[i];
			ADC_Value_Sum2 += 0;
			ADC_Value_Sum3 += (int)adc_convert(ADC_CH_01) * Weight_Ration[i];
		}
		
		adc_value[0] = ((ADC_Value_Sum1 / Weight_Ration_Sum*1.0)*1.0/4095)*100; 
		adc_value[1] = 0; 
		adc_value[2] = ((ADC_Value_Sum3 / Weight_Ration_Sum*1.0)*1.0/4095)*100;
}
