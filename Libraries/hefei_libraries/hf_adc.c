/*********************************************************************************************************************
* @file            hf_adc.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_adc.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADC��ʼ��
// @param        adc_ch            ѡ��ADCͨ����ADC_CHANNEL_x(x = 0..9)
// @return       void
// Sample usage:        adc_init(ADC_CHANNEL_1); 
                        //��ʼ��ͨ��1ΪADC����ͨ��
//-------------------------------------------------------------------------------------------------------------------
void adc_init(uint32_t adc_ch)
{
    /* ���õδ��ʱ��������1ms��ʱ */
    systick_config();

    /* ʹ��GPIOʱ�� */
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
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0);
    }
    else if(adc_ch == ADC_CHANNEL_1)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
    }
    else if(adc_ch == ADC_CHANNEL_2)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_2);
    }
    else if(adc_ch == ADC_CHANNEL_3)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_3);
    }
    else if(adc_ch == ADC_CHANNEL_4)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_4);
    }
    else if(adc_ch == ADC_CHANNEL_5)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_5);
    }
    else if(adc_ch == ADC_CHANNEL_6)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_6);
    }
    else if(adc_ch == ADC_CHANNEL_7)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOA, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_7);
    }
    else if(adc_ch == ADC_CHANNEL_8)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOB, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_0);
    }
    else if(adc_ch == ADC_CHANNEL_9)
    {
        /* ����GPIOģʽ */
        gpio_mode_set(GPIOB, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, GPIO_PIN_1);
    }

    /* ʹ��ADCʱ�� */
    rcu_periph_clock_enable(RCU_ADC);
    /* ����ADCʱ����Դ */
    rcu_adc_clock_config(RCU_ADCCK_APB2_DIV6);
    /* ��λ ADC */
    adc_deinit();

    /* ADC �������ܽ��� */
    adc_special_function_config(ADC_CONTINUOUS_MODE, DISABLE);
    /* ADC ɨ��ģʽ���� */
    adc_special_function_config(ADC_SCAN_MODE, DISABLE);

    /* ADC�����Ҷ��� */
    adc_data_alignment_config(ADC_DATAALIGN_RIGHT);

    /* ADCת������������������ⲿ���� */
    adc_external_trigger_source_config(ADC_REGULAR_CHANNEL, ADC_EXTTRIG_REGULAR_NONE);
    adc_external_trigger_config(ADC_REGULAR_CHANNEL, ENABLE);

    /* ADCʹ�� */
    adc_enable();
    /* ��ʱ1ms�ȴ�ʹ����� */
//    delay_1ms(1);
    /* ADCУ׼�͸�λУ׼ */
    adc_calibration_enable();
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADCת��һ��
// @param        adc_ch            ѡ��ADCͨ����ADC_CHANNEL_x(x = 0..9)
// @return       uint16            ת����ģ������ֵ
// Sample usage:        uint16_t data; data = adc_convert(ADC_CHANNEL_1); 
                        //��ȡADCͨ��1ת��ֵ
//-------------------------------------------------------------------------------------------------------------------
uint16_t adc_convert(uint32_t adc_ch)
{
    /* ����ADCͨ����ת��ʱ�� */
    adc_regular_channel_config(0, adc_ch, ADC_SAMPLETIME_1POINT5);
    /* ʹ��ADC������� */
    adc_software_trigger_enable(ADC_REGULAR_CHANNEL);
    /* ���ת����ɱ�־λ */
    adc_flag_clear(ADC_FLAG_EOC);
    /* �ȴ�ADCת����� */
    while (!adc_flag_get(ADC_FLAG_EOC));
    /* ����ADC��ֵ */
    return(adc_regular_data_read());
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ADCת�����
// @param        adc_ch            ѡ��ADCͨ����ADC_CHANNEL_x(x = 0..9)
// @param        count             ��ֵ�˲�����
// @return       uint16            ת����ģ������ֵ
// Sample usage:        uint16_t data; data = adc_mean_filter(ADC_CHANNEL_1, 5); 
                        //��ADCͨ��1����5����ƽ��ֵ
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
