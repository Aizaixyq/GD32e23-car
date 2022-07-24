/*********************************************************************************************************************
* @file            LINKF_L9110S_2.c
* @author          Davis Klay HF
* @version         1.0
* @Target core     GD32E230C8T6
* @date            2021-9-26
********************************************************************************************************************/

#include "HF_L9110S_2.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        PWM初始化
// @param        object            控制对象       
// @return       void
// Sample usage:        PWM_9110_init(left); 
                        //初始化左电机PWM
//-------------------------------------------------------------------------------------------------------------------
void l9110s_init(left_or_right object)
{
    if(object == right)
    {
        gpio_init(L_PWM1_PORT, L_PWM1_MODE, L_PWM1_PIN);
        gpio_init(L_PWM2_PORT, L_PWM2_MODE, L_PWM2_PIN);
        pwm_init(L_PWM1_TIMER, L_PWM1_TIMER_CH, 72, 2500, 0);
        pwm_init(L_PWM2_TIMER, L_PWM2_TIMER_CH, 72, 2500, 0);
    }
    else if(object == left)
    {
        gpio_init(R_PWM1_PORT, R_PWM1_MODE, R_PWM1_PIN);
        gpio_init(R_PWM2_PORT, R_PWM2_MODE, R_PWM2_PIN);
        pwm_init(R_PWM1_TIMER, R_PWM1_TIMER_CH, 72, 2500, 0);
        pwm_init(R_PWM2_TIMER, R_PWM2_TIMER_CH, 72, 2500, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        控制电机正转
// @param        object            控制对象
// @param        value             PWM占空比(0-10000)
// @return       void 
// Sample usage:        PWM_9110_forward(right, 10000);
                        //右电机满速正转(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void l9110s_forward(left_or_right object, uint16_t value)
{
    if(object == right)
    {
        pwm_duty(L_PWM2_TIMER, L_PWM2_TIMER_CH, value);
        pwm_duty(L_PWM1_TIMER, L_PWM1_TIMER_CH, 0);
    }
    else if(object == left)
    {
        pwm_duty(R_PWM1_TIMER, R_PWM1_TIMER_CH, value);
        pwm_duty(R_PWM2_TIMER, R_PWM2_TIMER_CH, 0);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        控制电机反转
// @param        object            控制对象
// @param        value             PWM占空比(0-10000)
// @return       void 
// Sample usage:        PWM_9110_back(left, 10000)；
                        //左电机满速反转(10000/10000)
//-------------------------------------------------------------------------------------------------------------------
void l9110s_backward(left_or_right object, uint16_t value)
{
    if(object == right)
    {
        pwm_duty(L_PWM2_TIMER, L_PWM2_TIMER_CH, 0);
        pwm_duty(L_PWM1_TIMER, L_PWM1_TIMER_CH, value);
    }
    else if(object == left)
    {
        pwm_duty(R_PWM1_TIMER, R_PWM1_TIMER_CH, 0);
        pwm_duty(R_PWM2_TIMER, R_PWM2_TIMER_CH, value);
    }
}


