/*********************************************************************************************************************
* @file            board.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
*                  -2021.10.24, V1.1
* @modify          1. 修改了板载LED熄灭函数和板载LED电平翻转函数的注释
*                  2. 删除了板载LED点亮函数中使另一个LED熄灭的函数
********************************************************************************************************************/

#include "board.h"

//-------------------------------------------------------------------------------------------------------------------
// @brief        板载LED初始化   
// @param        led_num            选择LED：LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_init(LED1);//板载LED1初始化
//-------------------------------------------------------------------------------------------------------------------
void board_led_init(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_init(LED1_PORT, LED1_MODE, LED1_PIN);//配置LED1的引脚
        gpio_bit_output(LED1_PORT, LED1_PIN, OFF);//LED1熄灭
    }
    if(led_num == LED2)
    {
        gpio_init(LED2_PORT, LED2_MODE, LED2_PIN);//配置LED2的引脚
        gpio_bit_output(LED2_PORT, LED2_PIN, OFF);//LED2熄灭
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        板载LED点亮   
// @param        led_num            选择LED：LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_on(LED1);//点亮板载LED1
//-------------------------------------------------------------------------------------------------------------------
void board_led_on(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_bit_output(LED1_PORT, LED1_PIN, ON);
    }
    if(led_num == LED2)
    {
        gpio_bit_output(LED2_PORT, LED2_PIN, ON);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        板载LED熄灭
// @param        led_num            选择LED：LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_off(LED1);//板载LED1熄灭
//-------------------------------------------------------------------------------------------------------------------
void board_led_off(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_bit_output(LED1_PORT, LED1_PIN, OFF);
    }
    if(led_num == LED2)
    {
        gpio_bit_output(LED2_PORT, LED2_PIN, OFF);
    }
}

//-------------------------------------------------------------------------------------------------------------------
// @brief        板载LED电平翻转
// @param        led_num            选择LED：LEDx(x = 1.2)
// @return       void
// Sample usage:       board_led_toggle(LED1);//板载LED1电平翻转
//-------------------------------------------------------------------------------------------------------------------
void board_led_toggle(unsigned char led_num)
{
    if(led_num == LED1)
    {
        gpio_toggle(LED1_PORT, LED1_PIN);
    }
    if(led_num == LED2)
    {
        gpio_toggle(LED2_PORT, LED2_PIN);
    }
}
