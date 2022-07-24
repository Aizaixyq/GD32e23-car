/*********************************************************************************************************************
* @file            HF_WS2812b.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "HF_WS2812b.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        RGB��ʼ��
// @param        void
// @return       void
// Sample usage:        ws2812b_init(); 
                        //RGB�Ƴ�ʼ��
//-------------------------------------------------------------------------------------------------------------------
void ws2812b_init()
{
    gpio_init(GPIOB, OUT_AF_1_PP, GPIO_PIN_4);
    pwm_init(TIMER2, TIMER_CH_0, 9, 20, 0);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        RGBд��
// @param        GRB             д�������
// @return       void
// Sample usage:        uint8_t RGB[3] = {0xff,0x00,0x00};	ws2812b_write(RGB); 
                        //��RGBд�����飬��ʾ��ɫ
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
                //������ֵ(�Ƚ�ֵ,����ռ�ձȵ�ʱ��������ֵ)
                pwm_duty(TIMER2, TIMER_CH_0, 3000);/*��1*/
            }
            else
            {
                pwm_duty(TIMER2, TIMER_CH_0, 1000);/*��0*/
            }
        timer_enable(TIMER2);
						
        while(!timer_flag_get(TIMER2, TIMER_FLAG_UP));
        timer_disable(TIMER2);
        timer_flag_clear(TIMER2, TIMER_FLAG_UP);
        }
    }
}
