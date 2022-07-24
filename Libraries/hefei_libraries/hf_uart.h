/*********************************************************************************************************************
* @file            hf_uart.c
* @author          Davis Klay HF
* @Target core     GD32E230C8T6
* @revisions       -2021.10.7, V1.0
* @modify          none
********************************************************************************************************************/

#ifndef _HF_UART_H
#define _HF_UART_H

#include "headfile.h"
#include "gd32e23x_usart.h"

/* 函数定义 */

/* 串口初始化 */
void uart_init(uint32_t gpio_tx_periph, uint32_t tx_pin, uint32_t gpio_rx_periph, uint32_t rx_pin, uint32_t uart_periph, uint32_t baud);
/* 串口发送字节 */
void uart_putchar(uint32_t uart_periph, uint8_t data);
/* 串口发送数组 */
void uart_putbuff(uint32_t uart_periph, uint32_t *buff, uint32_t len);
/* 串口发送字符串 */
void uart_putstr(uint32_t uart_periph, uint8_t *str);
/* 读取串口接收的字节（whlie等待） */
uint8_t uart_getchar(uint32_t uart_periph);
/* 读取串口接收的字符串（whlie等待） */
void uart_getstr(uint32_t uart_periph, uint16_t *dat);
/* 读取串口接收的数据（查询接收） */
uint8_t uart_query(uint32_t uart_periph, uint16_t *dat);
/* 串口中断设置 */
void uart_interrupt_init(uint32_t uart_periph, usart_interrupt_enum int_flag, uint32_t status, uint32_t uart_irq);

#endif