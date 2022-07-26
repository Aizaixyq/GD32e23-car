/*********************************************************************************************************************
* @file            hf_exti.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_exti.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        开启引脚外部中断
// @param        gpio_periph            选择的端口：GPIOx(x = A,B,C,F)
// @param        exti_pin               选择的引脚：GPIO_PIN_x(x=0..15)
// @param        Mode                   选择的模式，只能选择以下参数：
// @arg          CHANGE:                电平改变触发
// @arg          RISING:                上升沿触发
// @arg          FALLING:               下降沿触发
// @return       void
// Sample usage:            exti_enable(GPIOA, GPIO_PIN_0, CHANGE);//开启PA0外部中断，模式为电平改变触发
                            //注：无法同时开启同一引脚数的外部中断（如PA0和PB0）
//-------------------------------------------------------------------------------------------------------------------
void exti_enable(uint32_t gpio_periph, uint32_t exti_pin, exti_Mode_enum Mode)
{
    uint32_t exti_source_gpio;
    uint32_t exti_source_pin;
    uint32_t exti_num;

    /* 配置比较设置时钟 */
    rcu_periph_clock_enable(RCU_CFGCMP);

    /* 配置中断优先级 */
    nvic_irq_enable(EXTI0_1_IRQn, 0U);
    nvic_irq_enable(EXTI2_3_IRQn, 0U);
    nvic_irq_enable(EXTI4_15_IRQn, 0U);

    /* 中断源端口及时钟配置 */
    if(gpio_periph == GPIOA)
    {
        exti_source_gpio = EXTI_SOURCE_GPIOA;
        rcu_periph_clock_enable(RCU_GPIOA);
    }
    else if(gpio_periph == GPIOB) 
    {
        exti_source_gpio = EXTI_SOURCE_GPIOB;
        rcu_periph_clock_enable(RCU_GPIOB);
    }
    else if(gpio_periph == GPIOC)
    {
        exti_source_gpio = EXTI_SOURCE_GPIOC;
        rcu_periph_clock_enable(RCU_GPIOC);
    }
    else if(gpio_periph == GPIOF)
    {
        exti_source_gpio = EXTI_SOURCE_GPIOF;
        rcu_periph_clock_enable(RCU_GPIOF);
    }

    /* 中断源引脚及线序配置 */
    if(exti_pin == GPIO_PIN_0)
    {
        exti_source_pin = EXTI_SOURCE_PIN0;
        exti_num = EXTI_0;
    }
    else if(exti_pin == GPIO_PIN_1)
    {
        exti_source_pin = EXTI_SOURCE_PIN1;
        exti_num = EXTI_1;
    }
    else if(exti_pin == GPIO_PIN_2)
    {
        exti_source_pin = EXTI_SOURCE_PIN2;
        exti_num = EXTI_2;
    }
    else if(exti_pin == GPIO_PIN_3)
    {
        exti_source_pin = EXTI_SOURCE_PIN3;
        exti_num = EXTI_3;
    }
    else if(exti_pin == GPIO_PIN_4)
    {
        exti_source_pin = EXTI_SOURCE_PIN4;
        exti_num = EXTI_4;
    }
    else if(exti_pin == GPIO_PIN_5)
    {
        exti_source_pin = EXTI_SOURCE_PIN5;
        exti_num = EXTI_5;
    }
    else if(exti_pin == GPIO_PIN_6)
    {
        exti_source_pin = EXTI_SOURCE_PIN6;
        exti_num = EXTI_6;
    }
    else if(exti_pin == GPIO_PIN_7)
    {
        exti_source_pin = EXTI_SOURCE_PIN7;
        exti_num = EXTI_7;
    }
    else if(exti_pin == GPIO_PIN_8)
    {
        exti_source_pin = EXTI_SOURCE_PIN8;
        exti_num = EXTI_8;
    }
    else if(exti_pin == GPIO_PIN_9)
    {
        exti_source_pin = EXTI_SOURCE_PIN9;
        exti_num = EXTI_9;
    }
    else if(exti_pin == GPIO_PIN_10)
    {
        exti_source_pin = EXTI_SOURCE_PIN10;
        exti_num = EXTI_10;
    }
    else if(exti_pin == GPIO_PIN_11)
    {
        exti_source_pin = EXTI_SOURCE_PIN11;
        exti_num = EXTI_11;
    }
    else if(exti_pin == GPIO_PIN_12)
    {
        exti_source_pin = EXTI_SOURCE_PIN12;
        exti_num = EXTI_12;
    }
    else if(exti_pin == GPIO_PIN_13)
    {
        exti_source_pin = EXTI_SOURCE_PIN13;
        exti_num = EXTI_13;
    }
    else if(exti_pin == GPIO_PIN_14)
    {
        exti_source_pin = EXTI_SOURCE_PIN14;
        exti_num = EXTI_14;
    }
    else if(exti_pin == GPIO_PIN_15)
    {
        exti_source_pin = EXTI_SOURCE_PIN15;
        exti_num = EXTI_15;
    }

    /* 配置GPIO引脚作为中断源 */
    syscfg_exti_line_config(exti_source_gpio, exti_source_pin);

    /* 中断触发方式初始化 */
    if(Mode == CHANGE)       exti_init(exti_num, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
    else if(Mode == RISING)  exti_init(exti_num, EXTI_INTERRUPT, EXTI_TRIG_RISING);
    else if(Mode == FALLING) exti_init(exti_num, EXTI_INTERRUPT, EXTI_TRIG_FALLING);

    /* 清除中断标志位 */
    exti_interrupt_flag_clear(exti_num);

    /* 使能外部中断 */
    exti_interrupt_enable(exti_num);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        关闭引脚外部中断
// @param        exti_pin            选择的引脚：GPIO_PIN_x(x=0..15)
// @return       void
// Sample usage:        exti_disable(GPIO_PIN_0);
                        //关闭引脚PX0的外部中断（X=A、B、C、F）
//-------------------------------------------------------------------------------------------------------------------
void exti_disable(uint32_t exti_pin)
{
    uint32_t exti_num;

    if(exti_pin == GPIO_PIN_0)        exti_num = EXTI_0;
    else if(exti_pin == GPIO_PIN_1)   exti_num = EXTI_1;
    else if(exti_pin == GPIO_PIN_2)   exti_num = EXTI_2;
    else if(exti_pin == GPIO_PIN_3)   exti_num = EXTI_3;
    else if(exti_pin == GPIO_PIN_4)   exti_num = EXTI_4;
    else if(exti_pin == GPIO_PIN_5)   exti_num = EXTI_5;
    else if(exti_pin == GPIO_PIN_6)   exti_num = EXTI_6;
    else if(exti_pin == GPIO_PIN_7)   exti_num = EXTI_7;
    else if(exti_pin == GPIO_PIN_8)   exti_num = EXTI_8;
    else if(exti_pin == GPIO_PIN_9)   exti_num = EXTI_9;
    else if(exti_pin == GPIO_PIN_10)  exti_num = EXTI_10;
    else if(exti_pin == GPIO_PIN_11)  exti_num = EXTI_11;
    else if(exti_pin == GPIO_PIN_12)  exti_num = EXTI_12;
    else if(exti_pin == GPIO_PIN_13)  exti_num = EXTI_13;
    else if(exti_pin == GPIO_PIN_13)  exti_num = EXTI_13;
    else if(exti_pin == GPIO_PIN_14)  exti_num = EXTI_14;
    else if(exti_pin == GPIO_PIN_15)  exti_num = EXTI_15;

    /* 失能外部中断 */
    exti_interrupt_disable(exti_num);
}
