/*********************************************************************************************************************
* @file            hf_gpio.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_gpio.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO初始化
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        mode:                  选择的模式: GPIOMODE_enum(详见hf_gpio.h)
// @param        gpio_pin               选择的引脚：GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       void
// Sample usage:        gpio_init(GPIOA, 1, GPIO_PIN_0);
//                      //PA0初始化为浮空输入模式
//-------------------------------------------------------------------------------------------------------------------
void gpio_init(uint32_t gpio_periph, GPIOMODE_enum mode, uint32_t gpio_pin)
{
    /* 配置GPIO时钟 */
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

    /* 配置GPIO引脚模式 */
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
// @brief        GPIO引脚输出设置
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        gpio_pin               选择的引脚：GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @param        dat                    0：低电平 1：高电平
// @return       void
// Sample usage:        gpio_bit_output(GPIOA, GPIO_PIN_0, 1);
                        //PA0输出高电平
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
// @brief        GPIO引脚输出翻转
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        gpio_pin               选择的引脚：GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       void
// Sample usage:        gpio_toggle(GPIOA, GPIO_PIN_0);
                        //PA0输出切换（0变为1，1变为0）
//-------------------------------------------------------------------------------------------------------------------
void gpio_toggle(uint32_t gpio_periph, uint32_t gpio_pin)
{
    GPIO_TG(gpio_periph) = (uint32_t)gpio_pin;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        GPIO获取引脚输入
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,D,E,F,G)
// @param        gpio_pin               选择的引脚：GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       uint8                  0：低电平 1：高电平
// Sample usage:        uint8 status;  status = gpio_get_input(GPIOA, GPIO_PIN_0);
                        //获取PA0引脚输入电平
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
// @brief        GPIO获取引脚输出
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        gpio_pin               选择的引脚：GPIO_PIN_x(x=0..15), GPIO_PIN_ALL
// @return       uint8                  0：低电平 1：高电平
// Sample usage:        uint8 status = gpio_get_output(GPIOA, GPIO_PIN_0);
                        //获取PA0引脚输出电平
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
