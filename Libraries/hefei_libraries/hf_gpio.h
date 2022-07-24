/*********************************************************************************************************************
* @file            hf_gpio.h
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_GPIO_H
#define _HF_GPIO_H

#include "headfile.h"

/* 枚举声明 */

typedef enum    //枚举GPIO配置
{
    IN_AIN = 0,            //模拟输入模式
    IN_FLOATING = 1,       //浮空输入模式
    IN_PULLDOWN = 2,       //下拉输入
    IN_PULLUP = 3,         //上拉输入

    OUT_PP = 4,            //通用推挽输出模式
    OUT_OD = 5,            //通用开漏输出模式

    OUT_AF_0_PP = 6,       //复用功能推挽输出模式，复用功能0
    OUT_AF_0_OD = 7,       //复用功能开漏输出模式，复用功能0
    OUT_AF_1_PP = 8,       //复用功能推挽输出模式，复用功能1
    OUT_AF_1_OD = 9,       //复用功能开漏输出模式，复用功能1
    OUT_AF_2_PP = 10,      //复用功能推挽输出模式，复用功能2
    OUT_AF_2_OD = 11,      //复用功能开漏输出模式，复用功能2
    OUT_AF_3_PP = 12,      //复用功能推挽输出模式，复用功能3
    OUT_AF_3_OD = 13,      //复用功能开漏输出模式，复用功能3
    OUT_AF_4_PP = 14,      //复用功能推挽输出模式，复用功能4
    OUT_AF_4_OD = 15,      //复用功能开漏输出模式，复用功能4
    OUT_AF_5_PP = 16,      //复用功能推挽输出模式，复用功能5
    OUT_AF_5_OD = 17,      //复用功能开漏输出模式，复用功能5
    OUT_AF_6_PP = 18,      //复用功能推挽输出模式，复用功能6
    OUT_AF_6_OD = 19,      //复用功能开漏输出模式，复用功能6
    OUT_AF_7_PP = 20,      //复用功能推挽输出模式，复用功能7
    OUT_AF_7_OD = 21       //复用功能开漏输出模式，复用功能7

}GPIOMODE_enum;


/* 函数声明 */

/* GPIO初始化 */
void gpio_init(uint32_t gpio_periph, GPIOMODE_enum mode, uint32_t gpio_pin);
/* GPIO引脚输出设置 */
void gpio_bit_output(uint32_t gpio_periph, uint32_t gpio_pin, uint8_t dat);
/* GPIO引脚输出翻转 */
void gpio_toggle(uint32_t gpio_periph, uint32_t gpio_pin);
/* GPIO获取引脚输入 */
uint8_t gpio_get_input(uint32_t gpio_periph,uint32_t gpio_pin);
/* GPIO获取引脚输出 */
uint8_t gpio_get_output(uint32_t gpio_periph,uint32_t gpio_pin);

#endif
