/*********************************************************************************************************************
* @file            hf_pwm.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_pwm.h"

uint16_t period[6]={0,};

//-------------------------------------------------------------------------------------------------------------------
//@brief        PWM ��ʼ��(���Ŷ�Ӧͨ����PWM ���ų�ʼ������)
//@param        timer_periph:            TIMERx(x=0,2,13..16)
//@param        timer_ch:                TIMER_CH_x(x=0..15)
//@param        freq_div                 Ԥ��Ƶֵ(0~65535)
//@param        period_temp              �Զ���װ��ֵ(0~65535)
//@param        duty				     ռ�ձȣ�0-10000��
//@return       void
//Sample usage:        pwm_timer_init(TIMER2, TIMER_CH_0, 72, 10000, 2000); 
                       //��ʱ��TIMER2_CH_0���PWM�ź�,Ƶ��Ϊ100Hz(72MHz/72/10000),ռ�ձ�Ϊ20��(2000/10000)
                       //Ƶ�ʼ��㹫ʽ��PWM�ź�Ƶ�� = ʱ��Ƶ�ʣ�72MHz�� / Ԥ��Ƶֵ / �Զ���װ��ֵ
//-------------------------------------------------------------------------------------------------------------------
void pwm_init(uint32_t timer_periph, uint16_t timer_ch, uint16_t freq_div, uint16_t period_temp, uint16_t duty)
{
    /* ʹ�ܶ�ʱ��ʱ��,��¼�Զ���װ��ֵ */
    if(timer_periph == TIMER0)
    {
        rcu_periph_clock_enable(RCU_TIMER0);
        period[0] = period_temp;
    }
    else if(timer_periph == TIMER2)
    {
        rcu_periph_clock_enable(RCU_TIMER2);
        period[1] = period_temp;
    }
    else if(timer_periph == TIMER13)
    {
        rcu_periph_clock_enable(RCU_TIMER13);
        period[2] = period_temp;
    }
    else if(timer_periph == TIMER14)
    {
        rcu_periph_clock_enable(RCU_TIMER14);
        period[3] = period_temp;
    }
    else if(timer_periph == TIMER15)
    {
        rcu_periph_clock_enable(RCU_TIMER15);
        period[4] = period_temp;
    }
    else if(timer_periph == TIMER16)
    {
        rcu_periph_clock_enable(RCU_TIMER16);
        period[5] = period_temp;
    }

    /* ��λ����TIMER */					
    timer_deinit(timer_periph);

    /* TIMER�ṹ������ */
    timer_parameter_struct timer_initpara;											
    /* д��Ԥ��Ƶֵ */
    timer_initpara.prescaler         = freq_div-1;
    /* ����ģʽΪ��Ե���� */												
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    /* ������ʽΪ���ϼ��� */											
    timer_initpara.counterdirection  = TIMER_COUNTER_DOWN;	
    /* д���Զ���װ��ֵ */										
    timer_initpara.period            = period_temp-1;	
    /* ѡ��ʱ�ӷ�Ƶ���� */
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    /* д���ظ�����ֵ */											
    timer_initpara.repetitioncounter = 0;
    /* ��ʼ�����趨ʱ�� */														
    timer_init(timer_periph,&timer_initpara);

    /* TIMER����Ƚ�ģʽ�ṹ������ */
    timer_oc_parameter_struct timer_ocintpara;														
    /* ͨ�������������Ϊ�� */
    timer_ocintpara.ocpolarity   = TIMER_OC_POLARITY_HIGH;
    /* ͨ�����ʹ�� */	
    timer_ocintpara.outputstate  = TIMER_CCX_ENABLE;	
    /* ����ͨ�������������Ϊ�� */
    timer_ocintpara.ocnpolarity  = TIMER_OCN_POLARITY_HIGH;	
    /* ����ͨ��������� */										
    timer_ocintpara.outputnstate = TIMER_CCXN_DISABLE;
    /* ����״̬��ͨ�����Ϊ�� */											
    timer_ocintpara.ocidlestate  = TIMER_OC_IDLE_STATE_LOW;
    /* ����״̬�»���ͨ�����Ϊ�� */					
    timer_ocintpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;

	/* ���趨ʱ����ͨ��������� */
    timer_channel_output_config(timer_periph,timer_ch,&timer_ocintpara);
    /* �������趨ʱ����ͨ������Ƚ�ֵ */					
    timer_channel_output_pulse_value_config(timer_periph,timer_ch, duty * period_temp / 10000);
    /* �������趨ʱ��ͨ������Ƚ�ģʽ��PWM0/PWM1) */
    timer_channel_output_mode_config(timer_periph,timer_ch,TIMER_OC_MODE_PWM0);

    /* ��ʱ��ͨ�����Ӱ�ӼĴ������� */
    timer_channel_output_shadow_config(timer_periph,timer_ch,TIMER_OC_SHADOW_DISABLE);	
    /* ��ʱ��ͨ�����ʹ�� */			
    timer_primary_output_config(timer_periph,ENABLE);	
    /* ��ʱ���Զ�����Ӱ��ʹ�� */				
    timer_auto_reload_shadow_enable(timer_periph);
    /* ��ʱ��ʹ�� */													
    timer_enable(timer_periph);																	
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        PWM Ƶ������
//@param        timer_periph:            TIMERx(x=0,2,13..16)
//@param        freq_div                 Ԥ��Ƶֵ(0~65535)
//@param        period_temp              �Զ���װ��ֵ(0~65535)
//@return       void
//Sample usage:        pwm_freq(TIMER2,72, 10000); 
                       //����TIMER2��ͨ�������PWM�ź�Ƶ��Ϊ100Hz(72MHz/72/10000)
                       //Ƶ�ʼ��㹫ʽ��PWM�ź�Ƶ�� = ʱ��Ƶ�ʣ�72MHz�� / Ԥ��Ƶֵ / �Զ���װ��ֵ
