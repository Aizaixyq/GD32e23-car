/*********************************************************************************************************************
* @file            hf_HC-SR04.c
* @author          Davis Klay HF
* @version         1.0
* @Target core     GD32E230C8T6
* @date            2021-9-29
********************************************************************************************************************/

#include "HF_HC-SR04.h"

#define max     5000U
#define prescal 72U
#define speed   334.52

unsigned int g_overflow_times;
unsigned int g_current_time_value;
unsigned char g_flag_unhandler;

//-------------------------------------------------------------------------------------------------------------------
// @brief        超声波初始化
// @param        void
// @return       void
// Sample usage:        ultrasonic_init(); 
                        //初始化超声波功能
//-------------------------------------------------------------------------------------------------------------------
void ultra_init(void)
{
    /* 使能CFGCMP时钟 */
    rcu_periph_clock_enable(RCU_CFGCMP);

    /* 配置PB0为超声波trig引脚 */
    gpio_init(TRIG_PORT, TRIG_MODE, TRIG_PIN);
    gpio_bit_output(TRIG_PORT, TRIG_PIN, 0);

    /* 配置PA6为超声波ehco引脚 */
    gpio_init(ECHO_PORT, ECHO_MODE, ECHO_PIN);

    /* 设置中断EXTI6为高优先级 */
    nvic_irq_enable(EXTI4_15_IRQn, 0U);//此处的中断号名称参考gd32e23x.h
    nvic_irq_enable(TIMER5_IRQn, 1U);

    /* 配置PA6为中断源，对脉冲信号进行计数 */
    syscfg_exti_line_config(EXTI_PORT, EXTI_PIN);

    /* 配置中断EXTI6并清除中断标志位*/
    exti_init(EXTI_NUM, EXTI_INTERRUPT, EXTI_TRIG_BOTH);
    exti_interrupt_flag_clear(EXTI_NUM);
    exti_interrupt_enable(EXTI_NUM);

    /* 配置定时器 */

    /* 配置定时器时钟 */
    rcu_periph_clock_enable(RCU_TIMER5);
    timer_parameter_struct timer_initpara;
    /* 初始化TIMER5 */
    timer_deinit(TIMER5);
    /* 配置TIMER5 */
    timer_initpara.prescaler = prescal - 1;
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = max - 1;
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0U;

    /* 配置定时器结构体并配置定时器TIMER5 */
    timer_init(TIMER5, &timer_initpara);
    /* 使能定时器重装载 */
    timer_auto_reload_shadow_enable(TIMER5);
    /* 清除TIMER5中断标志位 */
    timer_interrupt_flag_clear(TIMER5, TIMER_INT_FLAG_UP);
    /* 使能TIMER5中断 */
    timer_interrupt_enable(TIMER5, TIMER_INT_UP);

	g_overflow_times = 0;
    g_current_time_value = 0;
    g_flag_unhandler = 0;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        超声波发射一次并返回距离
// @param        void            
// @return       float            测得的距离
// Sample usage:        ultrasonic_output(); 
                        //获取超声波测得的距离
//-------------------------------------------------------------------------------------------------------------------
unsigned int ultra_get_distance(void)
{   
    unsigned int distance;

    while (gpio_get_input(ECHO_PORT, ECHO_PIN) == 1)
	{
	    ; //wait end
	}

    /* 超声波trig引脚置1 */
    gpio_bit_output(TRIG_PORT, TRIG_PIN, 1);
    delay_1us(20);

    gpio_bit_output(TRIG_PORT, TRIG_PIN, 0);

    while (g_flag_unhandler) 
    {
        g_flag_unhandler = 0; 
		
		/* 计算单次求得的距离 */
        distance = (unsigned int)100 * ((g_overflow_times + (float)g_current_time_value / max) * max * prescal / (float)72000000 * speed * 100) / 2; 
    }
	
	g_overflow_times = 0;
    g_current_time_value = 0;

    return distance;
}

