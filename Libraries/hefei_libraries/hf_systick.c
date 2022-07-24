/*********************************************************************************************************************
* @file            hf_systick.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "hf_systick.h"

volatile static float count_1us = 0;
volatile static float count_1ms = 0;

//-------------------------------------------------------------------------------------------------------------------
// @brief        配置时钟
// @param        void
// @return       void
//-------------------------------------------------------------------------------------------------------------------
void systick_config(void)
{
    /* systick clock source is from HCLK/8 */
    systick_clksource_set(SYSTICK_CLKSOURCE_HCLK_DIV8);
    count_1us = (float)SystemCoreClock/8000000;
    count_1ms = (float)count_1us * 1000;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        微秒级延时
// @param        count            延时时间
// @return       void
// Sample usage:        delay_1us(50);
//                      //延时50微秒
//-------------------------------------------------------------------------------------------------------------------
void delay_1us(uint32_t count)
{
    uint32_t ctl;
    
    /* reload the count value */
    SysTick->LOAD = (uint32_t)(count * count_1us);
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
    /* enable the systick timer */
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
    /* wait for the COUNTFLAG flag set */
    do{
        ctl = SysTick->CTRL;
    }while((ctl&SysTick_CTRL_ENABLE_Msk)&&!(ctl & SysTick_CTRL_COUNTFLAG_Msk));
    /* disable the systick timer */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        毫秒级延时
// @param        count            延时时间
// @return       void
// Sample usage:        delay_1ms(50);
//                      //延时50毫秒
//-------------------------------------------------------------------------------------------------------------------
void delay_1ms(uint32_t count)
{
    uint32_t ctl;
    
    /* reload the count value */
    SysTick->LOAD = (uint32_t)(count * count_1ms);
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
    /* enable the systick timer */
    SysTick->CTRL = SysTick_CTRL_ENABLE_Msk;
    /* wait for the COUNTFLAG flag set */
    do{
        ctl = SysTick->CTRL;
    }while((ctl&SysTick_CTRL_ENABLE_Msk)&&!(ctl & SysTick_CTRL_COUNTFLAG_Msk));
    /* disable the systick timer */
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    /* clear the current count value */
    SysTick->VAL = 0x0000U;
}
