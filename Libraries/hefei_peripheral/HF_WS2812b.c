/*********************************************************************************************************************
* @file            HF_WS2812b.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "HF_WS2812b.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        RGB初始化
// @param        void
// @return       void
// Sample usage:        ws2812b_init(); 
                        //RGB灯初始化
//-------------------------------------------------------------------------------------------------------------------
void ws2812b_init()
{
    gpio_init(GPIOB, OUT_AF_1_PP, GPIO_PIN_4);
    pwm_init(TIMER2, TIMER_CH_0, 9, 20, 0);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        RGB写入
// @param        GRB             写入的数组
// @return       void
// Sample usage:        uint8_t RGB[3] = {0xff,0x00,0x00};	ws2812b_write(RGB); 
                        //向RGB写入数组，显示红色
//-------------------------------------------------------------------------------------------------------------------
void ws2812b_write(unsigned char* rgb_value)	
{
    unsigned char grb_value[3];
    unsigned int j, i;
	
    grb_value[0] = rgb_value[1];
    grb_value[1] = rgb_value[0];
    grb_value[2] = rgb_value[2];

    for(j=0; j<3; j++)
    {
        for(i=8; i>0; i--)
        {
            if((*(grb_value+j) >> (i-1)) & 0x01)
            {
                //设置阈值(比较值,调节占空比的时候调节这个值)
                pwm_duty(TIMER2, TIMER_CH_0, 3000);/*发1*/
            }
            else
            {
                pwm_duty(TIMER2, TIMER_CH_0, 1000);/*发0*/
            }
        timer_enable(TIMER2);
						
        while(!timer_flag_get(TIMER2, TIMER_FLAG_UP));
        timer_disable(TIMER2);
        timer_flag_clear(TIMER2, TIMER_FLAG_UP);
        }
    }
}