//-------------------------------------------------------------------------------------------------------------------
void pwm_freq(uint32_t timer_periph, uint16_t freq_div, uint16_t period_temp)
{
    timer_prescaler_config (timer_periph, freq_div - 1, TIMER_PSC_RELOAD_NOW);
    timer_autoreload_value_config (timer_periph, period_temp - 1);
    if(timer_periph == TIMER0) period[0] = period_temp;
    else if(timer_periph == TIMER2) period[1] = period_temp;
    else if(timer_periph == TIMER13) period[2] = period_temp;
    else if(timer_periph == TIMER14) period[3] = period_temp;
    else if(timer_periph == TIMER15) period[4] = period_temp;
    else if(timer_periph == TIMER16) period[5] = period_temp;
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        PWM ռ�ձ�����
//@param        timer_periph:            TIMERx(x=0,2,13..16)
//@param        timer_ch:                TIMER_CH_x(x=0..15)
//@param        duty				     ռ�ձȣ�0-10000��
//@return		void
//Sample usage:        pwm_duty(TIMER2, TIMER_CH_1, 2000); 
                       //����TIMER2ͨ��1PWM���ռ�ձ�Ϊ20��(2000/10000)
//-------------------------------------------------------------------------------------------------------------------
void pwm_duty(uint32_t timer_periph, uint32_t timer_ch, uint16_t duty)
{
    uint16_t Period;

    if(timer_periph == TIMER0) Period = period[0];
    else if(timer_periph == TIMER2) Period = period[1];
    else if(timer_periph == TIMER13) Period = period[2];
    else if(timer_periph == TIMER14) Period = period[3];
    else if(timer_periph == TIMER15) Period = period[4];
    else if(timer_periph == TIMER16) Period = period[5];

    timer_channel_output_pulse_value_config(timer_periph, timer_ch, duty * Period / 10000);
}

//-------------------------------------------------------------------------------------------------------------------
//@brief        PWM ֹͣ
//@param        timer_periph:            TIMERx(x=0,2,13..16)
//@return		void
//Sample usage:        pwm_stop(TIMER2); 
                       //ֹͣTIMER2����ͨ����PWM���
//-------------------------------------------------------------------------------------------------------------------
void pwm_stop(uint32_t timer_periph)
{
    /* ��ʱ��ʧ���� */													
    timer_disable(timer_periph);
}
