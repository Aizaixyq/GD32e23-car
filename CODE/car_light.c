/*********************************************************************************************************************
* @file            car_light.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "car_light.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ܳ�β��ͬʱ����
// @param        color          β����ɫ
// @param        time           ��ʱʱ��(ms)
// @return       void
// Sample usage:        car_both_rgb_on(red, 1000);//β��ͬʱ��ʾ��ɫ����ʱ1s
//-------------------------------------------------------------------------------------------------------------------
void car_both_rgb_on(rgb_color color, unsigned int time)
{
    if(color == red)
    {	
        ws2812b_write(rgb_red);
        ws2812b_write(rgb_red);
        delay_1ms(time);
    }
    else if(color == yellow)
    {
        ws2812b_write(rgb_yellow);
        ws2812b_write(rgb_yellow);
        delay_1us(time);
    }
    else if(color == white)
    {
        ws2812b_write(rgb_white);
        ws2812b_write(rgb_white);
        delay_1ms(time);
    }
    else if(color == blue)
    {
        ws2812b_write(rgb_blue);
        ws2812b_write(rgb_blue);
        delay_1ms(time);
    }
    else if(color == green)
    {
        ws2812b_write(rgb_green);
        ws2812b_write(rgb_green);
        delay_1ms(time);
    }
    else if(color == cyan)
    {
        ws2812b_write(rgb_cyan);
        ws2812b_write(rgb_cyan);
        delay_1ms(time);
    }
    else if(color == purple)
    {
        ws2812b_write(rgb_purple);
        ws2812b_write(rgb_purple);
        delay_1ms(time);
    }
    else 
    {
        ws2812b_write(rgb_user_define);
        ws2812b_write(rgb_user_define);
        delay_1ms(time);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ܳ�β�������˸
// @param        color          β����ɫ
// @param        flash_count    ��˸����
// @param        time           ���ʱ��(ms)
// @return       void
// Sample usage:        car_left_rgb_flash(red, 3, 500);//�����˸��ɫ���Σ����0.5s
//-------------------------------------------------------------------------------------------------------------------
void car_left_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time)
{
    unsigned int i;
	
    if(color == red)
    {				  
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_red);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);

            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == red)
    else if(color == yellow)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_yellow);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);

            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == yellow)
    else if(color == white)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_white);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == white)
    else if(color == green)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_green);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == green)
    else if(color == blue)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_blue);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == blue)
    else if(color == cyan)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_cyan);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == cyan)
    else if(color == purple)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_purple);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else if(color == purple)
    else 
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_user_define);
            ws2812b_write(rgb_off);
		
            delay_1ms(time);
					
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ܳ�β��Ϩ��
// @param        void
// @return       void
// Sample usage:        car_both_rgb_off();//β��Ϩ��
//-------------------------------------------------------------------------------------------------------------------
void car_both_rgb_off(void)
{
    ws2812b_write(rgb_off);
    ws2812b_write(rgb_off);
    delay_1ms(50);
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ܳ�β���ҵ���˸
// @param        color          β����ɫ
// @param        flash_count    ��˸����
// @param        time           ���ʱ��(ms)
// @return       void
// Sample usage:        car_right_rgb_flash(red, 3, 500);//�ҵ���˸��ɫ���Σ����0.5s
//-------------------------------------------------------------------------------------------------------------------
void car_right_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time)
{
    unsigned int i;
	
    if(color == red)
    {	
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_red);
		
            delay_1ms(time);
      
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == red)
    else if(color == yellow)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_yellow);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == yellow)
    else if(color == white)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_white);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == white)
    else if(color == green)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_green);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == green)
    else if(color == blue)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_blue);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == blue)
    else if(color == cyan)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_cyan);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == cyan)
    else if(color == purple)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_purple);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == purple)
    else 
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_user_define);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        ���ܳ�����β��ͬʱ��˸
// @param        color          β����ɫ
// @param        flash_count    ��˸����
// @param        time           ���ʱ��(ms)
// @return       void
// Sample usage:        car_both_rgb_flash(red, 3, 500);//β��ͬʱ��˸��ɫ���Σ����0.5s
//-------------------------------------------------------------------------------------------------------------------
void car_both_rgb_flash(rgb_color color, unsigned int flash_count, unsigned int time)
{
    unsigned int i;
	
    if(color == red)
    {	
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_red);
            ws2812b_write(rgb_red);
		
            delay_1ms(time);
      
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == red)
    else if(color == yellow)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_yellow);
            ws2812b_write(rgb_yellow);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == yellow)
    else if(color == white)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_white);
            ws2812b_write(rgb_white);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == white)
    else if(color == green)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_green);
            ws2812b_write(rgb_green);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == green)
    else if(color == blue)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_blue);
            ws2812b_write(rgb_blue);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == blue)		
    else if(color == cyan)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_cyan);
            ws2812b_write(rgb_cyan);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == cyan)		
    else if(color == purple)
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_purple);
            ws2812b_write(rgb_purple);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of if(color == purple)
    else 
    {
        for(i=0; i<flash_count; i++)
        {
            ws2812b_write(rgb_user_define);
            ws2812b_write(rgb_user_define);
		
            delay_1ms(time);
        
            ws2812b_write(rgb_off);
            ws2812b_write(rgb_off);
            delay_1ms(time);
        }//end of for(i=0; i<flash_count; i++)
    }//end of else
}
