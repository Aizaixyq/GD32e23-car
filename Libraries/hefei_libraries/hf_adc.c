/*********************************************************************************************************************
* @file            hf_adc.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_adc.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADC初始化
// @param        adc_ch            选择ADC通道：ADC_CHANNEL_x(x = 0..9)
// @return       void
// Sample usage:        adc_init(ADC_CHANNEL_1); 
                        //初始化通道1为ADC输入通道
//-------------------------------------------------------------------------------------------------------------------
void adc_init(uint32_t adc_ch)
{
    /* 配置滴答计时器，用于1ms延时 */
    systick_config();

    /* 使能GPIO时钟 */
    if(adc_ch == ADC_CHANNEL_8 || adc_ch == ADC_CHANNEL_9)
    {
        rcu_periph_clock_enable(RCU_GPIOB);
    }
    else 
    {
        rcu_periph_clock_enable(RCU_GPIOA);
    }
    if(adc_ch == ADC_CHANNEL_0)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0);
    }
    else if(adc_ch == ADC_CHANNEL_1)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
    }
    else if(adc_ch == ADC_CHANNEL_2)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_2);
    }
    else if(adc_ch == ADC_CHANNEL_3)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_3);
    }
    else if(adc_ch == ADC_CHANNEL_4)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_4);
    }
    else if(adc_ch == ADC_CHANNEL_5)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_5);
    }
    else if(adc_ch == ADC_CHANNEL_6)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_6);
    }
    else if(adc_ch == ADC_CHANNEL_7)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_7);
    }
    else if(adc_ch == ADC_CHANNEL_8)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOB, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0);
    }
    else if(adc_ch == ADC_CHANNEL_9)
    {
        /* 配置GPIO模式 */
        gpio_mode_set(GPIOB, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
    }

    /* 使能ADC时钟 */
    rcu_periph_clock_enable(RCU_ADC);
    /* 配置ADC时钟来源 */
    rcu_adc_clock_config(RCU_ADCCK_APB2_DIV6);
    /* 复位 ADC */
    adc_deinit();

    /* ADC 连续功能禁用 */
    adc_special_function_config(ADC_CONTINUOUS_MODE, DISABLE);
    /* ADC 扫描模式禁用 */
    adc_special_function_config(ADC_SCAN_MODE, DISABLE);

    /* ADC数据右对齐 */
    adc_data_alignment_config(ADC_DATAALIGN_RIGHT);

    /* ADC转换由软件触发而不是外部触发 */
    adc_external_trigger_source_config(ADC_REGULAR_CHANNEL, ADC_EXTTRIG_REGULAR_NONE);
    adc_external_trigger_config(ADC_REGULAR_CHANNEL, ENABLE);

    /* ADC使能 */
    adc_enable();
    /* 延时1ms等待使能完成 */
//    delay_1ms(1);
    /* ADC校准和复位校准 */
    adc_calibration_enable();
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADC转换一次
// @param        adc_ch            选择ADC通道：ADC_CHANNEL_x(x = 0..9)
// @return       uint16            转换的模拟量数值
// Sample usage:        uint16_t data; data = adc_convert(ADC_CHANNEL_1); 
                        //获取ADC通道1转换值
//-------------------------------------------------------------------------------------------------------------------
uint16_t adc_convert(uint32_t adc_ch)
{
    /* 配置ADC通道和转换时间 */
    adc_regular_channel_config(0, adc_ch, ADC_SAMPLETIME_1POINT5);
    /* 使能ADC软件触发 */
    adc_software_trigger_enable(ADC_REGULAR_CHANNEL);
    /* 清除转换完成标志位 */
    adc_flag_clear(ADC_FLAG_EOC);
    /* 等待ADC转换完成 */
    while (!adc_flag_get(ADC_FLAG_EOC));
    /* 返回ADC的值 */
    return(adc_regular_data_read());
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADC转换多次
// @param        adc_ch            选择ADC通道：ADC_CHANNEL_x(x = 0..9)
// @param        count             均值滤波次数
// @return       uint16            转换的模拟量数值
// Sample usage:        uint16_t data; data = adc_mean_filter(ADC_CHANNEL_1, 5); 
                        //对ADC通道1采样5次求平均值
//-------------------------------------------------------------------------------------------------------------------
uint16_t adc_mean_filter(uint32_t adc_ch, uint8_t count)
{
    uint8_t i;
    uint16_t sum, max, min;

    sum = 0;
    if(count < 1)
    {
        return 0;
    }
		sum = adc_convert(adc_ch);
		max = sum;
		min = sum;
    for (i = 1; i < 5; i++)
    {
        uint16_t a = adc_convert(adc_ch);
				sum += a;
				if(a > max){
					max = a;
				}
				else if(a < min){
					min = a;
				}
    }
		sum -= (min + max);
    return sum / 3;
}
