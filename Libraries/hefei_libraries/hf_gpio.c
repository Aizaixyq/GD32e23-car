/*********************************************************************************************************************
* @file            hf_gpio.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_gpio.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO��ʼ��
// @param        gpio_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        mode:                  ѡ���ģʽ: GPIOMODE_enum(���hf_gpio.h)
// @param        gpio_pin               ѡ������ţ�GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       void
// Sample usage:        gpio_init(GPIOA, 1, GPIO_PIN_0);
//                      //PA0��ʼ��Ϊ��������ģʽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(uint32_t gpio_periph, GPIOMODE_enum mode, uint32_t gpio_pin)
{
    /* ����GPIOʱ�� */
    if(gpio_periph == GPIOA)
    {
        rcu_periph_clock_enable(RCU_GPIOA);
    }
    else if(gpio_periph == GPIOB)
    {
        rcu_periph_clock_enable(RCU_GPIOB);
    }
    else if(gpio_periph == GPIOC)
    {
        rcu_periph_clock_enable(RCU_GPIOC);
    }
    else if(gpio_periph == GPIOF)
    {
        rcu_periph_clock_enable(RCU_GPIOF);
    }

    /* ����GPIO����ģʽ */
    if(mode == IN_AIN)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_ANALOG, GPIO_PUPD_NONE, gpio_pin);
    }

    else if(mode == IN_FLOATING)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_INPUT, GPIO_PUPD_NONE, gpio_pin);
    }

    else if(mode == IN_PULLDOWN)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_INPUT, GPIO_PUPD_PULLDOWN, gpio_pin);
    }

    else if(mode == IN_PULLUP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_INPUT, GPIO_PUPD_PULLUP, gpio_pin);
    }

    else if(mode == OUT_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
    }

    else if(mode == OUT_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_INPUT, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
    }

    else if(mode == OUT_AF_0_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_0, gpio_pin);
    }

    else if(mode == OUT_AF_0_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_0, gpio_pin);
    }

    else if(mode == OUT_AF_1_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_1, gpio_pin);
    }

    else if(mode == OUT_AF_1_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_1, gpio_pin);
    }

    else if(mode == OUT_AF_2_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_2, gpio_pin);
    }

    else if(mode == OUT_AF_2_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_2, gpio_pin);
    }

    else if(mode == OUT_AF_3_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_3, gpio_pin);
    }

    else if(mode == OUT_AF_3_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_3, gpio_pin);
    }

    else if(mode == OUT_AF_4_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_4, gpio_pin);
    }

    else if(mode == OUT_AF_4_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_4, gpio_pin);
    }

    else if(mode == OUT_AF_5_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_5, gpio_pin);
    }

    else if(mode == OUT_AF_5_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_5, gpio_pin);
    }

    else if(mode == OUT_AF_6_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_6, gpio_pin);
    }

    else if(mode == OUT_AF_6_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_6, gpio_pin);
    }

    else if(mode == OUT_AF_7_PP)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_PP, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_7, gpio_pin);
    }

    else if(mode == OUT_AF_7_OD)
    {
        gpio_mode_set(gpio_periph, GPIO_MODE_AF, GPIO_PUPD_NONE, gpio_pin);
        gpio_output_options_set(gpio_periph, GPIO_OTYPE_OD, GPIO_OSPEED_50MHZ, gpio_pin);
        gpio_af_set(gpio_periph, GPIO_AF_7, gpio_pin);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO�����������
// @param        gpio_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        gpio_pin               ѡ������ţ�GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @param        dat                    0���͵�ƽ 1���ߵ�ƽ
// @return       void
// Sample usage:        gpio_bit_output(GPIOA, GPIO_PIN_0, 1);
                        //PA0����ߵ�ƽ
//-------------------------------------------------------------------------------------------------------------------
void gpio_bit_output(uint32_t gpio_periph, uint32_t gpio_pin, uint8_t dat)
{
    if(RESET != dat)
    {
        gpio_bit_set(gpio_periph, gpio_pin);
    }
    else
    {
        gpio_bit_reset(gpio_periph, gpio_pin);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO���������ת
// @param        gpio_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        gpio_pin               ѡ������ţ�GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       void
// Sample usage:        gpio_toggle(GPIOA, GPIO_PIN_0);
                        //PA0����л���0��Ϊ1��1��Ϊ0��
//-------------------------------------------------------------------------------------------------------------------
void gpio_toggle(uint32_t gpio_periph, uint32_t gpio_pin)
{
    GPIO_TG(gpio_periph) = (uint32_t)gpio_pin;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO��ȡ��������
// @param        gpio_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,D,E,F,G)
// @param        gpio_pin               ѡ������ţ�GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       uint8                  0���͵�ƽ 1���ߵ�ƽ
// Sample usage:        uint8 status;  status = gpio_get_input(GPIOA, GPIO_PIN_0);
                        //��ȡPA0���������ƽ
//-------------------------------------------------------------------------------------------------------------------
uint8_t gpio_get_input(uint32_t gpio_periph,uint32_t gpio_pin)
{
    if(0!= gpio_input_bit_get(gpio_periph, gpio_pin))    
    {       
        return 1;
    }
    else
    {
        return 0;
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO��ȡ�������
// @param        gpio_periph            ѡ��Ķ˿ڣ�GPIOx(x = A,B,C,F)
// @param        gpio_pin               ѡ������ţ�GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       uint8                  0���͵�ƽ 1���ߵ�ƽ
// Sample usage:        uint8 status = gpio_get_output(GPIOA, GPIO_PIN_0);
                        //��ȡPA0���������ƽ
//-------------------------------------------------------------------------------------------------------------------
uint8_t gpio_get_output(uint32_t gpio_periph,uint32_t gpio_pin)
{
    if(0 !=gpio_output_bit_get(gpio_periph, gpio_pin))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
