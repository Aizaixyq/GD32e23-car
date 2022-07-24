/*********************************************************************************************************************
* @file            hf_qtimer.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_qtimer.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��������ʼ��
// @param        Encodernum            ѡ��ı�������Encoder1��2��Encoder_ALL
// @param        mode                  ѡ��ı���������ģʽ��Mode1(������)��2(����)
// @return       void
// Sample usage:        Encoder_Init(Encoder_ALL, Mode1);
//                      //��ʼ��������1�ͱ�����2������ģʽΪ������
//-------------------------------------------------------------------------------------------------------------------
void timer_quad_init(encoder_typedef_enum Encodernum)
{

    rcu_periph_clock_enable(RCU_GPIOA);

    /* ����A,B���ż����ù��ܣ���ΪTIMERͨ�� */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_7);
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_6);
    gpio_af_set(GPIOA, GPIO_AF_1, GPIO_PIN_7);
    gpio_af_set(GPIOA, GPIO_AF_1, GPIO_PIN_6);

    /* ���嶨ʱ���ṹ�� */
    timer_parameter_struct timer_initpara;

    /* ���ö�ʱ��ʱ�� */
    rcu_periph_clock_enable(RCU_TIMER2);

    /* ��ʼ��TIMER2 */
    timer_deinit(TIMER2);

    /* ���ö�ʱ���ṹ�岢���ö�ʱ�� */
    timer_initpara.prescaler         = 9;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 5000;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER2,&timer_initpara);

    /* ʹ�ܶ�ʱ����װ�� */
    timer_auto_reload_shadow_enable(TIMER2);

    /* ���ö�ʱ������������ */
    timer_quadrature_decoder_mode_config(TIMER2,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);

    /* ʹ�ܶ�ʱ�� */
    timer_enable(TIMER2);


    /* ����A,B���ż����ù��ܣ���ΪTIMERͨ�� */
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_9);
    gpio_mode_set(GPIOA, GPIO_MODE_AF, GPIO_PUPD_PULLUP, GPIO_PIN_8);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_9);
    gpio_af_set(GPIOA, GPIO_AF_2, GPIO_PIN_8);


    /* ���ö�ʱ��ʱ�� */
    rcu_periph_clock_enable(RCU_TIMER0);

    /* ��ʼ��TIMER2 */
    timer_deinit(TIMER0);

    /* ���ö�ʱ���ṹ�岢���ö�ʱ�� */
    timer_initpara.prescaler         = 9;
    timer_initpara.alignedmode       = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection  = TIMER_COUNTER_UP;
    timer_initpara.period            = 5000;
    timer_initpara.clockdivision     = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER0,&timer_initpara);

    /* ʹ�ܶ�ʱ����װ�� */
    timer_auto_reload_shadow_enable(TIMER0);

    /* ���ö�ʱ������������ */
    timer_quadrature_decoder_mode_config(TIMER0,TIMER_ENCODER_MODE2,TIMER_IC_POLARITY_RISING,TIMER_IC_POLARITY_RISING);

    /* ʹ�ܶ�ʱ�� */
    timer_enable(TIMER0);

}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ��ȡ������ֵ
// @param        Encodernum            ѡ��ı�������Encoder1��2��Encoder_ALL
// @return       int16
// Sample usage:        int16 value;value = Encoder_Read(Encoder1);
//                      //��ȡ������1��ֵ������value
//-------------------------------------------------------------------------------------------------------------------
int16_t timer_quad_get(encoder_typedef_enum Encodernum)
{
    int16_t value, value1, value2;

    value1 = 0;
    value2 = 0;
    if(Encodernum == Encoder1)
    {
        value1 = timer_counter_read(TIMER0)-10000;
        timer_counter_value_config(TIMER0,10000);
        value = value1;
    }
    else if(Encodernum == Encoder2)
    {
        value2 = timer_counter_read(TIMER2)-10000;
        timer_counter_value_config(TIMER2,10000);
        value = value2;
    }
    return value;
}
