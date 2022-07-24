/*********************************************************************************************************************
* @file            hf_pit.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_pit.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ʱ���жϳ�ʼ��(ms)
// @param        timer_periph	ѡ���ж�ʹ�õĶ�ʱ����TIMER2,5,13,14,15,16��
// @param        timer_period	�����ж�ʱ�䣨ms��
// @return       void
// Sample usage:        timer_pit_interrupt_ms(TIMER2, 1000); 
//                      //����TIMER2 1000ms��ʱ���ж�
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
    /* ��λ����TIMER */
    timer_deinit(timer_periph);

    /* TIMER�ṹ������� */
    timer_parameter_struct timer_initpara;

    timer_initpara.prescaler         = 7199;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = timer_period*10-1;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(timer_periph, &timer_initpara);

    /* �������TIMER�ĸ����жϱ�־λ */
    timer_interrupt_flag_clear(timer_periph, TIMER_INT_FLAG_UP);
    /* ʹ��TIMER�ж� */
    timer_interrupt_enable(timer_periph, TIMER_INT_UP);
    /* ʹ���жϸ��²�ʹ��TIMER */
    timer_enable(timer_periph);	
}


//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ʱ���жϳ�ʼ��(us)
// @param        timer_periph	ѡ���ж�ʹ�õĶ�ʱ����TIMER2,5,13,14,15,16��
// @param        timer_period	�����ж�ʱ�䣨us��
// @return       void
// Sample usage:        timer_pit_interrupt_us(TIMER2, 1000);
//                      //����TIMER2 1000us��ʱ���ж�
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
    /* ��λ����TIMER */
    timer_deinit(timer_periph);

    /* TIMER�ṹ������� */
    timer_parameter_struct timer_initpara;

    timer_initpara.prescaler         = 9;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = timer_period*72-1;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_init(timer_periph, &timer_initpara);

    /* �������TIMER�ĸ����жϱ�־λ */
    timer_interrupt_flag_clear(timer_periph, TIMER_INT_FLAG_UP);
    /* ʹ��TIMER�ж� */
    timer_interrupt_enable(timer_periph, TIMER_INT_UP);
    /* ʹ���жϸ��²�ʹ��TIMER */
    timer_enable(timer_periph);	
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        �رն�ʱ���ж�
// @param        timer_periph	ѡ��رյĶ�ʱ���жϣ�TIMER2,5,13,14,15,16��
// @return       void
// Sample usage:        timer_pit_interrupt_us(TIMER2);
//                      //�ر�TIMER2��ʱ���ж�
//-------------------------------------------------------------------------------------------------------------------
void timer_pit_close(uint32_t timer_periph)
{
    timer_disable(timer_periph);	
}
