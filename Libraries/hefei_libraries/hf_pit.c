/*********************************************************************************************************************
* @file            hf_pit.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_pit.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        定时器中断初始化(ms)
// @param        timer_periph	选择中断使用的定时器（TIMER2,5,13,14,15,16）
// @param        timer_period	设置中断时间（ms）
// @return       void
// Sample usage:        timer_pit_interrupt_ms(TIMER2, 1000); 
//                      //开启TIMER2 1000ms定时器中断
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_interrupt_ms(uint32_t timer_periph, uint16_t timer_period)
{
    if(timer_periph == TIMER2)
    {
        nvic_irq_enable(TIMER2_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER2);
    }
    else if(timer_periph == TIMER5)
    {
        nvic_irq_enable(TIMER5_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER5);
    }
    else if(timer_periph == TIMER13)
    {
        nvic_irq_enable(TIMER13_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER13);
    }
    else if(timer_periph == TIMER14)
    {
        nvic_irq_enable(TIMER14_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER14);
    }
    else if(timer_periph == TIMER15)
    {
        nvic_irq_enable(TIMER15_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER15);
    }
    else if(timer_periph == TIMER16)
    {
        nvic_irq_enable(TIMER16_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER16);
    }
    /* 复位外设TIMER */
    timer_deinit(timer_periph);

    /* TIMER结构体的配置 */
    timer_parameter_struct timer_initpara;

    timer_initpara.prescaler         = 7199;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = timer_period*10-1;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(timer_periph, &timer_initpara);

    /* 清除外设TIMER的更新中断标志位 */
    timer_interrupt_flag_clear(timer_periph, TIMER_INT_FLAG_UP);
    /* 使能TIMER中断 */
    timer_interrupt_enable(timer_periph, TIMER_INT_UP);
    /* 使能中断更新并使能TIMER */
    timer_enable(timer_periph);	
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        定时器中断初始化(us)
// @param        timer_periph	选择中断使用的定时器（TIMER2,5,13,14,15,16）
// @param        timer_period	设置中断时间（us）
// @return       void
// Sample usage:        timer_pit_interrupt_us(TIMER2, 1000);
//                      //开启TIMER2 1000us定时器中断
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_interrupt_us(uint32_t timer_periph, uint16_t timer_period)
{
    if(timer_periph == TIMER2)
    {
        nvic_irq_enable(TIMER2_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER2);
    }
    else if(timer_periph == TIMER5)
    {
        nvic_irq_enable(TIMER5_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER5);
    }
    else if(timer_periph == TIMER13)
    {
        nvic_irq_enable(TIMER13_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER13);
    }
    else if(timer_periph == TIMER14)
    {
        nvic_irq_enable(TIMER14_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER14);
    }
    else if(timer_periph == TIMER15)
    {
        nvic_irq_enable(TIMER15_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER15);
    }
    else if(timer_periph == TIMER16)
    {
        nvic_irq_enable(TIMER16_IRQn, 0);
        rcu_periph_clock_enable(RCU_TIMER16);
    }
    /* 复位外设TIMER */
    timer_deinit(timer_periph);

    /* TIMER结构体的配置 */
    timer_parameter_struct timer_initpara;

    timer_initpara.prescaler         = 9;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = timer_period*72-1;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(timer_periph, &timer_initpara);

    /* 清除外设TIMER的更新中断标志位 */
    timer_interrupt_flag_clear(timer_periph, TIMER_INT_FLAG_UP);
    /* 使能TIMER中断 */
    timer_interrupt_enable(timer_periph, TIMER_INT_UP);
    /* 使能中断更新并使能TIMER */
    timer_enable(timer_periph);	
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        关闭定时器中断
// @param        timer_periph	选择关闭的定时器中断（TIMER2,5,13,14,15,16）
// @return       void
// Sample usage:        timer_pit_interrupt_us(TIMER2);
//                      //关闭TIMER2定时器中断
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_close(uint32_t timer_periph)
{
    timer_disable(timer_periph);	
}
