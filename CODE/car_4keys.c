/*********************************************************************************************************************
* @file            car_4keys.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#include "car_4keys.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        按键初始化   
// @param        key_num            选择按键：Kx(x = 1, 2, 3, 4)
// @return       void
// Sample usage:       key_init(K1);//按键K1初始化
//-------------------------------------------------------------------------------------------------------------------
void key_init(unsigned char key_num)
{   
  	if(key_num == K1)
    {
        gpio_init(K1_PORT, K1_MODE, K1_PIN); 
    }
  	if(key_num == K2)
    {
        gpio_init(K2_PORT, K2_MODE, K2_PIN);
    }
  	if(key_num == K3)
    {    
        gpio_init(K3_PORT, K3_MODE, K3_PIN);
    }
  	if(key_num == K4)
    {
        gpio_init(K4_PORT, K4_MODE, K4_PIN);    
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        检测键值   
// @param        key_num            选择按键：Kx(x = 1, 2, 3, 4)
// @return       key_value
// Sample usage:       key_check(K1);//检测K1键值
//-------------------------------------------------------------------------------------------------------------------
unsigned char key_check(void)
{
    unsigned char key_value;

    if(KEYDOWN == gpio_get_input(K1_PORT, K1_PIN))
    {
        key_value = 0x01;
		
		while(KEYUP != gpio_get_input(K1_PORT, K1_PIN))
        {
            ;    
        }
    }        
    else if(KEYDOWN == gpio_get_input(K2_PORT, K2_PIN))				
    {
        key_value = 0x02;
		
		while(KEYUP != gpio_get_input(K2_PORT, K2_PIN))
        {
            ;    
        }
    }					
    else if(KEYDOWN== gpio_get_input(K3_PORT, K3_PIN))
    {
        key_value = 0x03;
		
		while(KEYUP != gpio_get_input(K3_PORT, K3_PIN))
        {
            ;    
        }
    }
    else if(KEYDOWN == gpio_get_input(K4_PORT, K4_PIN))
    {
        key_value = 0x04;
		
		while(KEYUP != gpio_get_input(K4_PORT, K4_PIN))
        {
            ;    
        }  
    }
    else
    {
        key_value = 0xFF;
    }

    return key_value;
}
